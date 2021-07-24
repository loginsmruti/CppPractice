#include <stdio.h>
#include <unistd.h>

int main()
{
   int pid , fd[2];
   int retval , totbytes = 0;

   char* msg = "aricent" , mychar ;
   pipe(fd);

   pid = fork();

   if(pid == 0)
   {
      write(fd[1] , msg , strlen(msg));
      close(fd[1]);
      exit(0);
   }
   else
   {
      wait(NULL);
      write(fd[1] , msg , strlen(msg));
      close(fd[1]);

      while(retval = read(fd[0] , &mychar , 1) > 0)
         totbytes += retval ;
      printf("%d" , totbytes);
      
   }
   exit(0);
}
