#include<stdio.h>

int main()
{
 int x , y;
 
 printf("\n\tVicky\n");

 x = fork(); 

 if(x == 0 ) {
   printf("\n\t I a Child.... with PID :%d \n",getpid());
 }
 else {
    printf("\n\t I am a Parent...with PPID : %d \n",getppid()); 
 }
 
 y = fork(); 

 if(y == 0 ) {
   printf("\n\t I a Child.... with PID :%d \n",getpid());
 }
 else {
    printf("\n\t I am a Parent...with PPID : %d \n",getppid()); 
 }



 return (0);
}
