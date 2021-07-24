#include"header.h"
int main()
{
   
    int mid;
    struct mymsg msg;
    mid=msgget(100,IPC_CREAT|0660);
    //msgsnd(mid,&msg,sizeof(msg),0);
    msgrcv(mid,&msg,sizeof(msg),1,0);
    printf("message recieved..\n");
    msg.mtype=2;
    msgsnd(mid,&msg,sizeof(msg),0);
    //msgctl(mid,IPC_RMID,NULL);
}
