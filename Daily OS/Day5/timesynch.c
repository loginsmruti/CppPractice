
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


void handle(int x)
{
}


int main()
{
int pipe1[2] ;
 int pid  ;//, pipe2[2];
  pipe(pipe1);
 
 pid = fork();

 if(pid)
 {
  time_t curtime ;
  char buf[30] ;
  int counter = 0;
  struct tm *loctime ;
  int status = 1 ;
  while(counter < 7)
  {
   sleep(1);
   close(pipe1[0]); //close(pipe2[1]);
   curtime = time(NULL);
   loctime = localtime(&curtime);
   strcpy(buf , asctime(loctime));
   write(pipe1[1] , buf , strlen(buf));
   printf("\n\t Time Is Written... : %s\n",buf);
   kill(pid ,SIGUSR1);
   counter++;
  }
   close(pipe1[0]);  
   wait(&status);
 }
 else
 {
  signal(SIGUSR1 ,handle);
  //printf("\n\t Signal Handler Installer.....");
 char temp[30];
 close(pipe1[1]);
 do {
   pause();
  // printf("\n\t Received Signal .....Now Time Available....");
   int no = read(pipe1[0] , temp ,30);
   temp[no] ='\0';
   printf("\nNow Time Is  : %s\n",temp);
 }while(1);
 close(pipe1[0]);
 }
 exit(0);
 return (0);
}
