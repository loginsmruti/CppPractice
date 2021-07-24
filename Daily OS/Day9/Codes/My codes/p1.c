/* WAP in which a process create 10 child process. Each of the child process is started by passing the pid of its immediate older sibling .this child process display the pid of its immediate older sibling */

#include<stdio.h>
#include<stdlib.h>

int main()
{
int cpid[10],counter;

 printf(" I AM THE FIRST PROC %d\n",getpid());
 
 for(counter=0;counter<10;counter++)
  {
   if(!cpid[counter])
    {
     if(counter==0)
          printf(" i am oldest sibling %d\n",getpid());
       else
          printf("


    }


 }
return 0;
}
