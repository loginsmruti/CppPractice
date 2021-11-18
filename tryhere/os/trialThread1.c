#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *th_f(void *arg);

char *myString = "Aricent";

int main()
{
   pthread_t ntid;
   char *lptr;
   int status;
  
   status = pthread_create(&ntid , NULL ,th_f ,NULL); 
   if(status != 0)
   {
     printf("Error in Creating Thread\n");
     exit(status); 
   }
   pthread_join(ntid , (void**)&lptr);
   printf("%s\n" , lptr);
   pthread_exit(NULL);
  
  return 0; 
}

void *th_f(void *arg)
{
   printf("New Thread: ");
   myString++;
   pthread_exit((void*)myString);
}


