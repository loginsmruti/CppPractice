#include<stdio.h>
#include<stdlib.h>

/*
int main()
{
   int i , x ,y;


    x = fork();
     if(x)
     { 
       y = fork();
      for(i = 0 ; i<10 ; i++)
      {
        if(y == 0)
        {
          fork();
          printf("PPID = %d ",getppid());
          sleep(1);
          wait();    
         }
       }
        wait();
     }
     else {
       printf("\ntest");  
       exit(0);
     }
  
 return (0);
}

*/
