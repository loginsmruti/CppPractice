#include <stdio.h>
#include <fcntl.h>

int main()
{
   char databuf[20];
   int pid , fd , bytesread ;
   fd = open( "datafile" , O_RDONLY);

   pid = fork();

   if(pid == 0)
   {
      fd = open( "datafile" , O_RDONLY);
      bytesread = read(fd , databuf , 5);

      databuf[bytesread] = '\0';
      printf("Child has read :: %s" , databuf);
      exit(0);
   }
   bytesread = read(fd , databuf , 5);
   databuf[bytesread] = '\0';
   printf("parent has read :: %s \n" , databuf);

   return 0;


   
}

