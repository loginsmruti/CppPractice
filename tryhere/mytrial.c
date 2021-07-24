#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
   int fd1 , fd2;
   char buf1[512] , buf2[512];
   
   fd1 = open("/etc/passowrd" , O_RDONLY);
   fd2 = open("/etc/passowrd" , O_RDONLY);

   read(fd1 , buf1 , 512);
   read(fd2 , buf1 , 512);
    
   return 0;
}
