#define MSGKEY 100
#define SHMKEY 101
#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include <sys/msg.h>
#include<signal.h>
#include<time.h>
struct student
{
   char name[50];
   int age;
};
struct reqmsg
{
   long mtype;
   struct student st;
};
struct resmsg
{
   long mtype;
   char msg[50];
};
