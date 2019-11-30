#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void admin_login()
{
    system("clear");
    start:
        for(int i=0;i<6;i++)
            printf("\n");
        char path[2000]="Admin";
        int length_path=strlen(path);

        path[length_path]='\0';

        FILE *ptr;
        ptr=fopen(path,"r");
        if(ptr == NULL)
        {
            printf("1");
            system("sleep 5");
        }
        printf("\n\t\t\tEnter Password: ");
        char password[1000];
        scanf("%s",password);
        char already_password[1000];
        int j=0;
        char ch=fgetc(ptr);
        while(ch!=EOF)
        {
            already_password[j]=ch;
            ch=fgetc(ptr);
            j++;
        }
        already_password[j-1]='\0';
        if(strcmp(already_password,password)==0)
        {
            system("clear");
            printf("\n\n\n\n\n\n\t\t\t\tWELCOME TO IIITB AIRLINES\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("sleep 5");
        }
        else
        {
            system("clear");
            printf("\n\t\t\tInvalid Password TRY AGAIN...");
            goto start;                
        }
}