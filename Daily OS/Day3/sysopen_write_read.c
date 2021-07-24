#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
#include<fcntl.h>


int main()
{
 char str[100] ="Fourthline...";
 int k ,d, i ,count ;
 char x ;
 k = open("vicky",O_CREAT|O_APPEND|O_WRONLY,S_IRUSR|S_IWUSR);
 
 if(k == -1)
 {
  printf("\n\tThere is something problem in file  .....\n");
 }
 else
  {
    count = 0 ;
    while(str[count] != '\0') {
     i = write(k , &str[count] ,1);
     count++;
    }
    if(i > 0 )
      printf("\n\t File Writing Successful....\n");
  }
  close(k);

 d = open("vicky",O_RDONLY);
 if(d == -1)
 {
  printf("\n\tThere is something problem in file  .....\n");
 }
 else
 {
   while(read(d , &x ,1))
     printf("%c",x);
 }
 printf("\n");
 
  close(d);

 return (0);
}


