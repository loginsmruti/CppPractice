
#include<stdio.h>
#include<stdlib.h>


int main()
{
 char str[10] ;
 
 int x = fork();
 if(!x)
 { 
  //sleep(1);
  FILE *fp = fopen("XYZ","w");
  fprintf(fp , "%s\n" ,str);
 }
   
 return (0);
}
