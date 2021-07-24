#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void h(int y)
{
 printf("\n\t After receiving ....I am stopping...");
}

void handle(int x)
{
 printf("\n\t Received Signal .....");
 exit(0);
}


int main()
{
 int pid ;
 pid = fork();

 if(pid)
 {
  signal(SIGCHLD , h);
  printf("\n\tParent : %d \n",getpid());
  sleep(5);
  kill(pid ,SIGUSR1);
  wait();
 }
 else
 {
  signal(SIGUSR1 ,handle);
  printf("\n\t Signal Handler Installed ....\n"); 
  for( ; ; );
 }

 return (0);
}
