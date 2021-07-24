#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<singal.h>
#include "s5c.h"


int main()
 {
  
   int pid=fork();
  
   if(pid)
   {
    printf(" pid is %d\n ",getpid());
     fd=open("RECORD",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
     signal(SIGCHLD,chldTerm);
           

   }
   else
   {


   }
