#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>


long myopen(char *fname,int *fd)
   {
   struct stat st;
   *fd=open(fname,O_RDONLY);
   fstat(*fd,&st);
  long sz=st.st_size;
  lseek(*fd,sz/2,SEEK_SET);
  return sz;
  }

int main()
{
  int fd;
   char arr[50];
   long fsize=myopen("new",&fd);
    printf("%d %ld\n",fd,fsize);
    read(fd,arr,4);
     arr[4]='\0';
     printf("arr=%s\n",arr);
 return 0;
}

