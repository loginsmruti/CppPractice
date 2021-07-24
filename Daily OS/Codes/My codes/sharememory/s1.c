#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define KEY 100
 int main()
  {
    int shmid;
    //char *shmptr;
    shmid=shmget(KEY,20,IPC_CREAT | 0660);
    //shmptr=shmat(shmid,(void *)0,0);
    sleep(5);

   return 0;
 }

 //NOTE -> after run this program use command $ipcs -m for show the structure of memory

