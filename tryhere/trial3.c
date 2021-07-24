#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int val;
   unsigned char *str = "16";

//   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);


   return(0);
}
