#include<stdio.h>

/*

	A
       /\
      B	 C 

*/



int main()
{
 int x;
 printf("\n\t I am a Parent : PID -> "getpid());
  x = fork(); 

 if(x == 1)
 {
  fork();
 }

 return(0);
}
