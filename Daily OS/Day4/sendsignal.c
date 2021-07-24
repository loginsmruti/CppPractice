#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handle(int x)
{
 printf("\n\t Signal Received\n");
 exit(0);
}


int main()
{

 signal(SIGINT ,handle);
 printf("\n\t Signal Handler Install...");
  for( ; ; );

 return (0);
}
