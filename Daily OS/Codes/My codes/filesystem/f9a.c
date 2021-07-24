#include<stdio.h>
#include<stdlib.h>

int main()
{
 char arr[10];

 lseek(3,0,SEEK_SET);
  read(3,arr,5);
  arr[5]='\0';
 printf("data read :%s\n",arr);

  return 0;
}
