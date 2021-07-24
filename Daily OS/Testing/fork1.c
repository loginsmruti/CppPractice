
#include<stdio.h>

int main()
{
 printf("\n\tHello");
 sleep(5);
 fork();
 printf("\n\tHI");
 sleep(5);
 fork();
 printf("\n\tBye");
 sleep(5);
 
 return 0;
}
