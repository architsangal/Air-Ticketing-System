#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* flight_search(char *book_id)
{
	FILE *fp = fopen(book_id, "r");
	char arr[10000], c;
	char* arr1 =malloc(10000);
	c=fgetc(fp);
	int count=0,seat;
	while(c != EOF)
	{
		if(c == ':')
			count++;
		if(count == 19)
		{
			for(int i=0;i<10;i++)
			{
				arr1[i]=fgetc(fp);
			}
			arr1[10]='\0';
			c=fgetc(fp);
			count++;
		}
		else if(count == 22)
		{
			fscanf(fp,"%d",&seat);
		}
		c=fgetc(fp);
	}
	fclose(fp);
	fp = fopen(arr1,"r");
	c=fgetc(fp);
	int test;
	FILE *fp2 = fopen("testing","w");
	while(c != EOF)
	{
		fscanf(fp,"%d",&test);
		if(test != seat)
		{
			fprintf(fp2," %d",test);
		}
		c=fgetc(fp);
	}
	fclose(fp2);char path[1000];
	path[0]='r';
	path[1]='m';
	path[2]=' ';
	path[3]='\0';
	strcat(path,arr1);
	system(path);
	char path1[10000] = "mv testing ";
	strcat(path1,arr1);
	system(path1);
}