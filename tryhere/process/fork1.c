
#include<stdio.h>

/*

   A
   |
   B
  /  \ 
 /    \
c      d

 */



int main()
{
   int x = 0;
   printf("I am a Parent : PID -> %d\n", getpid());
   x = fork(); 

   if(!x) {
      
   } else {
      y = fork();
      if(!y) {
         
      } else {
        fork(); 
      }
      
   }
   
   return(0);
}

