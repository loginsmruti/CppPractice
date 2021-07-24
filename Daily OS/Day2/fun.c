#include<stdio.h>

int bbsr();

int main()
{
 int (*p)();
 p = 0x400511;
 //printf("%x",&bbsr);
 (*p)();
}

int bbsr()
{
 printf("\n\tBhubaneswar\n\n");
 return 0;
}
