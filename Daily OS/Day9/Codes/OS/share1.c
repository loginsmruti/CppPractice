#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
    int shmid;
    char *sh;
    shmid=shmget(101,20,IPC_CREAT|0660);
    sh=shmat(shmid,(void*)0,0);
    sleep(10);
}
