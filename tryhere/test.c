#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXBUF 10
#if 0

char buffer[MAXBUF] = {0};

int main()
{
   ssize_t bytesread = 0;
   

   int fd = 0; 
   fd = open("tmpfile" , O_RDONLY);

   bytesread = read(3 , buffer , MAXBUF);

   printf ("%d -- %d -- %s",fd , bytesread , buffer);
}

int main()
{
   ssize_t bytesread;
   char buf[512] = {0};
   char buf1[512] = {0};

   int fd1 , fd2 , ret; 
   fd1 = open("/etc/passwd" , O_RDONLY);
   fd2 = open("/etc/passwd" , O_RDONLY);

   ret = fork();
   if(0 == ret)
   {
     // bytesread = read(fd1, buf , 512);
      int ret;
      char *cmd[] = { "ls", "-l", (char *)0 };
         ret = execv ("/bin/ls", cmd);
   }
   else
   {
      wait(NULL);
      bytesread = read(fd2, buf1 , 512);
   }

   return 0;
}






int main( int argc , char* argv[])
{
   ssize_t bytesread = 0;
   ssize_t byteswrite = 0;
   
   char buffer[1];
   
   int fd = 0; 
   fd = open(argv[1] , O_RDONLY);
   
   if(fd < 0)
      printf(" Flie Opening Unsuccessfull");

   while(1)
   {
      bytesread = read(fd , buffer , 1);
      byteswrite = write( 1 , buffer , bytesread);
   }


   return 0;
}

int main()
{
   int   ret , pfd[2];     
   char *msg = "Hello World\n";
   signal(SIGPIPE , SIG_IGN);
   if ( pipe ( pfd ) < 0)              /* create a pipe  */
   {                                 /* must do before a fork */
      exit (1);
   }
   close ( pfd [0] );                 /* close unneeded I/O */
 
   ret = write( pfd[1] , msg , strlen(msg));
   if(ret)
   {
      printf("written Successfull");
   }
   else
   {
      printf("written Unsuccessfull");
   }

   
   exit (0);
}

int main()
{
   size_t toread = 10;
   ssize_t bytesread;
   char* buf = NULL;

   int fd = 0; 
   fd = open("tmpfile" , O_CREAT|O_RDWR , S_IRWXU);

   bytesread = read(fd, buf , toread);

   printf ("%d -- ",bytesread );
}
int main()
{
   printf ("Hello\n");
   
   fork(); 
   fork(); 
   fork(); 
   fork(); 
   printf ("Hello\n");

   return 0;
}


#endif


#if 0
int main()
{
   int x = 2;
   switch(x) 
   {
      case 2:
         printf ("TWO");
         break;
      
      case 3:
         printf ("THREE\n");

   }

   return 0;
}
#endif

int main()
{
   int *p ,  *q;

   p = (int*)malloc(sizeof(int));
   q = (int*)malloc(sizeof(int));
  
   *p = 10;

   q = p;

   printf("value :: %d" , *q);
   return 0;
}

