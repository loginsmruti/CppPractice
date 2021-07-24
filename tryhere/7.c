#include <stdio.h>

char buf[10];
int fun()
{
   char name[] = "ABCD";
   static int i = 0;
   int n = sprintf(&buf[i++] , "%c%c" , name[0] , name[1]);

   return n;
}

int main()
{
 int j =fun();
 
 strcpy(&buf[j] , "CD");
 printf("\n %s", buf);
 
 return 0;
}
