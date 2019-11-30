#include <stdio.h>
#define row_MAX = 70
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct data
    {
        char flight_num[100] ;
        char flight_name[100] ;
        char start[100] ;
        char end[100] ;
        char departure[6]  ;   // it will be like 0000,0015... in HHMM format
        char landing[6] ;      //HHMM format
        char travel_time[6] ;  // in minutes
        char seats[6] ;        // total seats left
        char price[6] ;

    }   data_set[100] ;         // currently taking max 10


////////////////////

void get_data(struct data data_set[], char file_name[]) //

 /* purpose of this function is to take data from "data.txt" file
 *and store it in -struct- 'data'
 */

{
  char row[70] ;
  int i = 0 ;

  FILE * fp ;
  fp = fopen(file_name , "r" ) ;

  while(fgets(row,70,fp) != NULL)
    {
      sscanf   (row ,"%s %s %s %s %s %s %s %s %s",
      &data_set[i].flight_num[0] ,
      &data_set[i].flight_name[0] ,
      &data_set[i].start[0] ,
      &data_set[i].end[0] ,
      &data_set[i].departure[0] ,
      &data_set[i].landing[0] ,
      &data_set[i].travel_time[0] ,
      &data_set[i].seats[0] ,
      &data_set[i].price[0]) ;
      i++ ;
    }

  fclose(fp) ;
}

/////////////////////

void print_data(struct data data_set[] )  // print data of a -struct- define on terminal
    {
        for(int j=0 ; j<=10 ; j++)
        {
            printf("%s " , data_set[j].flight_num     ) ;
            printf("%s " , data_set[j].flight_name    ) ;
            printf("%s " , data_set[j].start          ) ;
            printf("%s " , data_set[j].end            ) ;
            printf("%s " , data_set[j].departure      ) ;
            printf("%s " , data_set[j].landing        ) ;
            printf("%s " , data_set[j].travel_time    ) ;
            printf("%s " , data_set[j].seats          ) ;
            printf("%s\n" , data_set[j].price      ) ;
        }
    }

//////////////////////

void fprint_sort(int j)

{

  /*
   *  this function is used to save data in file "sort.txt"
   *  it open's the file in append mode
   *  and save the data row of "j" thingy in file "sort.txt"
   */



  FILE * fp ;
  fp = fopen("sort.txt" , "a" ) ;
  fprintf(fp ,"%s " , data_set[j].flight_num     ) ;
  fprintf(fp ,"%s " , data_set[j].flight_name    ) ;
  fprintf(fp ,"%s " , data_set[j].start          ) ;
  fprintf(fp ,"%s " , data_set[j].end            ) ;
  fprintf(fp ,"%s " , data_set[j].departure      ) ;
  fprintf(fp ,"%s " , data_set[j].landing        ) ;
  fprintf(fp ,"%s " , data_set[j].travel_time    ) ;
  fprintf(fp ,"%s " , data_set[j].seats          ) ;
  fprintf(fp ,"%s\n" , data_set[j].price      ) ;
  fclose(fp) ;

}

/////////////////////

void sorting1(struct data data_set[] , char start[])
    {
        if(strcmp(start,"*") == 0)
            {
              for(int j=0 ; j<=1 ; j++)
              {
                fprint_sort(j) ;
              }
            }

        else
            {
            for(int j=0 ; j<=10 ; j++)
                {
                if( strcmp(data_set[j].start,start) == 0 )
                fprint_sort(j) ;
                }

            }

    }

//////////////////

void sorting2(struct data data_set[]  , char end[] )
{
        if(strcmp(end,"*") == 0)
            {
            for(int j=0 ; j<=1 ; j++)
              {
                fprint_sort(j) ;
              }
            }

        else
            {
            for(int j=0 ; j<=10 ; j++)
                {
                if( strcmp(data_set[j].end,end) == 0 )
                fprint_sort(j) ;
                }

            }

}


///////////////////



void sorting3(struct data data_set[] , char start_time[] )
{

        if(strcmp(start_time , "*" )==0)
            {
            for(int j=0 ; j<=1 ; j++)
              {
                fprint_sort(j) ;
              }
            }

        else
            {
            for(int j=0 ; j<=10 ; j++)
                {
                if( strcmp(data_set[j].departure,start_time) == 0 )
                fprint_sort(j) ;
                }

            }

}
///////////////////////
void sorting4(struct data data_set[] , char end_time[] )
{

        if(strcmp(end_time , "*" )==0)
            {
            for(int j=0 ; j<=1 ; j++)
              {
                fprint_sort(j) ;
              }
            }

        else
            {
            for(int j=0 ; j<=10 ; j++)
                {
                if( strcmp(data_set[j].landing,end_time) == 0 )
                fprint_sort(j) ;
                }

            }

}
///////////////////////
void sorting5(struct data data_set[] , char price[] )
{

        if(strcmp(price , "*" )==0)
            {
            for(int j=0 ; j<=1 ; j++)
              {
                fprint_sort(j) ;
              }
            }

        else
            {
            for(int j=0 ; j<=10 ; j++)
                {
                if( strcmp(data_set[j].price,price) == 0 )
                fprint_sort(j) ;
                }

            }

}
///////////////////////
char * final_sort(struct data data_set[])
{
printf("%s\n", data_set[0].flight_num) ;
return data_set[0].flight_num ;
}


//////////////////////
void print_sort() {

FILE * fp ;
fp = fopen( "sort.txt" , "r" ) ;
char row[80];
while(fgets(row,80,fp) != NULL)
{
  printf("\t%s",row);
}
fclose(fp) ;

}
////////////////////////
void print_data1() {

FILE * fp ;
fp = fopen( "data.txt" , "r" ) ;
char row[80];
while(fgets(row,80,fp) != NULL)
{
  printf("\t%s",row);
}
fclose(fp) ;

}


//////////////////////


struct data flight() {

FILE * fp ;
fp = fopen("sort.txt" , "w" ) ;
printf("\n\n");
print_data1();

// need these variables in main function
char start[100]  = "*" ;
char end[100]    = "*" ;
char start_time[6] = "*" ;
char end_time[6]   = "*" ;
char price[6]      = "*" ;
//////////////////////////

get_data(data_set,"data.txt") ;    // gets data from data.txt to data_set structure
printf("\n") ;
printf("\n") ;

// asking user for start destination
printf("\n\t\t\tFROM : ") ;         // giving user promt for "start"
scanf( "%s" , start ) ;     // getting start destination
sorting1( data_set , start );   // sort data and store in sort.txt
system("clear");
printf("\n") ;
printf("\n") ;
print_sort() ;              // printing sort function

memset(data_set, 0, sizeof(data_set));  // clearing data_set
get_data(data_set, "sort.txt");         // allocating new data to data_set
fclose(fp);
fp = fopen("sort.txt" , "w" )  ;       // reopening file
printf("\n\t\t\tTO : ") ;                      // giving user promt for "end"
scanf("%s" , end ) ;                   // getting end destination
sorting2( data_set , end ) ;            // sort
system("clear");
printf("\n") ;
printf("\n") ;
print_sort() ;                         //print sort.txt

memset(data_set, 0, sizeof(data_set));  // clearing data_set
get_data(data_set, "sort.txt");         // allocating new data to data_set
fclose(fp) ;

fp = fopen("sort.txt","w") ;
printf("\n\t\t\tDeparture : ") ;
scanf("%s",start_time) ;
sorting3( data_set,start_time ) ;
system("clear");
printf("\n");
printf("\n");
print_sort() ;

memset(data_set, 0, sizeof(data_set));  // clearing data_set
get_data(data_set, "sort.txt");         // allocating new data to data_set
fclose(fp) ;

fp = fopen("sort.txt","w") ;
printf("\n\t\t\tLanding : ") ;
scanf("%s",end_time) ;
sorting4( data_set,end_time ) ;
system("clear");
printf("\n") ;
printf("\n");
print_sort() ;

memset(data_set, 0, sizeof(data_set));  // clearing data_set
get_data(data_set, "sort.txt");         // allocating new data to data_set
fclose(fp) ;

fp = fopen("sort.txt","w") ;
printf("\n\t\t\tPrice : ") ;
scanf("%s",price) ;
sorting5( data_set,price ) ;
system("clear");
printf("\n") ;
printf("\n");
print_sort() ;

memset(data_set, 0, sizeof(data_set));  // clearing data_set
get_data(data_set, "sort.txt");         // allocating new data to data_set
fclose(fp) ;

//final_sort(data_set);
return data_set[0];

}