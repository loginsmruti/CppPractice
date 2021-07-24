#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>



void *bhubaneswar(void *);
void *cuttack(void *);

void *bhubaneswar(void *k)
{
 int *p = (int *)k ;
  
 printf("[bbsr() calling ]pthraed_self() : %ld::::getpid() : %d \n",pthread_self(),getpid() ); 
 int i ;
 char str[30] ="VICKY";
 for(i = 0 ; i<strlen(str) ; i++ )
 {
  write(*p , &str[i] , 1);
  sleep(1);  
 }
 //pthread_exit(3);
}

void *cuttack(void *k1)
{
 int *p1 = (int *)k1 ;
 printf("[Cuttack() calling ]pthraed_self() : %ld::::getpid() : %d \n",pthread_self() ,getpid()); 
 int i ;
 char str1[30] ="ROCKY";
 for(i = 0 ; i<strlen(str1) ; i++ )
 {
  write(*p1 , &str1[i] , 1);
  sleep(1);  
 }
 //pthread_exit(9);
}

int main()
{
 pthread_t t1 , t2 ;
 int   x;
// int *p = &x ;
 //int **q = &p ;
 int  start = open("MyText.txt",O_CREAT|O_RDWR);
 printf("pthraed_self() : %ld::::getpid() : %d \n",pthread_self() ,getpid()); 

 pthread_create(&t1 , 0 ,bhubaneswar ,(void *)&start ); 
  
 pthread_create(&t2 , 0 , cuttack ,(void *)&start);

 pthread_join(t1 , NULL);
 pthread_join(t2 , NULL);
 
 return 0;
}

