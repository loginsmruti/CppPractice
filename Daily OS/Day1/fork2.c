
#include<stdio.h>

int main()
{
 int x ;
 int y =10;
 
 printf("\n\tVicky1\n");
 printf("\n\tVicky2\n");
 printf("\n\tVicky3\n");

 x = fork(); 

 if(x == 0 ) {
   printf("\n\t I a Child.... with PID :%d y = %d\n",getpid(),y);
 }
 else {
    printf("\n\t I am a Parent...with PPID : %d y = %d \n",getppid(),y); 
 }

 return (0); 
 }
