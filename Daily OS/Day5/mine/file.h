#include<stdio.h>
#include<fcntl.h>
#include<string.h>


typedef struct file
{
  char fileName[20];
  short int flag;
  int startByte ,totalBytes ;
}File;

File p , q;

char *str_upr(char *);

char *string_concat(char * , char *);
