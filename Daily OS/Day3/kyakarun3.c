
#include<stdio.h>
#include<fcntl.h>

int main()
{
// int k ;
 char x ;
 //k = open("vicky",O_CREAT|O_APPEND|O_RDWR,S_IRUSR|S_IWUSR);
 
  while(read(3 ,&x ,1))
    printf("%c",x);

 printf("\n\n"); 
 return (0);

}


























