#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
int copy(char *source,char *destination)
{   
    char c;
    int fd1=open(source,O_RDONLY);
    if(fd1==-1)
    {
       return -1;
    }
    int fd2=open(destination,O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR);
    if(fd2==-1)
    {
       return -2;
    }
    while(read(fd1,&c,sizeof(char)))
    {
       write(fd2,&c,sizeof(char));
    }
    close(fd1);
    close(fd2);
    return 0;
}
void ex(int y)
{
   printf("server exiting...\n");
   exit(0);
}
void handler(int t)    
{
   int x;
   x=copy("clientfile","serverfile"); 
   if(x==0)
   {
      printf("copy successfully..\n");
   }
   if(x==-1||x==-2)
   {
      printf("not copied...\n");
   }
}
int main()
{
    int pid=getpid();
    printf("\nServer PID is: %d\n",pid);
    signal(SIGUSR1,handler);
    //signal(SIGUSR2,ex);
    while(1);
}
    





