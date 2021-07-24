
#include"header.h"

void *server(void *p)
{
	MSG  m2 ;
	char buff[50];
	int n , x = 1 ;
	int finsockfd1 = *(int *)(p) ;
	int finsockfd2 = *(((int *)p)+1) ;


	for(;;) 
	{ 	
			//Suggested User Id's To Clients
			
			
			//Read Messages From Client

			n = read(finsockfd1, m2.message, 50) ; 
			if(n == 0)
				pthread_exit((void *)&x);
			printf("\n *%s* \n",m2.message); 				//strcmp(buff , "exit"));
			
			if(strncmp(buff , "no",2) == 0) {
				printf("SERVER :: connection closed for present client\n") ;	
				close(finsockfd1);
				close(finsockfd2);
				pthread_exit((void *)&x);	
			} 
			//Write Messages To Client
			//printf("\n\tserv wroting to %d :: %s\n", finsockfd2, m2.message) ;
			 write(finsockfd2, m2.message , n) ; 
	}
}


int main(void)
{
	int   n , sockfd , size , y , address1[2] , address2[2] ,finsockfd1 , finsockfd2 ;  
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

  		finsockfd1 = accept(sockfd, (struct sockaddr *)&cli_addr, &size) ;
		finsockfd2 = accept(sockfd, (struct sockaddr *)&cli_addr, &size) ;
		
		address1[0] = finsockfd1 ;
		address1[1] = finsockfd2 ;
		address2[0] = finsockfd2 ;
		address2[1] = finsockfd1 ;

		pthread_create(&t2 , 0 ,server ,(void *)address1 );   
		pthread_create(&t2 , 0 ,server ,(void *)address2 );   
	}

	 pthread_join(t2 , (void **)&y);

 return (0);
}

