#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
void handler(int x)
{
    time_t t;
    int fd=open("time",O_RDONLY);
    lseek(fd,-sizeof(time_t),SEEK_END);
    read(fd,&t,sizeof(time_t));
    close(fd);
    printf("Time is:- %s\n",ctime(&t));
}
void hand(int y)
{
    printf("Parent terminated..\n");
    exit(0);
}
int main()
{
    int pid;
    pid=fork();
    if(pid)
    {
       time_t t;
       signal(SIGCHLD,hand);
       while(1)
       {
          sleep(1);
          time(&t);
          int fd=open("time",O_WRONLY|O_APPEND|O_CREAT,S_IRUSR|S_IWUSR);
          write(fd,&t,sizeof(time_t));
          close(fd);
          kill(pid,SIGUSR1);
       }
    }
    else
    {
       int i;
       signal(SIGUSR1,handler);
       for(i=1;i<=10;i++)
       pause();
    }
}
