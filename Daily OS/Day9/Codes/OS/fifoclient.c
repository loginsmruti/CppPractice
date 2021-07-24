#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd1,fd2;
    char arr[25];
    int n;
    mkfifo("myfifo",S_IRUSR|S_IWUSR);
    fd1=open("myfifo",O_RDWR);
    mkfifo("myfifo1",S_IRUSR|S_IWUSR);
    fd2=open("myfifo1",O_RDWR);
    while(1)
    {
       n=read(fd1,arr,24);
       arr[n]='\0';
       printf("From Server :- %s\n",arr);
       if(strcmp(arr,"exit")==0)
       {
           exit(0);
       }
       write(fd2,arr,n);
    }
}
