#include<stdio.h>
#include<stdlib.h>
int mysystem(char *cmd)
{
    if(!fork())
    {
       execvp(cmd,args);
       printf("Coomand not found\n");
       exit(0);
    }
    else
    {
        wait();
    }
}
int main(int argc,char *argv[])
{ 
    char cmd[10];
    do
    {
      printf("enter command::");
      gets(cmd);
      mysystem(cmd);
    }while((strcmp(cmd,"exit")!=0));
}

