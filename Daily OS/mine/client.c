#include "file.h"

			
int main(void)
{
	int fd1 , n ;
	char buffer[30];
	mkfifo("printer",S_IWUSR |S_IRUSR);	
	fd1 = open("printer",O_RDWR);
	perror("success");

	printf("\n\t Enter File Name : "); 
	scanf("%s",p.fileName);
 	getchar();
	printf("\n\t Enter Toggle Flag As (1/0) : ");
	scanf("%hd",&p.flag);
 	getchar();

	printf("\n\t Enter Start Byte value :");
	scanf("%d",&p.startByte);
 	getchar();
	
	printf("\n\t Enter Total Bytes to be extracted :");
	scanf("%d",&p.totalBytes);
 	//printf("%s	%hd	%d	%d ",p.fileName,p.flag,p.startByte,p.totalBytes);
 	
	write(fd1 , &p ,sizeof(p));

	n = read(fd1 ,buffer , 5);
	buffer[n] = '\0' ;

	printf("\n\t %d  Server Response is : %s",n,buffer);

 return (0);

}
