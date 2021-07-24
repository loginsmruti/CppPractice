#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<pthread.h>
#include"header.h"


void *th(void * p)
{
	int fd= *(int *)p;
 	for(;;){
        struct record rd;
        read(fd,&rd,sizeof(rd));
        int result;
        switch(rd.op)
        {
                case 1:result=rd.num1+rd.num2;break;
                case 2:result=rd.num1-rd.num2;break;
                case 3:result=rd.num1*rd.num2;break;
                case 4:result=rd.num1/rd.num2;break;
                case 5:result=rd.num1%rd.num2;break;
                default:printf("wrong operation\n");
        }
        printf("%d   %d   %d  \n",rd.num1,rd.num2,rd.op);
        struct record rd1;
        rd1.op=result;
        write(fd,&rd1,sizeof(rd1));
        }
	
}

int main()
{
	int socket_fd;
	socket_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
       	struct sockaddr_in serv_addr, client_addr;
	bzero((char* )& serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(6500);
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
        bind(socket_fd,(struct sockaddr * )&serv_addr, sizeof(serv_addr));
	listen(socket_fd, 5);
	pthread_t thread1;
        for(;;)
        {
	   int client_fd;
	   int len=sizeof(client_addr);
	   client_fd=accept(socket_fd, (struct sockaddr *)&client_addr, &len);
           perror("accept");
           pthread_create(&thread1, NULL, th, (void *)&client_fd);
           perror("accept");
           
	}
	return 0;
}


