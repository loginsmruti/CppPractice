#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#define KEY 100

struct student
 {
    int id; 
    char name[10],address[20];
    long fee;
 };
