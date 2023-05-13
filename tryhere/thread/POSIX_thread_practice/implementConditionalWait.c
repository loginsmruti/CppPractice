#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int count = 0;
int done = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

void * print_global()
{
   while(count < 20)
   { 

      pthread_mutex_lock(&mutex1);
      done = 1;
      pthread_cond_wait(&cond1, &mutex1);
      printf("child-1 thread value :     %d\n",count);
      count++;
      pthread_mutex_unlock(&mutex1);
   }
   printf("child-1 thread terminated\n");
}

void * print_global_other()
{
   int ret;
   while(count < 20)
   {
      if(done == 1)
      {
         pthread_mutex_lock(&mutex1);
         printf("child-2 thread value :     %d\n ",count);
         count++;
         done = 0;
         pthread_cond_signal(&cond1);
         pthread_mutex_unlock(&mutex1);
      }
   }
   printf("child-2 thread terminated\n");
}

int main()
{
   int ret;
   pthread_t thread_id, thread_id1;
   ret = pthread_create(&thread_id, NULL, print_global , NULL);
   if(ret != 0)
   {
      perror("error in thread creation");
   }
   ret = pthread_create(&thread_id1, NULL, print_global_other , NULL);
   if(ret != 0)
   {
      perror("error in thread creation");
   }
   pthread_join(thread_id, NULL);
   pthread_join(thread_id1, NULL);
   printf("parent thread terminated\n");
}
