#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include"header.h"

int main()
{
	int sock_fd;
	struct sockaddr_in serv_addr;
        sock_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //create socket...
	bzero((char * )& serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET ;
        serv_addr.sin_port = htons(6500) ;
        inet_aton("127.0.0.1", &(serv_addr.sin_addr));
        char buf[1024];
	connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        perror("con");
        for(;;){
	int num1;
	int num2;
	int num3;
        printf("Enter first number : ");scanf("%d",&num1);getchar();
	printf("Enter second number : ");scanf("%d",&num2);getchar();
        printf("Enter operation symbol: ");
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
        write(sock_fd,&rd,sizeof(rd));
        struct record rd1;
        read(sock_fd,&rd1,sizeof(rd1));
        printf("send messagen : %d\n",rd1.op);
	}
	close(sock_fd);
	exit(0);

}
