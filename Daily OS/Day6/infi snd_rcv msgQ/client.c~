#include "header.h"
			//Client
int main()
{
   MSG m , m3;
   char name[30] ,id[30];
   int mid , res ;
   
   m.type = getpid();
   
   printf("\n\t Enter Your Name : ");
   scanf("%[^\n]",name);
   getchar();
   printf("Enter You Id : ");
   scanf("%s",id);
   
   strcpy(m.s.name , name);
   strcpy(m.s.id ,id);
  
   mid =msgget(KEY ,IPC_CREAT | 0600);

   msgsnd(mid ,&m , sizeof(STU) ,0);
   printf("\n\t Sent From Client\n");
  
   msgrcv(mid , &m3 ,sizeof(STU), getpid(), 0);
    
   printf("Client Printing ::: Name :%s   ID : %s \n",m3.s.name,m3.s.id);

 return (0);

}
