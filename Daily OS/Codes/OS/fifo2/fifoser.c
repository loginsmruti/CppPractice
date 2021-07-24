#include"header.h"
int main()
{
    int fd1,fd2,fd,fd3;
    char arr[25],c;
    int n;
    struct file f1;
    int count=1;
    mkfifo("myfifo",S_IRUSR|S_IWUSR);
    fd1=open("myfifo",O_RDWR);
    mkfifo("myfifo1",S_IRUSR|S_IWUSR);
    fd2=open("myfifo1",O_RDWR);
    while(1)
    {
       n=read(fd1,&f1,sizeof(f1));
       fd=open(f1.name,O_RDONLY);
       if(fd==-1)
       {
          write(fd2,"failed",n);
          continue;
       }
       n=lseek(fd,f1.offset,SEEK_SET);
       //perror("seek") ;
       //printf("seek Return : %d\n",n);
       fd3=open("printer",O_CREAT|O_WRONLY|O_APPEND,S_IRUSR|S_IWUSR);
       n=read(fd,&c,1);
       //printf("Return : %d  , Lenth: -  %d",n,f1.len);
       while(n&&count<=f1.len)
       {
          
          //printf("writing...\n");
          count++;
          if(f1.toggle==1)
          {
             if(c>='A'&&c<='Z')
             {
                c=c+32;
             }
             else if(c>='a'&&c<='z')
             {
                c=c-32;
             }
          }
          write(fd3,&c,1);
          n=read(fd,&c,1);
       }
       
       printf("printed successfully...\n");
       write(fd2,"done",n);
              
    }
}
