#include "header.h"
			//Client000000
int main()
{
   MSG m , m3;
   char msg[30] ;
   int mid , res ,id ;
   printf("\n\t Myprocess Id Is : %d",getpid());
   m.type = getpid();
   
   printf("\n\t Enter Process Id Of Partner : ");
   scanf("%d",id);
   printf("\nReady To Chat....\n");
   printf("\n\t Enter Your Message : ");
   scanf("%s",msg);
     
   strcpy(m.s.message , msg);

  
   mid =msgget(KEY ,IPC_CREAT | 0600);

   msgsnd(mid ,&m , sizeof(STU) ,0);
   printf("\n\t Sent From Client\n");
  
   msgrcv(mid , &m3 ,sizeof(STU), getpid(), 0);
    
   printf("Client Printing ::: Name :%s   ID : %s \n",m3.s.name,m3.s.id);

 return (0);

}
