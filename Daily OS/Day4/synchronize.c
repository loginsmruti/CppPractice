
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<string.h>
#include<signal.h>

void readfile(int );
void handle(int);
void terminate(int);

void readfile(int z)
{
 char arr[80] ;
 int fd  , n ;

  fd = open("LOG" ,O_RDONLY);
  n = read( fd , arr , 30);
  printf("\n\t   %s \n" ,arr );
  arr[n] ='\0' ;
  close(fd);
}


void terminate(int y)
{
 printf("\n\t Exiting....\n\n");
 exit(0);
}


int main(void)
{
 int pid ,fdt ;
 pid = fork();

 if(pid)
 {
  int i;
  char mytime[50];
  time_t curtime ;
  struct tm *loctime ;

 signal(SIGINT , terminate );
  printf("\n\t Signal Handler Is Installed ...\n");

  for( ; ; )
  {
   sleep(1);
   fdt = open("LOG" ,O_CREAT | O_APPEND |O_WRONLY ,S_IWUSR |S_IRUSR ) ;
   curtime = time(NULL);
   loctime = localtime(&curtime);
   strcpy(mytime , asctime(loctime));
   write(fdt ,mytime , strlen(mytime));
   close(fdt);
   kill( pid ,SIGUSR1 );
  }
  wait();
 }
 else
 {
  int counter ;
  signal( SIGUSR1, readfile  );

  for( ; ; )//counter =1 ;counter<=10 ; counter++)
  {
    pause();
  }
 }
 return(0);
}
