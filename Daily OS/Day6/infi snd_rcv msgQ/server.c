#include "header.h"

			//Server
int main(void)
{
    MSG m1 , m2 ;
 
    int mid , res ;
      
    mid =msgget(KEY ,IPC_CREAT | 0600);

    while(1)
    {
     msgrcv(mid , &m1 ,sizeof(STU),0 , 0);
     
     if(strcmp(m1.s.name , "exit") == 0)
       exit(0);
     //msgctl(mid , IPC_RMID ,NULL );
     printf("\n\t Received From Message Que\n");
     printf("Server Printing ::: Name :%s   ID : %s \n",m1.s.name,m1.s.id);
     
     strcpy(m2.s.name ,m1.s.name);
     strcpy(m2.s.id ,m1.s.id);

     m2.type = m1.type ;        
     msgsnd(mid ,&m2 , sizeof(STU) ,0);
     printf("\nMessage Sent From Srever:  %s %s\n",m2.s.name ,m2.s.id);
    
    }

  return (0);

}
