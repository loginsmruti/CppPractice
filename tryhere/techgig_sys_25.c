#include <stdio.h>
#include <fcntl.h>

int main(int argc , char *argv[]) 
{
   int fd1 , fd2 , fd3;
   char var1, var2 , var3 ;

   char* fname = argv[1];
   fd1 = open(fname , O_RDONLY);
   fd2 = open(fname , O_RDONLY);
   fd3 = open(fname , O_RDONLY);

   dup2(fd2 , fd3);
   read(fd1 , &var1 , 1); 
   read(fd2 , &var2 , 1); 
   read(fd3 , &var3 , 1); 
   printf("c1 = %c , c2 = %c , c3 = %c ",var1 , var2 , var3);

   return 0;  
   
}
