#include"header.h"
int main()
{
   struct msg m;
   struct init in;
   int mid=msgget(KEY,IPC_CREAT|0660);
   int count=0,flag=1;
   int pid[2];
   while(count<2)
   {
       msgrcv(mid,&in,sizeof(int),2,0);       
       pid[count]=in.pid;
       count++;       
   }  
   printf("Client running : \n"); 
   while(1)
   {
       msgrcv(mid,&m,sizeof(struct myst),1,0);
       printf("Messege Recived : \n");
       printf("Messege :- %s\n",m.messeg.messege);
       printf("recived :: %d\n",m.messeg.pid);
       if(m.messeg.pid==pid[0])
       { 	
            m.mtype=pid[1];
       }
       else
       {
           m.mtype=pid[0];
       }
       msgsnd(mid,&m,sizeof(struct myst),0);
   }

}

