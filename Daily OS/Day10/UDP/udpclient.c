#include "udpheader.h"

struct sockaddr_in serv_addr , client_addr; 

void *client(void *p)
{
	MSG m , m1;
	int sockfd1 = *(int *)p , x = 5 ,sockfd  ; 
	char    buff[50] , b1[50];
	int   rcvbytes , sentbytes ;  

	for(;;) 
	{ 	
		printf("enter line :\n") ;
		fgets(buff, 50, stdin) ;
		strcpy(m.message , buff);

		if(strcmp(buff, "quit\n") == 0)  
		   	pthread_exit((void *)&x);
	
			if((sentbytes = sendto(sockfd1, &m.message, strlen(m.message), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) == -1)
   			{
				printf("\n unable to send  from client");
				close(sockfd1);
  			}
			rcvbytes = recvfrom(sockfd1, &m1.message , strlen(m1.message) ,0 ,(struct sockaddr *)&client_addr ,(int *)0 ) ; 

			write(1, m1.message, rcvbytes) ;
	 }
}


int main(void) 
{

	int sockfd , y;
	//pthread_t t1 ;

	if(  (sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1 )
	{
		perror("Socket Creation : ");
		return -1;
	}
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(PORT) ;
	if(inet_aton(IP, &(serv_addr.sin_addr)) == 0)
	{
		perror("inet_aton :");
		exit(EXIT_FAILURE);
	}
	
	bzero((char *)&client_addr , sizeof(serv_addr)) ;
	client_addr.sin_family = AF_INET ;
	client_addr.sin_port = htons(1024) ;
	if(inet_aton(IP, &(client_addr.sin_addr)) == 0)
	{
		perror("inet_aton :");
		exit(EXIT_FAILURE);
	}	
	
	if((bind(sockfd, (struct sockaddr *)&client_addr, sizeof(serv_addr))) == -1)
	{
		perror(" Binding : ");
		close(sockfd);
		return -1;
	}

	//pthread_create(&t1 , 0 ,client ,(void *)&sockfd ); 
	client(&sockfd) ;
	 
	//pthread_join(t1 , (void **)&y);

	close(sockfd) ;

	return (0);	
}


