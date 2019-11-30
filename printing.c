#include<stdio.h>
#include<string.h>
int copy_to_text_file(char* filename,char name[],char date[],char time[],char from[],char to[],char class[],int seat,char flight[],char destination[])
{
	FILE *fp;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
	  return 0;
	}
	else
	{
		fprintf(fp," \t _________________________________________________________________________________________________________\n\t");
		fprintf(fp,"|             AIR TICKET                                               :     BOARDING PASS                |\n\t");
		fprintf(fp,"|______________________________________________________________________:__________________________________|\n\t");
		fprintf(fp,"|Name of passenger: %.13s",name);
		int length=strlen(name);
    int i;
    for(i=0;i<13-length;i++)
			fprintf(fp," ");
		fprintf(fp,"      DATE:%s",date);
                fprintf(fp,"      TIME:%s  ",time);
                if(strlen(name)>=13)
                  {fprintf(fp,":NAME:%.13s                |\n\t",name);}
                else 
                  {
                      fprintf(fp,":NAME:%s",name);
                      for(int i=0;i<29-strlen(name);i++)
                      {fprintf(fp," ");}
                       fprintf(fp,"|\n\t");
                   }
                fprintf(fp,"|");
                for(int i=0;i<70;i++)
                     {fprintf(fp," ");}
                if(strlen(from)>=20)
                   {fprintf(fp,":FROM:%.20s         |\n\t",from);}
                else
                  {fprintf(fp,":FROM:%s",from);
                    for(int i=0;i<29-strlen(from);i++)
                      {fprintf(fp," ");}
                        fprintf(fp,"|\n\t");}
                 fprintf(fp,"|Class:%.8s       ",class);
                    for(int i=0;i<8-strlen(class);i++)
                           fprintf(fp," ");
                     /*for(int i=0;i<23;i++)
                           {fprintf(fp," ");}
                      fprintf(fp,"GATE:%.2s",gate);
                     for(int i=0;i<2-strlen(gate);i++)
                         {fprintf(fp," ");}
                     */fprintf(fp,"              SEAT:%d",seat);
                     // for(int i=0;i<2-strlen(seat);i++)
                      if(seat<10)
                          {fprintf(fp," ");}
                      for(int i=0;i<23;i++)
                        fprintf(fp," ");
                      
                      fprintf(fp,"     :");
                    if(strlen(to)>=20)
                     {fprintf(fp,"TO:%.20s           |\n\t",to);}
                     else
                      {fprintf(fp,"TO:%s",to);
                        for(int i=0;i<31-strlen(to);i++)
                          {fprintf(fp," ");}
                             fprintf(fp,"|\n\t");}
                     fprintf(fp,"|");
                     fprintf(fp,"Booking ID : %s",filename);
                     for(int i=0;i<49;i++)
                       {fprintf(fp," ");}
                     fprintf(fp,":DATE:%s     TIME:%s     |\n\t",date,time);
                     fprintf(fp,"|From:%.20s",from);
                     for(int i=0;i<20-strlen(from);i++)
                        {fprintf(fp," ");}
                     fprintf(fp,"            FLIGHT:%.20s                ",flight);
                     /*if(strlen(gate)>=2)
                      {
                         fprintf(fp,":GATE:%.2s                           |\n\t",gate);}
                      else
                          {fprintf(fp,":GATE:%s                            |\n\t",gate);}
                      */
                      if(seat>=10)
                         {fprintf(fp,":SEAT:%d                           |\n\t",seat);}
                       else
                          {fprintf(fp,":SEAT:%d                            |\n\t",seat);}
                       fprintf(fp,"|Destination:%.20s",destination);
                       for(int i=0;i<52;i++)
                        {fprintf(fp," ");}
                       if(strlen(flight)>=19)
                        {fprintf(fp,":FLIGHT:%.19s|\n\t",flight);}
                       else
                        {fprintf(fp,"   :FLIGHT:%s",flight);
                         for(int i=0;i<27-strlen(flight);i++)
                          {fprintf(fp," ");}
                         fprintf(fp,"|\n\t");}
                       fprintf(fp,"|");
                        for(int i=0;i<105;i++)
                          {fprintf(fp," ");}
                        fprintf(fp,"|\n\t");
                         fprintf(fp,"|");
                       for(int i=0;i<105;i++)
                         {fprintf(fp,"_");}
                        fprintf(fp,"|\n");

	}
	fclose(fp);
	return 0;
}
int print_the_text_file(char* filename)
{
	char c;
	FILE *fptr;
	fptr=fopen(filename,"r");
	if(fptr==NULL)
{
		printf("unable to open the file");
		return 0;
}
	else
	{
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(fptr);
		}
	}
	fclose(fptr);
	return 0;
}


int print(char* filename,char name[],char date[],char time[],char from[],char to[],char class[],int seat,char flight[],char destination[])
{
	copy_to_text_file(filename,name,date,time,from,to,class,seat,flight,destination);
        print_the_text_file(filename);
	return 0;
}



























