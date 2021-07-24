#include<stdio.h>
int main()
{
 char str[20];
  if(fork())
    {

    printf("enter str==");
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

 return 0;
 }
