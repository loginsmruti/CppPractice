
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

#define KEY 300 
#pragma pack(1)

typedef struct stud 
{

 char message[50];
 
}STU;

typedef struct msg 
{
 long type ;
 STU s;
}MSG;

