#include<stdio.h>

int main(void)
{
 char name[30] ;
 printf("\n\t Enter Your Name  : ");
 scanf("%[^\n]",name);

 printf("My Name Is : %s\n",name);
 return (0);
}
