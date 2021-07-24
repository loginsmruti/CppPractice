#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{

char arr[20];
 int fd=open("new",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
write(fd,arr,6);
 return 0;
}
