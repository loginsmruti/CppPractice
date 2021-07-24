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
     
     

     m2.type = m1.type ;        
     msgsnd(mid ,&m2 , sizeof(STU) ,0);

     printf("\nMessage Sent From Srever:  %s %s\n",m2.s.msg );
    
    }

  return (0);

}
