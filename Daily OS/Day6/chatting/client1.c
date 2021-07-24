#include "header.h"
			//Client1111111.....
int main()
{
   MSG m , m3;
   char name[30] ,id[30];
   int mid , res ;
   printf("\n\t Myprocess Id Is : %d",getpid());
   m.type = getpid();
   
     
   printf("\n\t Enter Process Id Of Partner : ");
   scanf("%s",name);
   printf("\nReady To Chat....\n");
   strcpy(m.s.name , name);

  
   mid =msgget(KEY ,IPC_CREAT | 0600);

   msgsnd(mid ,&m , sizeof(STU) ,0);
   printf("\n\t Sent From Client\n");
  
   msgrcv(mid , &m3 ,sizeof(STU), getpid(), 0);
    
   printf("Client Printing ::: Name :%s   ID : %s \n",m3.s.name,m3.s.id);

 return (0);

}
