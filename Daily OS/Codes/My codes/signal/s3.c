#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handl(int x)
 {
   printf("handler receive \n");
    exit(0);
 }


int main()
 {
   int pid=fork();
   int fd;
   time_t t;
   char arr[100];
   
   fd=fopen("TIME",O_CREAT |O_WRONLY|S_IRUSR,S_IWUSR);
   
  for(;;)
  {
  pid=fork();
  if(pid)
  {
   printf(" parent  ....\n");
 //  sleep(5);
   arr=t;
   write(fd,arr,sizeof
   pause();
   kill(pid,SIGUSR1);
  }
  else
   {
   signal(SIGUSR1,handl);
   printf("handler installed \n");
  

  }
 }
 return 0;

}
