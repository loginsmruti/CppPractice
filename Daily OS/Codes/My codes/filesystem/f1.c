#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
   char arr[10];
   int fd=open("v7.c",O_RDONLY);
   
   read(fd,arr,6);
   arr[6]='\0';
   printf("%s",arr);
  printf("*****************1******************\n");
  

  read(fd,arr,6);
   arr[6]='\0';
   printf("%s",arr);

 /* read(fd,arr,6);
   arr[6]='\0';
   printf("%s",arr);
  
  read(fd,arr,6);
   arr[6]='\0';
   printf("%s",arr);*/

  printf("***********************************\n");
  
  

 
 return 0;
}
