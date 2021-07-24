
#include"header.h"

//char uid[12], patnerId[12] ;

void chat(void *p)
{
	int sockfd = *(int *)p   ;
	MSG msg , msg1;	
	char mssg[50] ;
												//CLIENT_LIST cl ;
   if(!fork())	
   {	while(1)
	{
												/*	printf("Enter ID : ");
													scanf("%[^\n]",uid);
													strcpy(cl.userId , uid);
													write();
	
													printf("Enter Friend UserId : ");
													scanf("%[^\n]",patnerId);
											*/
		printf("\n\tEnter Data:");
		scanf(" %[^\n]",mssg);
		if(strcmp(mssg, "quit\n") == 0)  
		   	//pthread_exit((void *)&x);
			exit(0) ;

		strcpy(msg.message , mssg);
		write(sockfd ,msg.message ,strlen(msg.message));
	}	
	
   }
   else
   {
	int n ;
    	while(1)
	{
		n = read(sockfd, msg1.message, 50) ;  
		if(n == 0) break ;
		write(1 , "\n\t",2);
		write(1, msg1.message, n) ;	   
	}
   }

}



int main(void)
{
	
	struct sockaddr_in  serv_addr ; 
	int sockfd   ;

	//pthread_t send;	
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	bzero((char *)&serv_addr, sizeof(serv_addr)) ;
	serv_addr.sin_family = AF_INET ;
	serv_addr.sin_port = htons(PORT) ;
	inet_aton(IP, &(serv_addr.sin_addr)) ;

	connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ;
	
	//pthread_create(&send,NULL,chat,(void*)&sockfd);
	chat(&sockfd) ;


	//pthread_join(send, (void **)&y);

	return (0);
}

