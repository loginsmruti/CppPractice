
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{ 
 int fd1 ,fd2,  n ;
 char data[30] ,buf[30];
 char x ;

 fd1 = open("server",O_WRONLY);
 perror("op1") ;
 fd2 = open("client",O_RDONLY);
 perror("op2") ;
  
 printf("\n\t Enter some Data To Echo : ");
 scanf("%s",data); 
 write(fd1 ,data , strlen(data));
 
 printf("Enter a (1/0) as Toggle Flag :");
 scanf("%d",&flag);
 
 write(fd1 ,&flag , sizeof(int));
 n = read(fd2 ,buf  , 10);
 buf[n] ='\0';
    printf(" Server Response is : %s\n",buf);

  printf("\n");

    
 return (0);
}
