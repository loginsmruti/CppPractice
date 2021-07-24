#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#define MSGKEY 110
#define SHMKEY 111
struct student
{
    char name[25];
    int roll;
};

struct msg
{
    long mtype;
    struct student st;
};

struct resmsg
{
    long mtype;
    char msg[25];
};
