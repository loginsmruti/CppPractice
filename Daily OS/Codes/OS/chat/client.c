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
   
    int mid=100;
    struct mymsg msg,msg1;
    mid=msgget(100,IPC_CREAT|0660);
    pid=fork();
    if(pid)
    {
        msgsnd(mid,&msg,sizeof(msg),0);
        printf("message sent\n");
        msgrcv(mid,&msg1,sizeof(msg),2,0);
        printf("name:-%c\n",msg1.m.name);
        printf("integer:-%d\n",msg1.m.i);
    }
