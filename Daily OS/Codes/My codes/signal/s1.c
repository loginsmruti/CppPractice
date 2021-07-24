#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handl(int x)
 {
   printf("recvd sig \n ");
 //   exit(0);
 }

int  main()
{
  signal(SIGINT,handl);
  printf("\n handler installed \n");
  for(;;);
 return 0;
} 
