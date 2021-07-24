#include "header.h"
				//SERVER
int main(void)
{
	int n ,sockfd , finsockfd , size ;
	struct sockaddr_in serv_addr , client_addr ;
	char buff[30] ; 	
	
	sockfd = socket(AF_INET ,SOCK_STREAM , IPPROTO_TCP);
	perror("Error Code At socket:");
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(6500) ;
	serv_addr.sin_addr.s_addr = //htonl (INADDR_ANY) ;
inet_aton(IP, &(serv_addr.sin_addr)) ;

	bind(sockfd ,(struct sockaddr*)&serv_addr ,sizeof(serv_addr));
	perror("Error Code At Bind:");
	listen(sockfd, 5) ;
	perror("Error Code At Listen:");

	size = sizeof(client_addr) ;
	finsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &size) ;
	
	perror("Error Code At accept:");
	n = read(finsockfd, buff, 50) ;	
	if(n == 0) {
	  write(1 , "\n\t N = ",6);
	 // write(1 , n , 4);
	}
	else
		write(1 , buff ,n);


	printf("\nSERVER :: connection closed for present client\n") ;	
	close(finsockfd);
	close(sockfd);
  
 return (0);
}

