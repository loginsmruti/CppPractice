#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
struct stud
{
   char name[25];
   int roll;
};
int main()
{
    int shmid;
    int fd;
    struct stud st;
    char *sh;
    shmid=shmget(101,20,IPC_CREAT|0660);
    sh=shmat(shmid,(void*)0,0);
    do
    {
       printf("1-add new record\n");
       printf("2-update new record\n");
       scanf("%d",&ch);
    }
    
}
