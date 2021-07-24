#include "head.h" 
       int main()
	{
          int id=shmget(111,10*sizeof(struct rec),IPC_CREAT|0600);
 	  void *p=shmat(id,0,0);
          struct rec obj;
	  obj.x=1;
          obj.c='b';
 	  strcpy(obj.arr,"binit");
          
          struct rec *recptr=p;
          memcpy(recptr,&obj,sizeof(obj));

          recptr++;
          scanf("%d%s%c",&recptr->x,recptr->arr,&recptr->c);
          return 0;
        } 
           	  
