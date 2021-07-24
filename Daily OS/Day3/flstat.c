#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>


long my_open(char *,int *);


long my_open(char *filename , int *point)
{
 long size;
 struct stat st ;

 *point =open(filename ,O_RDONLY);
 fstat(*point , &st);   
 size =st.st_size;
 lseek(*point ,size/2 ,SEEK_SET);

 return size;
}



int main()
{
 
  char arr[20];
  const char *filenane = "vicky";
  int k;
  long size ;
 
 size = my_open(fileName , &k);
 
 priintf("\n\t File Dptr :%d   size : %ld\n\n",k,size);
 read(k ,arr ,4);
 arr[4] ='\0';

 return (0);

}
