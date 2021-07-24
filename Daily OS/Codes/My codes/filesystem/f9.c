#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
 int main()
{
  int fd;
   char *args[]={"./t",NULL};
   fd = open("bks",O_CREAT | O_RDWR,S_IRWXU);
   write(fd,"hello",5);
   execvp("./t",args);

 return 0;
}


