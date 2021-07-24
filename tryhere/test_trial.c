#include <stdio.h>

int main()
{
   int i = -1 , n = 0;
   int arr[5] = {0};

   while(!feof(stdin))
   {
      scanf("%d " , &arr[++i]);
   }
   
   n = i; 
   while(n != -1)   
   {
      printf(" %d ,",arr[n]);
     n--; 
   }
}
