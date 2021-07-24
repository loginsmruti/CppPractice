#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
struct file
{
   char name[50];
   int toggle;
   int offset;
   int len;
};

