#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXBUF 10

void* doit(void*);
int fd ;

int main()
{
   char buf[MAXBUF];

   pthread_t th1;
   int ret;

   ret = pthread_create(&th1 , NULL , doit , NULL);
   if(ret)
   {
      printf("Error in creating thread\n");
      exit(EXIT_FAILURE);
   }
   
   ret = pthread_join(th1 , NULL);
   if(ret)
   {
      printf("Error in joining thread\n");
      exit(EXIT_FAILURE);
   }
   
   ret = read(fd , buf , MAXBUF);
   if(-1 == ret)
   {
      printf("Error in reading File\n");
      exit(EXIT_FAILURE);
   }
   buf[ret] = '\0';

   printf("read by main : %s\n" , buf);
   exit(EXIT_SUCCESS);
   
}

void *doit(void *ptr)
{
   int i ;
   char buf[MAXBUF];
   fd = open("sample" , O_RDONLY );

   if(-1 == fd)
   {
      printf("Error in opening File\n");
      pthread_exit(NULL); 
   }
   i = read(fd , buf , 2);
   buf[i] = '\0';

   printf("read by thread : %s\n" , buf);
   pthread_exit(NULL); 
}

