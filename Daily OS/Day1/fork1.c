
#include<stdio.h>

int main()
{
 //int x , y;
 
 printf("\n\tVicky\n");

  fork(); 

  printf("After Fork ....I am Parent %d , I am Child : %d \n ", getpid(),getppid());

  printf("After Fork ....I am Parent %d , I am Child : %d  \n", getpid(),getppid());
 

 return (0);
}
