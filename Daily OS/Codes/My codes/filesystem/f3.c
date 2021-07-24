#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{

char arr[10]={-1,2,3,4,5,6,7,8,9,10};
 int x;
 int fd=open("new",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
write(fd,arr,10*sizeof(int));
 close(fd);

 fd=open("new",O_RDONLY);
 read(fd,&x,sizeof(int));
 printf("%d\n",x);
 return 0;
}
