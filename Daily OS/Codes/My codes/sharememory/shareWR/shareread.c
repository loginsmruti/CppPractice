#include "head.h"

      
	 int main()
	{
          int id=shmget(111,10*sizeof(struct rec),IPC_CREAT|0600);
 	  void *p=shmat(id,0,0);
          
          
          struct rec *recptr=p;
         

          recptr++;
          printf("%d %s %c",recptr->x,recptr->arr,recptr->c);
          return 0;
        } 
           	  
