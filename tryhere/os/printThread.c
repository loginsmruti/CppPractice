#include <stdio.h>
#include <pthread.h>

void *printme(void *th);

void *printme(void *th)
{
   int *p;
   p = (int*)th;
   printf("i am thread :%d\n", *p);
   free(th);
   pthread_exit(NULL);
}

int main()
{
   pthread_t thread[5];

   int t;
   int *iptr;
   for(t = 0 ; t< 5 ; t++)
   {
      iptr = (int *)malloc(sizeof(int));
      *iptr = t;
      pthread_create(&thread[t] , NULL , printme , iptr);   
   }
     pthread_exit(NULL); 

     return 0;
}
