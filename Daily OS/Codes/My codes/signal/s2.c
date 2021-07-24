#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handl(int x)
 {
    printf("\n handler receiver ");
    exit(0);
 }
int main()
{
int pid=fork();

 if(pid) //par
  {
  //signal(SIGCHLD,h);
   printf("par...\n");
   sleep(5);
   kill(pid,SIGUSR1);
  //wait();
 }
 else 
 {
   signal(SIGUSR1,handl);
   printf("halder installed \n");
   for(;;);
 }
return 0;
 }

