#include<stdio.h>


int main()
{
   struct 
   {
     int a ;
     int b;
     char x;
     char* y;
      
   }mySize;

   
   printf("Structure size ::: **[ %d ]**" , sizeof(mySize));

   return 0;
}
