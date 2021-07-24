#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{

 char ch[4];
 mkfifo("bkfifo",S_IRUSR|S_IWUSR);
  int fd=open("bkfifo",O_RDWR);
 write


 return 0;
}
