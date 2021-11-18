#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#define MAXBUF 10

char buff[MAXBUF];
int main()
{
 int buf ;
 int ret , fd ;
 fd = open("example.txt", O_RDONLY); 
 ret = read(fd , buff , MAXBUF );
 printf("%d , %d , %s " , fd , ret , buff);
 exit(0);
 return 0 ; 
}
