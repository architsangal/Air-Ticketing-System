#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

long long int Booking_ID(void) 
  { 
    
    srand(time(0));
    long long int BookingId;
    BookingId=rand()%100000000+1; 
    system("sleep 1");
    return BookingId; 
}
char *Add_zero(void)
{
	char *book=(char*)malloc(9);
	char *arr3=(char*)malloc(8);
	sprintf(book,"%lld",Booking_ID());
	int len = strlen(book);

	if(len!=8)
	{
		
		for(int y=0;y<8-len;y++)
		{
			arr3[y]='0';
		}
		for(int k=8-len,m=0;k<8,m<len;k++,m++)
		{
			arr3[k] = book[m];
		}
			return arr3;

	}
	else
		return book;
}



char* data_base(char from[],char to[],char date[],char flight_name[],char time[],char landing[],int seat,char class[],int age,char gender[],char name[])
{	
	FILE *fp;
	
	fp = fopen("booking.txt","a");
	char *temp=Add_zero();
	fprintf(fp,"%s %s %s %s %s %s %s ",temp, from, to, date, flight_name, time, landing);
	fprintf(fp,"%d %s %d %s %s\n", seat, class, age, gender, name);
	fclose(fp);
	return temp;
}

void make_copy(char *name)
{
	FILE *fp, *fp1;
	fp = fopen("booking.txt", "r");
	fp1 = fopen(name, "a");
	char c;
	c = fgetc(fp);
	while(c != EOF)
	{
		fputc(c, fp1);
		c = fgetc(fp);
	}

	fclose(fp);
	fclose(fp1); 
}


char* booking(char from[],char to[],char date[],char flight_name[],char time[],char landing[],int seat,char class[],int age,char gender[],char name[])
{
	char* id = (char* )data_base(from,to,date,flight_name,time,landing,seat,class,age,gender,name);
	return id;
}

