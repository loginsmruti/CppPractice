#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

struct student
{
   char name[25];
   int roll;
};

int main()
{
   int pid,fd,ch,roll;
   struct student st;
   printf("Enter process id... ");
   scanf("%d",&pid);
   do
   {
      printf("Enter 1 for add new record\n");
      printf("Enter 2 for modify record\n");
      printf("Enter 3 for view a record\n");
      printf("Enter 4 to exit\n");
      scanf("%d",&ch);
      getchar();
      switch(ch)
      {
         case 1:
             fd=open("clientfile",O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);
             printf("\nEnter name:  ");
             gets(st.name);
             printf("\nEnter Roll No:  ");
             scanf("%d",&st.roll);
             write(fd,&st,sizeof(struct student));
             close(fd);
             kill(pid,SIGUSR1);
             break;
         case 2:
             fd=open("clientfile",O_RDWR);
             lseek(fd,0,SEEK_SET);
             printf("\nEnter Roll No:  ");
             scanf("%d",&roll);
             while(read(fd,&st,sizeof(struct student)))
             {
                if(roll==st.roll)
                {
                  printf("\nEnter name:  ");
                  gets(st.name);
                  break;
                }
             }
             lseek(fd,-sizeof(struct student),SEEK_CUR);
             write(fd,&st,sizeof(struct student));
             kill(pid,SIGUSR1);
             break;
         case 3:
             fd=open("clientfile",O_RDONLY);
             lseek(fd,0,SEEK_SET);
             printf("\nEnter Roll No:  ");
             scanf("%d",&roll);
             while(read(fd,&st,sizeof(struct student)))
             {
                if(roll==st.roll)
                {
                  printf("\nName:  %s ",st.name);
                  break;
                }
             }
            break;
         case 4:
             kill(pid,SIGUSR2);
             exit(0);
      }
   }while(1);
}
