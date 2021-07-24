#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main(int argc, char* argv[])
{
	/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~socket creation~~~~~~~~~~~~~~~~~~~~~~~*/
	int socket_fd;
	socket_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(socket_fd==-1)
	{
		printf("\n socket creation is failed. \n");
		return==-1;
	}
	/*~~~~~~~~~~~~~~~~~socket address and port number~~~~~~~~~~~~~~~~~~~*/
	struct sockaddr_in serv;

	serv.sin_family=AF_INET;
	serv.sin_port=htons(8888);
	serv.sin_addr.s_addr=hton1(INADDR_ANY);

	printf(" \n server.sin_port: %d, port no: %d",serv.sin_port, portno );
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ binding server structure to socket~~~~~~~~~~~~~~~~~~~~~~~*/

	int value =bind(socket_fd,(struct sockadd*)&serv, sizeof(serve));
	if(value==1)
	{
		printf("\n Bind failed\n");
		close(socket_fd);
		return -1;

	}
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~ server is set to listen for client~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	vlaue=listen(socket_fd, 5);
	if(value==-1)
	{
		printf(" \n Listen Failed\n");
		close(socket_fd);
		return -1;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~server now~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	int client_fd;
	int socklen_t len=0;
	client_fd=accept(socket_fd, (struct sockadd *)&serv, &len);
	if()

}
	
	
