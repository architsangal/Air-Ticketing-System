#include<stdio.h>
#include<string.h>

int check_id(char *name, char *file)
{
	FILE *fp;
	fp = fopen(file, "r");
	char arr[100];
	int result = 1;

	while(!feof(fp))
	{
		fscanf(fp, "%s", arr);
		if(strcmp(arr, name) == 0)
		{		
			result = 0;
			break;
		} 
	}
	fclose(fp);
	return result;
}

int checkDeleted(char arr[])
{
	return check_id(arr, "booking2.txt");	
}