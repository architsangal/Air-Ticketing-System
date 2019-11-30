#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct flight
{
char flight_num[100] ;
char flight_name[100] ;
char start[100] ;
char end[100] ;
char departure[100]  ;   // it will be like 0000 , 0015 ... in HHMM format
char landing[100] ;      //HHMM format
char travel_time[100] ;  // in minutes
char seats[100] ;        // total seats left
char price[100] ;
};
void add_flight()
{
  FILE *fp;
  fp = fopen("data.txt","a");
  struct flight f;
  system("clear");
  printf("\n\n\n\t\t\t\"C\" Is For Capital Letter\n\t\t\t\"s\" Is For Small Letters\n\t\t\t\"d\" Is For Digit\n\t\t\t");
  printf("Enter the number of the Flight (CCCssssddd) : ");
  scanf("%s",f.flight_num);
  fprintf(fp,"%s",f.flight_num);
  printf("\n\t\t\tEnter the Flight company name (CCC): ");
  scanf("%s",f.flight_name);
  fprintf(fp," %s",f.flight_name);
  printf("\n\t\t\tTake off destination (Css) : ");
  scanf("%s",f.start);
  fprintf(fp," %s",f.start);
  printf("\n\t\t\tLanding destination (Css) : ");
  scanf("%s",f.end);
  fprintf(fp," %s",f.end);
  printf("\n\t\t\tTime of departure in (dddd) or (HHMM): ");
  scanf("%s",f.departure);
  fprintf(fp," %4s",f.departure);
  printf("\n\t\t\tTime of landing in (dddd) or (HHMM): ");
  scanf("%s",f.landing);
  fprintf(fp," %4s",f.landing);
  printf("\n\t\t\tTravel time in min (ddd) : ");
  scanf(" %s",f.travel_time);
  fprintf(fp," %3s",f.travel_time);
  printf("\n\t\t\tNo of seats (dd) : ");
  scanf("%s",f.seats);
  fprintf(fp,"%3s",f.seats);
  printf("\n\t\t\tPrice of ticket (dddd) : ");
  scanf("%s",f.price);
  fprintf(fp," %s\n",f.price);
  fclose(fp);

  system("clear");
  printf("\n\n\n\t\t\tFlight has been added successfully.\n\n\n\n\n\n\n\n\n\n\n");
  fclose(fopen(f.flight_num,"w"));
}
void Delete_line(int i)
{
  int ctr=0; // maintain a check on which line we are at a present moment
  FILE *fptr1,*fptr2;
  fptr1 = fopen("data.txt", "r");
  char str[250], temp[] = "temp.txt";
  fptr2 = fopen(temp, "w");
  while (!feof(fptr1))
  {
      strcpy(str, "\0");
      fgets(str, 250, fptr1);
      if (!feof(fptr1))
      {
          ctr++;
          /* skip the line at given line number */
          if (ctr != i)
          {
              fprintf(fptr2, "%s", str);
          }
      }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove("data.txt");          // remove the original file
  rename(temp, "data.txt");
}
int line(char *p)
{
    char row[70],name[100] ;
    int i = 0 ;
    FILE * fp = fopen( "data.txt" , "r" ) ;
    for(int k=0;k<20;k++)
      name[k]=*(p+k);
    //printf("%s\n",name);
    struct flight data_set[100];
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
        //printf("%s ",data_set[i].flight_num);
        if(strcmp(data_set[i].flight_num,name) == 0)
          return i+1;
        i++;
     }
return -1;
}
void admin_work()
{
  int i,option;
  system("clear");
  printf("\n\t\t\t1.Add a flight\n\t\t\t2.Delete a flight\n\t\t\tEnter Your Choice : ");
  scanf("%d",&option);
  if(option==1)
  {
  add_flight();
  }
  else if(option==2)
  {
  struct flight f;
  FILE *fp;
  int i;
  fp = fopen("data.txt","r");
  system("clear");
  printf("\n\t\t\tEnter the number of the Flight(CCCssssddd): ");
  scanf("%s",f.flight_num);
  i = line(f.flight_num);
  printf("\n%d\n",i);
  if(i>=0)
    {
      Delete_line(i);
      system("clear");
      printf("\n\t\t\tFlight deleted successfully\n\n\n\n\n\n\n\n\n\n\n");
    }
  }
}
