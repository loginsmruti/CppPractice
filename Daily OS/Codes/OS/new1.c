#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
long my_open(char *file, int *fd)
{
   struct stat st;
   *fd=open(file,O_RDONLY);
   if(*fd!=-1)
   {
      fstat(*fd,&st);
      lseek(*fd,(st.st_size)/2,SEEK_SET);
   }
   return st.st_size;
}
int main()
{
   int fd;
   long size;
   char ch;
   size=my_open("new.c",&fd);
   printf("size of file=%ld\n",size);
   read(fd,&ch,1);
   printf("Char %c\n",ch);
}
