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
	printf(" jaya bachhan\n");
	int * fd= (int *)p;
 	for(;;){
        struct record rd;
        read(* fd,&rd,sizeof(rd));
        int result;
        switch(rd.op)
        {
                case 1:result=rd.num1+rd.num2; break;
                case 2:result=rd.num1-rd.num2;break;
                case 3:result=rd.num1*rd.num2;break;
                case 4:result=rd.num1/rd.num2;break;
                case 5:result=rd.num1%rd.num2;break;
                default:printf("wrong operation\n");
        }

        printf("%d   %d   %d  \n",rd.num1,rd.num2,rd.op);
        struct record rd1;

//      write(client_fd,buf, strlen(buf));
 
        rd1.op=result;

        write(*fd,&rd1,sizeof(rd1));
        }


}

int main(int argc, char* argv[])
{
	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~socket creation~~~~~~~~~~~~~~~~~~~~~~~*/
	int socket_fd;
	socket_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(socket_fd==-1)
	{
		printf("\n socket creation is failed. \n");
		return-1;
	}
	/*~~~~~~~~~~~~~~~~~socket address and port number~~~~~~~~~~~~~~~~~~~*/
	struct sockaddr_in serv_addr, client_addr;
	bzero((char* )& serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(6500);
//	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	 inet_aton("175.145.10.144", &(serv_addr.sin_addr)) ;

//	printf(" \n server.sin_port: %d",serv_addr.sin_port );
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ binding server structure to socket~~~~~~~~~~~~~~~~~~~~~~~*/

	int value =bind(socket_fd,(struct sockaddr * )&serv_addr, sizeof(serv_addr));
	if(value==1)
	{
		printf("\n Bind failed\n");
		close(socket_fd);
		return -1;

	}
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~ server is set to listen for client~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	value=listen(socket_fd, 5);
	if(value==-1)
	{
		printf(" \n Listen Failed\n");
		close(socket_fd);
		return -1;
	}


	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~server now~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	  pthread_t thread1;

	for(;;){
	printf("  tin  tin \n");
	int client_fd;
	int len=sizeof(client_addr);
	client_fd=accept(socket_fd, (struct sockaddr *)&client_addr, &len);
	if(client_fd==-1)
	{
		printf(" \n accept failed\n");
		close(socket_fd);
		return -1;
	}
//	char buf[20];

//	int n=	read(client_fd, buf, 20);
//	buf[n]='\0';
//	printf("%s \n ", buf);
//	pthread_t thread1;
	pthread_create(&thread1, NULL, th, (void *)& client_fd);

//	pthread_join(thread1, NULL);
	close(client_fd);
	
	}
	pthread_join(thread1, NULL);

	close(socket_fd);
	
	return 0;

}


