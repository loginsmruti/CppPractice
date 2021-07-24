#include"header.h"
int main()
{
   struct msg m,m1;
   char ch='y';
   int mid=msgget(KEY,IPC_CREAT|0660);
   while(ch!='n')
   {
       printf("Enter Messege : ");
       gets(m1.messeg.messege);
       m1.mtype=1;
       m1.messeg.pid=getpid();
       msgsnd(mid,&m1,sizeof(struct myst),0);      
       msgrcv(mid,&m,sizeof(struct myst),getpid(),0);
       printf("Messege Recived : \n");
       printf("Type :- %ld\n",m.mtype); 	
       printf("Messege : - %s\n",m.messeg.messege);
       printf("Conyinue (y/n)");
       ch=getchar();
       getchar();
   }

}
