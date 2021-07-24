#include "header.h"

int sockfd ;

void *client()
{
	char    buff[50] , b1[50];
	int   n;  
	for(;;) { 	
		printf("enter line :\n") ;
		fgets(buff, 50, stdin) ;

		//if(strcmp(buff, "quit\n") == 0)  
		  // break ;
	
		write(sockfd, buff, strlen(buff)) ;
		n = read(sockfd, b1, 50) ;
		write(1, b1, n) ;
	}
}


main() 
{

	struct sockaddr_in  serv_addr ; 

	
	pthread_t t1 ;
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(PORT) ;
	inet_aton(IP, &(serv_addr.sin_addr)) ;

	connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;


	 pthread_create(&t1 , 0 ,client ,NULL ); 
	 
	 pthread_join(t1 , NULL);

	 close(sockfd) ;

	exit(0) ;
}


