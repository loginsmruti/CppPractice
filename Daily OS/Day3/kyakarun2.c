#include<stdio.h>
#include<fcntl.h>

int main()
{
 
 int k ;
 char x ;
 k = open("vicky",O_CREAT|O_APPEND|O_RDWR,S_IRUSR|S_IWUSR);

 char *arg[] = {"./ok",NULL}; 



 execvp("./ok", arg);

 return (0);

}
