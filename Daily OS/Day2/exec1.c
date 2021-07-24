
#include<stdio.h>


int main()
{
 char *args[] = {"mv","./../vicky.txt","./",NULL};
 printf("One");

 execvp("mv",args);
 printf("Two");

 return (0);
}
