#include "header.h"
			//Client
int main()
{
   MSG m , m3;

   int mid , res ;
   m.type = 1;
   strcpy(m.s.name , "Vicky");
   strcpy(m.s.id ,"001");
  
   mid =msgget(KEY ,IPC_CREAT | 0600);

   msgsnd(mid ,&m , sizeof(STU) ,0);
   printf("\n\t Sent From Client\n");
  
   msgrcv(mid , &m3 ,sizeof(STU),2 , 0);
  
   printf("Client Printing ::: Name :%s   ID : %s \n",m3.s.name,m3.s.id);

 return (0);

}
