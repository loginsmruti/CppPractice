/*

Write a program in which a process creates 10 child processes. Each of the child process is started by passing the pid of its immediate older sibling – this child process displays the pid of its immediate older sibling.
	All the children should continue to run till the last child is created.
	The parent should wait for all its children to die out.

*/



#include<stdio.h>
#include<stdlib.h>


int main()
{
 int cpid[10] , counter =0 ,i=10;

 while(counter < 10)
 {
   cpid[counter] = fork();
   if(!cpid[counter])
   {
    //printf("");
  printf("Previous Sibling ID Is : %d ....it's Parent Id Is :%d \n ",cpid[counter-1] ,getppid()); 
    sleep(1);
    exit(0);
   }  
 counter++;
 }

 while(i>0)
 {
      //printf("Previous Sibling ID Is : %d ....it's Parent Id Is :",cpid[counter]-i ,getppid()); 
  wait();
  i--;
 }
 return (0);
}

