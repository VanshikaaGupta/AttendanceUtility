#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    char rl[20];
    char na[20];
    char atndnce[10];
    int count;
    int den;
}s;
int total[20];
long si = sizeof(s);
FILE *fp;

int enterAttendance();
void display();
void studentInfo();
int main()
{
    int date,s;
    int choice;
    char name[20];
    char password[10];
    do
    {
        printf("ATTENDANCE CALCULATOR \n\n\n\n\ ");


    printf("                1. Log in as teacher. \n");
    printf("                 2. Log in as student. \n");
    printf("                 3. Exit \n");
    printf("\n\n Enter your choice \n");
    scanf("%d",&choice);
    system("cls");
     switch(choice)
    {

        case 1:
        printf("Enter username: ");
        scanf("%s",name);
        printf("Enter password: ");
        scanf("%s",password);
        if (strcmp(name, "MCA") == 0&&strcmp(password, "teacher") == 0)
        {
            printf("\n \n \n         ACCESS GRANTED\n");
            printf("\n \n \n");
            do{
                    printf("     1.Add new record.\n ");
                    printf("     2.Display \n");
                    printf("     3.Exit \n");
                    printf("Enter your choice. \n");
                    scanf("%d",&s);
                    system("cls");
                    switch(s)
                    {
                        case 1:printf("Month-Jan      Year-2020\n\n");
                        enterAttendance();
                        break;

                        case 2:printf("Month-Jan      Year-2020\n\n");
                        display();
                        break;
                        case 3: exit(1);
                        break;

                        default: printf("Invalid choice\n");
                        break;


                    }
            }while(s!=3);


        }
        else printf("\n \n \n   ACCESS DENIED\n");
         break;


        case 2: printf("Enter username: ");
        scanf("%s",name);
          printf("Enter password: ");
          scanf("%s",password);
          system("cls");
           if (strcmp(name, "MCA") == 0&&strcmp(password, "student") == 0)
           {
               printf("\n \n \n ACCESS GRANTED\n");
               studentInfo();

           }

         else printf("\n \n \nACCESS DENIED\n");
         break;

       case 3: exit(1);
         break;

       default: printf("Invalid choice\n");
         break;
    }
    }while(choice!=3);
    return 0;

    }




   int t=0,m=0;
    int enterAttendance()
    {
        fp = fopen("synp.txt","a+");
        printf("Mark P:Present    A:Absent    H:Holiday\n\n");
        printf("Enter Roll: ");
        scanf("%s",&s.rl);
        printf("Enter Student Name: ");
        scanf("%s", &s.na);
        printf("Enter Attendance:\n");
        s.count=0;
        s.den=0;
        ++t;
        for(int i=0;i<10;i++)
            {
                printf("%d: ",i);
                scanf("%s", &s.atndnce[i]);
                if(s.atndnce[i]=='p'||s.atndnce[i]=='P' )
                {
                    s.count++;
                    s.den++;
                }
                if(s.atndnce[i]=='a'||s.atndnce[i]=='A')
                    s.den++;

            }

            int x=s.count;
            int y=s.den;
            total[m]=(x*100)/y;
            printf(" Total attendance %d %% \n",total[m]);
            ++m;
        fwrite(&s, sizeof(s),1,fp);
        printf("\n \nRecord Saved Successfully \n");
        fclose(fp);

    }
    int k;


    void display()
{
    printf("               STUDENTS INFORMATION \n\n");
    printf("%-30s %-20s  %s \n","Name","Roll","Attendance(%)");
    fp = fopen("synp.txt","r");
    while(fread(&s,sizeof(s),1,fp))
    {
        printf("%-30s %-20s  %d  \n",s.na,s.rl,total[k]);
        if(t!=0){
        t--;
        k++;
        }

    }
    fclose(fp);
    printf("Press any key to continue...");

}
void studentInfo()
{
    printf("               STUDENTS INFORMATION \n\n");
    printf("%-30s %-20s  %s \n","Name","Roll","Attendance(%)");
    fp = fopen("synp.txt","r");
    while(fread(&s,sizeof(s),1,fp))
    {
        printf("%-30s %-20s  %d  \n",s.na,s.rl,total[k]);
        if(t!=0){
        t--;
        k++;
        }
    }
}
