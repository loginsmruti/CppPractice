#include<stdio.h>
#include<stdlib.h>

void mysystem();

void mysystem()
{
 char command[10];
  printf("\n\n## ");
  scanf("%s",command); 
  while(strcmp(command , "exit") != 0)
  {
    if(fork())
    {
     wait();
    }
    else
    {   
      char *arg[] = {&command,NULL}; 
      execvp(command,arg);
      printf("\n\t No Such Commands.. : %s ",command);
      exit(0);
    }
     printf("\n\n## ");
     scanf("%s",command); 
   
  }
}


int main()
{
    
  mysystem();
   
 return (0);
}
