#include"header.h"
int main()
{
   struct msg m;
   int mid=msgget(KEY,IPC_CREAT|0660);
   while(1)
   {
       int n = msgrcv(mid,&m,sizeof(struct myst),1,0);
       printf("Messege Recived : \n");
       printf("Messege :- %s\n",m.messeg.messege); 	
       m.mtype=m.messeg.pid;
       msgsnd(mid,&m,sizeof(struct myst),0);
   }

}

