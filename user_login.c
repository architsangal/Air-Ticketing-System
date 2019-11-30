#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*void copy_to_pointer(char user[],char* use)
{
    for(int i=0;i<strlen(user);i++)
    {
        use[i]=user[i];
    }
}*/
char* user_login(void)
{
    system("clear");
    start:
    for(int i=0;i<6;i++)
        printf("\n");

    printf("\t\t\t IF YOU ARE A NEW USER SIGN UP OTHERWISE LOGIN\n");
    printf("\t\t\t Enter 1 for LOGIN\n");
    printf("\t\t\t Enter 2 for SIGN UP\n\n");
    
    printf("\t\t\t\t Enter the desired option: ");
    int c;
    scanf("%d",&c);

    system("clear");
    for(int i=0;i<6;i++)
    printf("\n");
    char* user = (char*) malloc(1000);
    if(c==1)
    {

        printf("\n\t\t\t Enter Username: ");
        scanf("%s",user);

        char path[2000]={""};
        int length_path=strlen(path);

        int i;
        for(i=0;i<strlen(user);i++)
        {
            path[length_path+i]=user[i];
        }
        path[length_path+i]='\0';

        FILE *ptr;
        ptr=fopen(path,"r");
        if(ptr==NULL)
        {
            system("clear");
            printf("\n\t\t\tInvalid User Name TRY AGAIN...");
            goto start;
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
        already_password[j]='\0';
        if(strcmp(already_password,password)==0)
            {
                system("clear");
                printf("\n\n\n\n\n\n\t\t\t\tWELCOME TO IIITB AIRLINES\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                system("sleep 5");
                return user;
            }
        else
            {
                system("clear");
                printf("\n\t\t\tInvalid Password TRY AGAIN...");
                goto start;                
            }
        
    }
    else if(c==2)
    {
        printf("\n\t\t\t Enter Username: ");
        scanf("%s",user);

        char path[2000]={""};
        int length_path=strlen(path);

        int i;
        for(i=0;i<strlen(user);i++)
        {
            path[length_path+i]=user[i];
        }
        path[length_path+i]='\0';

        FILE *ptr;
        ptr=fopen(path,"r");
        if(ptr==NULL)
        {
            ptr=fopen(path,"w");
            if(ptr==NULL)
            {
                system("clear");
                printf("\n\n\t\t\tSOMETHING WENT WRONG!!!\n\n\nTRY AGAIN!!!");
                goto start;
            }
            password_again:
            printf("\n\n\t\t\tNOTE:\n\n\t\t\t1) PASSWORD should have letters of both case.");
            printf("\n\t\t\t2) It should have a special character out of one of these !@#$%%^&* ");
            printf("\n\t\t\t3) It should not have characters more than 800");
            printf("\n\t\t\t4) It should have atleast one digit");
            printf("\n\n\t\t\t Enter Password: ");
            char password[1000];
            scanf("%s",password);
            int upper=0,lower=0,digit=0,sp_ch=0;
            for(i=0;i<strlen(password);i++)
            {
                if(password[i]>='a' && password[i]<='z')
                    lower=1;
                else if(password[i]>='A' && password[i]<='Z')
                    upper=1;
                else if(password[i]=='!' ||  password[i]=='@' ||  password[i]=='#' ||  password[i]=='$'  ||
                        password[i]=='%' ||  password[i]=='^' ||  password[i]=='&' ||  password[i]=='*')
                    sp_ch=1;
                else if(password[i]>='0' && password[i]<='9')
                    digit=1;
            }
            if(upper==1 && lower==1 && sp_ch==1 && digit==1)
            {
                for(i=0;i<strlen(password);i++)
                {
                    fputc(password[i],ptr);
                }
                system("clear");
                printf("\n\n\t\t\t\tAccount Created.....\n");
                fclose(ptr);
                goto start;
            }
            else
            {
                system("clear");
                printf("\n\n\t\t\t\tInvalid Password\n\t\t\tPassword MUST satisfy the given conditions");
                goto password_again;
            }
            
        }
        else
        {
            system("clear");
            printf("\n\t\t\t\b\b USERNAME ALREADY EXIST!!!\t\b\bCHOOSE A NEW ONE");
            goto start;
        }
    }
    else
    {
        system("clear");
        printf("\n\t\t\tINVALID INPUT TRY AGAIN");
        goto start;

    }
}
