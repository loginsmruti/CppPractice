
#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(void)
{ 
 int fd1 ,fd2,  n ;
 char data[30] ,buf[30];
 char x ;

 fd1 = open("serverinfo",O_WRONLY);
 perror("op1") ;
 fd2 = open("clientinfo",O_RDONLY);
 perror("op2") ;
  
 while(1)
 {
 printf("\n\t Enter some Data To Echo : ");
 scanf("%s",data);
 
 write(fd1 ,data , strlen(data));
 
 n = read(fd2 ,buf  , 10);
 buf[n] ='\0';
    printf(" Server Response is : %s\n",buf);

  printf("\n");

 if(strcmp(data , "exit") == 0 )
  break;

 }
    
 return (0);
}
