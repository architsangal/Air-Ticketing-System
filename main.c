#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_login.h"
#include "admin_login.h"
#include "seat.h"
#include "CP.h"
#include "booking_copy.h"
#include "printing.h"
#include "c_project.h"
#include "c_pro1.h"
#include "flights.h"
#include "c.h"
int main(void)
{
    
    system("clear");
    printf("\n\n\n\n\n\t\t\tENTER 1 OR 2");
    printf("\n\t\t\t1) USER");
    printf("\n\t\t\t2) ADMIN");
    printf("\n\t\t\tEnter your choice: ");
    int login;
    scanf("%d",&login);
    char* user = (char*)malloc(1000);
    user = "Admin";
    if(login == 1)
    {
        int option;
        user=user_login();
        
        starting:
        system("clear");
        printf("\n\n\n\n\n\t\t\t1 Book A New Ticket\n");
        printf("\t\t\t2 Cancelling An Existing Ticket\n");
        printf("\t\t\t3 Print An Existing Ticket\n\n");
        printf("\t\t\tEnter the desired option : ");
        scanf("%d",&option);
        if(option == 1)
        {
            system("clear");
            char name[1000];
            printf("\n\t\t\tEnter Name Of Passanger (Without Spaces): ");
            scanf("%s",name);

            system("clear");
            
            printf("\n\t\tSelect Your Flight\n");
            printf("\n\t\tKeep Following Rules In Mind :- \n");
            printf("\t\t1) Filters Are Case Sensitive.\n");
            printf("\t\t2) To Skip A Filter Enter. \"*\" \n ");
            printf("\t\t3) Once A Filter Is Skiped It Can NOT Be Applied Again.\n");
            printf("\t\t4) Enter Exactly The Same Data As Given In the Table Above For Each Input.\n");
            printf("\t\t5) If You Skip Filters And More Than 1 Flight Is Left At The End Of Filter Process Then First One Is Taken.\n");

            struct data flights = flight();
            
            char flight[11];
            strcpy(flight,flights.flight_num);
            
            char from[10];
            strcpy(from,flights.start);
            
            char to[10];
            strcpy(to,flights.end);

            system("clear");
            char date[11];
            printf("\n\n\t\t\tEnter Date Of Travelling : ");
            scanf("%s",date);
            
            char time[10];
            strcpy(time,flights.departure);
        
            char landing[10];
            strcpy(landing,flights.landing);
            
            char class[20];
            printf("\n\t\t\tEnter 1 for Business class\n");
            printf("\t\t\tEnter 2 for First class\n");
            printf("\t\t\tEnter 3 for Economy class\n\n\t\t\tEnter Your Choice: ");
            int input;
            scanf("%d", &input);
            
            if(input == 1)
                strcpy(class,"Business");
            else if(input == 2)
                strcpy(class,"First");
            else
                strcpy(class,"Economy");
            
            char gender[4];
            printf("\n\t\t\tEnter M for Male and F for Female\n\t\t\tEnter Info : ");
            scanf("%s",gender);
            
            int age;
            printf("\n\n\t\t\tEnter age : ");
            scanf("%d",&age);
            
            int seat=seat_no(flight);
            
            char* id = (char* )booking(from,to,date,flight,time,landing,seat,class,age,gender,name);
            
            system("clear");
            printf("\n\n\n\t\t\tREDIRECTING TO PAYMENT GATEWAY............");
            system("sleep 2");
            system("clear");
            printf("\n\n\n\t\t\tPAYMENT DONE :) ");
            system("sleep 2");
            
            system("clear");
            printf("\n\n\n");
            print(id,name,date,time,from,to,class,seat,flight,to);
            
            // printf("\n\nEnter \"*\" And Press \"Enter\" To End ..................................................");
            // printf("\n\nEnter \".\" And Press \"Enter\" To Go Back To Main Menu .................................");
            
            // char something[10];
            // scanf("%s",something);
            
            // if(something[0] == '.')
            //     goto starting;
        }
        else if(option == 2)
        {
            system("clear");
            printf("\n\t\t\tEnter Booking ID Of Ticket To Be Deleted : ");
            char deleting[10];
            scanf("%s",deleting);
            system("clear");
            if(checkDeleted(deleting))
            {
                delete(deleting);
            	flight_search(deleting);
                printf("\t\t\tTicket Deleted");
            }
            else
            {
                printf("\t\t\tTicket Already Deleted...\n\n\n\n\n");
            }
            system("sleep 3");
        }
        else
        {
            system("clear");
            printf("\n\t\t\tEnter Booking ID Of Ticket To Be Printed : ");
            char deleting[10];
            scanf("%s",deleting);
            system("clear");
            printf("\n\n\n");
            print_the_text_file(deleting);
            //printf("\n\nEnter \"*\" And Press \"Enter\" To End ..................................................");
            //printf("\n\nEnter \".\" And Press \"Enter\" To Go Back To Main Menu .................................");
        }
    }
    else if(login == 2)
    {
        admin_login();
        admin_work();
    }
    printf("\n\n\n\n\n\n\n");
    //system("make clean");
    //system("clear");
    return 0;
}
