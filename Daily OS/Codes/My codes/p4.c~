#include<stdio.h>
#include<stdlib.h>

int main()
{
 char *arg[]={"gcc","../c/assignment1/pattern7.c",NULL};
 char *arg1[]={"./a.out",NULL} ;//"../c/assignment1/pattern7.c"};
  int x;
  printf("i am %d and parent id is =%d",getpid(),getppid());
  if(!(x=fork()))
  {  
     execvp("gcc",arg);
  }
   wait() ;
     execvp("./a.out",arg1);
   return 0;
}
