#include "header.h"
			//CLIENT
int main(void)
{
	int   n, sockfd ;  
	struct sockaddr_in  serv_addr ; 
	char    buff[30] ;

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(6500) ;

	inet_aton("127.0.0.1", &(serv_addr.sin_addr)) ;
	connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;

 	printf("enter Some Message :\n") ;
	//fgets(buff, 50, stdin) ;
	n = read(0 , buff ,30);
	
	write(sockfd, buff, n) ;

	close(sockfd) ;
	

	return (0);
}

