#include "header.h"

main() 
{
	int   n, sockfd, finsockfd, size ;  
	struct sockaddr_in  serv_addr, cli_addr ; 
	char    buff[50];

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(6500) ;
	serv_addr.sin_addr.s_addr = htonl (INADDR_ANY) ;

	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;
	listen(sockfd, 5) ;

	size = sizeof(cli_addr) ;
	for(;;) 
	{ 	
		finsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &size) ;
	    if(!fork()) 
	    {
		close(sockfd) ; // child process – does not require socket fd
		for(;;) {	
			n = read(finsockfd, buff, 50) ;
			if(n == 0)	
				break ;

			write(finsockfd, buff, n) ; 
	         }
		printf("SERVER :: connection closed for present client\n") ;
		exit(0) ;  
	     }
	close(finsockfd) ; 	
	}  
}
