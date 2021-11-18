#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *printme(void *th);

void *printme(void *th)
{
   int *p;
   p = (int*)th;
   printf("i am thread :%d\n", *p);
   pthread_exit(NULL);
}

int main()
{
   pthread_t thread[5];

   int t , rc ;
   for(t = 0 ; t< 5 ; t++)
   {
      //printf("Creating Thread\n");
      rc = pthread_create(&thread[t] , NULL , printme , (void*)&t);   
      if(rc) 
         printf("Error creating thread\n");
   }
   
   exit(EXIT_SUCCESS);
     return 0;
}
