#include<stdio.h>
int main(int argc,char* argv[])
{
    int a=fork();
    if(!a)
    {
       if(argc==2)
       {
          char *args[]={"gcc","-o","hello.out",argv[1],NULL};
          execvp("gcc",args);
       }
       else
       {
          return -1;
       }
    }
    
    else 
    {
          int stat;
          wait(&stat);
          if(stat==0)
          {
             char *args1[]={"hello.out",NULL};
             execvp("./hello.out",args1);
          }
          else
          {
             printf("Error...\n");
          }
    }
}
