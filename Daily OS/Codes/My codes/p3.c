// program for excevp  

#include<stdio.h>
#include<stdlib.h>

int main()
{
 char *arg[]={"cp","p2.c","p3.c"};
   printf("one\n");
   execvp("cp",arg);
   printf("two\n");
 return 0;
}