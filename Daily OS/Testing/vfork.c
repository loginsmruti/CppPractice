#include<stdio.h>
#include<stdlib.h>
int main()
{
 int k;
 k = vfork();
 
 if(k == 0)
 {
   printf("\n\tI am a Child.....");
 } 
 else
 {
  printf("\n\tI am a Parent.....\n");
  exit(0);
 }

 return 0;
}

