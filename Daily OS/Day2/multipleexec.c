/*
     
   running another binary by creating a child process.....
  
*/


#include<stdio.h>

int main()
{
 int i ,x;
 char *arg0[] = {"gcc","-o","out","./fun.c","-w",NULL};
 char *arg1[] = {"./out",NULL};
  
  x=fork();
  if(x == 0)   // or if(!x)
  {
    execvp("./out",arg1);
  }
  //sleep(1);
  wait();
  execvp("gcc",arg0);
 return(0);
}
