#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<time.h>

void handler(int x)
{
}
void hand(int y)
{
    printf("ab nikal lo...program run ho to gaya\n");
    exit(0);
}
int main()
{
    int fd1[2];
    int pid;
    pipe(fd1);
    pid=fork();
    if(pid)
    {
       signal(SIGCHLD,hand);
       char arr[25];
       time_t t;
       int n;
       close(fd1[0]);
       while(1)
       {
         sleep(1);
         time(&t);
         write(fd1[1],&t,sizeof(time_t));
         kill(pid,SIGUSR1);
       }
    }   
    else
    {
       signal(SIGUSR1,handler);
       close(fd1[1]);
       int i=0;
       while(i<11)
       {
          pause();
          time_t t;
          read(fd1[0],&t,sizeof(time_t));
          printf("time is:-  %s\n",ctime(&t));
          i++;
       } 
    }
}
