#include "udpheader.h"

struct sockaddr_in serv_addr , client_addr;

void *server(void *p)
{
	MSG m2 ;
	char buff[50] ;
	int sockfd , rcvbytes , sentbytes , x = 1 , size ;
	sockfd = *(int *)p ;
	size = sizeof(client_addr);

	for(;;) 
	{ 	
			rcvbytes = recvfrom(sockfd, &m2.message , 50 ,0 , (struct sockaddr *)&client_addr,&size ) ; 
			
			if(rcvbytes == -1)
			{
			 	printf("\n unable to receive from    client");
			 	break;	
			}
			if(strncmp(m2.message , "no",2) == 0) {
				printf("SERVER :: connection closed for present client\n") ;	
				close(sockfd);
				pthread_exit((void *)&x);	
			} 
			if ((sentbytes = sendto(sockfd, &m2.message, strlen(m2.message), 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr))) == -1)
   			{
				printf("\n unable to send  from client");
				close(sockfd);
  			}	
	}
}

int main(void) 
{
	int  finsockfd , sockfd , size , y;  

	pthread_t t2;

	if( (sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		perror("Sockett Creation : ");
	}
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(PORT) ;
	serv_addr.sin_addr.s_addr = htonl (INADDR_ANY) ;

	if((bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) == -1)
	{
		perror(" Binding : ");
		close(sockfd);
		return -1;
	}

	for( ; ; )
	{
  	
		pthread_create(&t2 , 0 ,server ,(void *)&sockfd );   
	}

	 pthread_join(t2 , (void **)&y);

	return (0);
}


