#include "header.h"
main() 
{
	int   n, sockfd ;  
	struct sockaddr_in  serv_addr ; 
	char    buff[50], b1[50] ;

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(6500) ;
	inet_aton("127.0.0.1", &(serv_addr.sin_addr)) ;

	connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;

	for(;;) { 	
		printf("enter line :\n") ;
		fgets(buff, 50, stdin) ;

		if(!strcmp(buff, "quit\n"))  
		   break ;
	
		write(sockfd, buff, strlen(buff)) ;
		n = read(sockfd, b1, 50) ;
		write(1, b1, n) ;
	}
	close(sockfd) ;
	exit(0) ;
}
