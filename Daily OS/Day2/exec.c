#include<stdio.h>


int main()
{
 char *args[] = {"mv","./../A Process.ppt","./",NULL};
 printf("One");

 execvp("mv",args);
 printf("Two");

 return (0);
}
