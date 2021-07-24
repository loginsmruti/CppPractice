#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(void)
{ 
 int fd1 , fd2 , n , counter =0;
 char s[10];
 mkfifo("serverinfo",S_IWUSR |S_IRUSR);
 mkfifo("clientinfo",S_IWUSR | S_IRUSR); 
 
 fd1 = open("serverinfo",O_RDONLY);
 perror("op1") ;
 fd2 = open("clientinfo",O_WRONLY);
 perror("op2") ;
 
printf("aft open\n") ;
 while(counter < 7)
 {
  n = read(fd1 , s ,10);
  s[n] ='\0';
      write(fd2 ,s ,n);
  
  counter++;
 }
 return (0);
}
