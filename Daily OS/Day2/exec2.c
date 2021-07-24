
#include<stdio.h>


int main()
{
 char *args[] = {"v",NULL};
 printf("One");

 execvp("./v",args);
 printf("Two");

 return (0);
}
