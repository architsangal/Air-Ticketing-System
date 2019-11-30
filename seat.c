#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 1000
int fsize(FILE *fp)
{
    long size,current;
    current = ftell(fp); 
    if (fp)
      {
          fseek (fp, 0, SEEK_END);
          size = ftell(fp);
          fseek(fp,current,SEEK_CUR);
      }
  return size;

}
int comparefiles(FILE *fp1,FILE *fp2,int n)
{
  
  if(fsize(fp2)==0)
    return 0;
  else
  {
  int i,r=0;
  //fscanf(fp1,"%d",&i);
  i=n;
  fseek(fp2,0,SEEK_SET);
  char ch = fgetc(fp2);
  while (ch != EOF)
    {
      fscanf (fp2, "%d", &n);
      if(i==n)
        r++;
      ch = fgetc(fp2);
    }
  fclose(fp1);
  fclose(fp2);
  return r;
  }
}
int seat_no(char* flight)
{
  start:
      system("clear");
      int i,n;
      printf("\n\n\n");
      int arr[60];
      for(i=0;i<60;i++)
      arr[i]=i+1;
      FILE *fp2;
      fp2 = fopen(flight,"r");
      int k;
      char ch=fgetc(fp2);
      if(fsize(fp2) != 0)
      {
          fseek(fp2,1,SEEK_SET);
          while(ch != EOF)
          {
              fscanf(fp2,"%d",&k);
              arr[k-1]=0;
              ch = fgetc(fp2);
          }
      }
      for(i=0;i<58;i=i+4)
      {
          if(arr[i] == 0)
              printf("\t\t\t W [---]");
          else
              printf("\t\t\t W [%3d]",arr[i]);
          if(arr[i+1] == 0)
              printf("   [---]");
          else
              printf("   [%3d]",arr[i+1]);
          if(arr[i+2] == 0)
              printf("      [---]");
          else
              printf("      [%3d]",arr[i+2]);
          if(arr[i+3] == 0)
              printf("   [---] W\n");
          else
              printf("   [%3d] W\n",arr[i+3]);
      }
      printf("\t\t\tSelect a nonzero seat number :");
      scanf("%d",&n);
      if(n<=60&&n>0)
      {
          FILE *fptr,*fp;
          fptr = fopen("test.txt", "w");
          if(fptr == NULL)
          {
               printf("error");
               exit(1);
          }
          fprintf(fptr,"%d", n);
          fclose(fptr);
          fptr = fopen("test.txt", "r");
          fp = fopen(flight,"r");
          if(comparefiles(fptr,fp,n))
          {
                printf("\t\t\tSeat occupied");
                goto start;
          }
          else
          {
                fclose(fp);
                fp = fopen(flight,"a");
                fprintf(fp," %d",n);
          }
          fclose(fp);
      }
      else
      {
           printf("\n\n\n\t\t\tInvalid seat number");
           goto start;
      }
      //printf("\t\t\t1.Book another ticket\n\t\t\t2.Exit\n\t\t\t");
      //scanf("%d",&out);
      //if(out==1)
      // goto start;
           return n;
}
/*int main(void)
{
      char *flight = (char*)(malloc(1000));
      flight = "123.txt";
      printf("%d",seat_no(flight));
}*/
