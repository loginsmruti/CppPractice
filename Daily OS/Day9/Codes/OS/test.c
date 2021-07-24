#include<stdio.h>
#include<stdlib.h>
int mysystem(char *cmd)
{
    if(!fork())
    {
       char *args[]={cmd,NULL};
       execvp(cmd,args);
       //printf("u\n");
       //exit(0);
    }
    else
    {
        wait();
    }
}
int main(int argc,char *argv[])
{ 
    printf("1 process id=%d\n",getpid());
    mysystem(argv[1]);
    printf("2 process id=%d\n",getpid());
}

