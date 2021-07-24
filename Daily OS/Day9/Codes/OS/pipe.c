#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    if(!fork())
    {
       char arr[25];
       int n;
       close(fd1[0]);
       close(fd2[1]);
       while(1)
       {
         n=read(fd2[0],arr,24);
         write(fd1[1],arr,n);
         if(n==0)
         {
            break;
         }
       }
    }   
    else
    {
       close(fd1[1]);
       close(fd2[0]);
       char data[25];
       int n;
       while(1)
       {
         printf("Enter data...");
         gets(data);
         write(fd2[1],data,strlen(data));
         n=read(fd1[0],data,24);
         data[n]='\0';
         printf("server printed....%s\n",data);
         if(strcmp(data,"exit")==0)
         {
             exit(0);
         }
       }
       
    }
}
