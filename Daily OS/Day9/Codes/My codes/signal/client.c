#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "s5c.h"
#include<signal.h>

void add_record(struct client stu)
 {
  int fd;

   char ch=' ';
 
   fd=open("CLIENT",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
   while(ch!='n')
  {
    printf("\n Enter the id of client ");
     scanf("%d",&stu.id);
     getchar();
    printf("\n Enter the name of client =");
     scanf("%s",stu.name);
     getchar();
    printf("\n Enter the address of client =\n");
     scanf("%s",stu.address);
     getchar();
 
    printf("Enter the fee of client =");
       scanf("%f",&stu.fee);
     getchar();
      write(fd,&stu,sizeof(struct client));
   printf("\nDO YOU WANT TO CONTINUE ");
      scanf(" %c",&ch);
      getchar();
  }
}

void display_record(struct client stu)
 {
   int fd;

   fd=open("client",O_RDONLY);
    while(read(fd,&stu,sizeof(stu)))
    {
   printf("id\t|name\t|address\tfee\n");
   printf("%d\t%s\t%s\t%f",stu.id,stu.name,stu.address,stu.fee);
  
 //  read(fd,&stu,sizeof(struct client));
 }
}
 void modify_record(struct client stu)
  {
    int fd;
    int cid=0;
    fd=open("client",O_RDONLY|O_APPEND);
    printf("\n Enter the id  ");
    scanf("%d",&cid);
  while(read(fd,&stu,sizeof(stu)))
  {
   if(cid==stu.id)
     { 
       
       printf("\n Enter the new name of client =");
       scanf("%s",stu.name);
     getchar();
       printf("\n Enter the new address of client =");
       scanf("%s",stu.address);
     getchar();
       printf("\n Enter the fee of client =");
       scanf("%f",&stu.fee);
     getchar();
       write(fd,&stu,sizeof(stu));
     }
 }
 }
int main()
{
 
  struct client stu;
   int choice ;
   int pid;
  printf("Enter your pid =");
  scanf("%d",&pid);

   while(1)
   {
   
   printf("1.Add the record \n");
   printf("2.MODify the record \n");
   printf("3.View the record \n");
   printf("4. exit \n");
   printf("Enter your choice \n");
   scanf("%d",&choice);
   
   switch(choice)
     {
       case 1:
                  printf("\n Adding the record ");
                  add_record(stu);
                  
                   kill(pid,SIGUSR1);
                     break;
       case 2:
                   printf("\n modify the record ");
                   modify_record(stu);
                   kill(pid,SIGUSR1);
                   
                      break;
      case 3:
                   printf("view the record ");
                   display_record(stu);
                   kill(pid,SIGUSR1);
                     break;
      case 4:
                  printf("exit");
                  kill(pid,SIGUSR2);
                      exit(0);
        default:
                   printf("WRONG OUTPUT ");

    }
  }
 
 return 0;
}
