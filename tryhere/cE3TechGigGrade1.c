/* C Program - Sort String in Alphabetical Order */

#include <stdio.h>
#include<string.h>

int main()
{
   char str[10][30], t[30];

   int i = 0;
   int j = 0;

   int processCount = 0;

   printf("Enter any five string (name) : ");

   for(i=0; i<10; i++)
   {
      scanf("%s",str[i]);
      if(!strcmp("END", str[i])) {
         memset(str[i] , 0 , 30);
         processCount = i + 1; 
         break;
      } else {
         processCount = i + 1;
      }
   }
  
   for(i=1; i<processCount ; i++)
   {
      for(j=1; j<processCount ; j++)
      {
         if(strcmp(str[j-1], str[j])>0) {
            strcpy(t, str[j-1]);
            strcpy(str[j-1], str[j]);
            strcpy(str[j], t);
         }
      }
   }
   printf("Strings (Names) in alphabetical order :");
   for(i=processCount; i>=0; i--)
   {
      printf(" %s",str[i]);
   }
   return 0;
}
