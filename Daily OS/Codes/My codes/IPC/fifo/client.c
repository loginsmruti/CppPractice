#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
  //int i;

 char data[50];

 int fd1=open("ServerFifo",O_RDWR);
 int fd2=open("ClientFifo",O_RDWR);
  do
  {
 
 printf("\n Enter the data =");
  scanf("%s",data);


   write(fd2,data,strlen(data));

 
 int n=read(fd1,data,50);
   data[n]='\0';

 
 printf("server response is ...%s",data);
  }while(strcmp(data,"exit")!=0);
   return 0;
}
