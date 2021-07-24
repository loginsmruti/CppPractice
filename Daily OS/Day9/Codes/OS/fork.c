#include<stdio.h>
main()
{
   char str[35];
   if(!(fork()))
   {
     printf("Enter str  ");
     scanf("%s",str);
 
     FILE *fp=fopen("xyz","w");
     fprintf(fp,"%s\n",str);
     wait();
   }
   else
   {
     sleep(1);
     FILE *fp=fopen("abc","w");
     fprintf(fp,"%s\n",str);
   }
}
