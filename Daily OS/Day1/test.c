

#include<stdio.h>

int main()
{
 int x ,y =9;
 
 printf("\n\tVicky\n");

  x = fork(); 

  if(x == 1)
 {
  printf("After Fork ....I am Parent %d ,X = %d \n ", getpid(),x);
 }
 else
 {
  printf("I am a child :%d  .......X =%d \n",getpid(),x);
 }
 return (0);
}
