                         // program for sending the time throrgh sender and receiver will receive the file and print the time on terminal 
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<string.h>
#include<time.h>
void readFile(int x)
 {
 char arr[80];
   int fd=open("TIME",O_RDONLY);
   int n=read(fd,arr,30);
    arr[n]='\0';
   printf("%s\n",arr);
   close(fd);

 }
  void chldTerm(int x)
  {
    exit(0);
 }

 int main()
 {
 int cpid=fork();

  if(cpid)
  {
   int fd;
    char newTime[80];
    time_t t;
    signal(SIGCHLD,chldTerm);
     for(;;)
      {
         sleep(1);
         fd=open("TIME",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
         t=time(NULL);
         strcpy(newTime,ctime(&t));
          write(fd,newTime,strlen(newTime));
         close(fd);
         kill(cpid,SIGUSR1);
     }

 }
 else 
 {
   int cntr;
    signal(SIGUSR1,readFile);
       for(cntr=1;cntr<=10;cntr++)
            pause();


 }

 return 0;
}
