#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#include"header.h"

int main(int argc, char * argv[])
{
	int sock_fd;
	struct sockaddr_in serv_addr;

	 sock_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bzero((char * )& serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET ;
        serv_addr.sin_port = htons(6500) ;
         inet_aton("175.145.10.144", &(serv_addr.sin_addr)) ;


	char buf[1024];
	connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	for(;;){
	int num1;
	int num2;
	int num3;

	printf("Enter first number : ");scanf("%d",&num1);getchar();
	printf("Enter second number : ");scanf("%d",&num2);getchar();
//	printf("Enter operation code: ");scanf("%d",&num3);getchar();

	printf("Enter opetion symbol:");
	char ch;
	scanf("%c",&ch);
	getchar();

	switch(ch)
	{
		case '+':num3=1;break;
		case '-':num3=2;break;
		case '*':num3=3;break;
		case '/':num3=4;break;
		case '%':num3=5;break;
	}

	struct record rd;
	rd.num1=num1;
	rd.num2=num2;
	rd.op=num3;

//	scanf("%[^\n]s",buf);
//	getchar();

//	write(sock_fd, buf, strlen(buf)+1);
	write(sock_fd,&rd,sizeof(rd));

//	char b1[50];
	struct record rd1;
//	int n	=read(sock_fd, b1, 50);

//	b1[n]='\0';

	read(sock_fd,&rd1,sizeof(rd1));

	printf("send messagen : %d\n",rd1.op);
	}
	close(sock_fd);
	exit(0);

}
