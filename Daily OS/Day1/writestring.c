
#include<stdio.h>
#include<stdlib.h>


int main()
{
 char str[10] ;
 
 //int x = fork();
 if(fork())
 { 
  printf("Parent\n\tEnter A String : ");
  scanf("%s",str);
  FILE *fp = fopen("XYZ","w");
  fprintf(fp , "%s\n" ,str);
  wait();
 }
 else
 {
  sleep(1);
  FILE *fp = fopen("XYZ","w");
  fprintf(fp , "%s\nchild" ,str);
  
  
 }
   
 return (0);
}
