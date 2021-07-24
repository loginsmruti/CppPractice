#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
struct msg
{
    int i;
    char name;
};
struct mymsg
{
    long mtype;
    struct msg m;
};
int main()
{
   
    int mid;
    struct mymsg msg,msg1;
    msg.mtype=1;
    msg.m.i=100;
    msg.m.name='s';
    mid=msgget(100,IPC_CREAT|0660);
  //  msgsnd(mid,&msg,sizeof(msg),0);
    msgrcv(mid,&msg1,sizeof(msg),1,0);
    printf("name:-%c\n",msg1.m.name);
    printf("integer:-%d\n",msg.m.i);
  //  msgctl(mid,IPC_RMID,NULL);
}
