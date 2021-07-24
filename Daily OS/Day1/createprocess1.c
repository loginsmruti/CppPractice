
#include<stdio.h>

/*

	A
	|
	|
	B
	|
	|
	c

*/



int main()
{
 int x;
 printf("\n\t I am a Parent : PID -> "getpid());
  x = fork(); 

 if(!x)
 {
  fork();
 }

 return(0);
}
