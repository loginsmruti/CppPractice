#include<stdio.h>
#include<stdlib.h>

void mysystem(char *);

void mysystem(char *command)
{
 if(fork())
 {
  wait();
 }
 else
 {  
   char *arg[] ={command,NULL}; 
   execvp(command,arg);
   printf("\n\t No Such Commands.. : %s ",command);
   exit(0);
 }
}


int main(int argc, char *argv[])
{
  //printf("....Entry..... %s ",*(argv+1));
  printf("\nMy pid Is : %d \n",getpid()); 
  
  mysystem(*(argv+1));
  
  printf("\nMy pid Is : %d \n\n",getpid()); 
 
 return (0);
}
