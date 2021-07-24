#include "header.h"


void *server(void *p)
{
	MSG m2 ;
	char buff[50];
	int finsockfd , n , x = 1 ;
	finsockfd = *(int *)p ;
	//struct sockaddr_in cli_addr ;

	for(;;) 
	{ 	
			n = read(finsockfd, m2.message , 50) ; m2.message[n] = '\0' ;
			printf("\n *%s* \n",m2.message); //strcmp(buff , "exit"));
			
			if(n == 0)
			 break;	
			if(strncmp(m2.message , "no",2) == 0) {
				printf("SERVER :: connection closed for present client\n") ;	
				close(finsockfd);
				pthread_exit((void *)&x);	
			} 
			 write(finsockfd, m2.message , n) ; 	
	}
}

int main(void) 
{
	int  finsockfd , sockfd , size , y;  
	struct sockaddr_in  serv_addr, cli_addr ; 

	pthread_t t2;

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(PORT) ;
	serv_addr.sin_addr.s_addr = htonl (INADDR_ANY) ;

	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;
	listen(sockfd, 5) ;
	size = sizeof(cli_addr) ;

	for( ; ; )
	{
  		finsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &size) ;
		pthread_create(&t2 , 0 ,server ,(void *)&finsockfd );   
	}

	 pthread_join(t2 , (void **)&y);

	return (0);
}


