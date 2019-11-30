#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void delete_ticket(char id[])
{
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen("booking.txt", "r");
	fp2 = fopen("booking1.txt", "w");
	fp3 = fopen("booking2.txt", "a");
	int count = 0, a = 0;
	char c, arr[100], arr1[100];
	arr[0] = 'a'; arr[1] = 'b';
	
	c = fgetc(fp1);
	while(c != EOF)
	{
		if(strncmp(arr, id, strlen(id)) != 0)
		{
			if(c != ' ' && c != '\n')
			{
				arr[count] = c;
				count++;
			}

			else if(c == ' ')
			{
				arr[count] = '\0';
		
				if(strncmp(arr, id, strlen(id)) != 0)
				{
					fprintf(fp2, "%s%c", arr, c);
					count = 0;
				}
			}

			else if(c == '\n')
			{
					
				arr[count] = '\0';
				fprintf(fp2, "%s%c", arr, c);
				count = 0;
			}
			c = fgetc(fp1);
		}

		if(strncmp(arr, id, strlen(id)) == 0)
		{
			a++;
			if(c != ' ' && c != '\n') 
			{
				arr1[count] = c;
				count++;
			}

			else if(c == ' ' && a == 1)
			{	
				fprintf(fp3, "%s%c", id, c);
				count = 0;
			}

			else if(c == ' ' && a != 1)
			{
				arr1[count] = '\0';
				fprintf(fp3, "%s%c", arr1, c);
				count = 0;
			}

			else if(c == '\n')
			{
				arr1[count] = '\0';
				fprintf(fp3, "%s%c", arr1, c);
				for(int i = 0; i < 9; i++)
					arr[i] = '\0';
				count = 0;
			}
			c = fgetc(fp1);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	system("rm booking.txt");
	system("mv booking1.txt booking.txt");
}

void delete(char arr[])
{
	delete_ticket(arr);
}
