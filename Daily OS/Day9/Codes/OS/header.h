#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
struct mymsg
{
    long mtype;
    char message[50];
};
