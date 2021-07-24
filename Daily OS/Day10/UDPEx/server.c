
#include"header.h"

int main()
{
  int sock_fd,size ,chk ;
  struct sockaddr_in serv,client;
  sock_fd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
  if(sock_fd==-1)
  {
      printf("Socket Creation Problem...\n");
  close(sock_fd);
      return -1;
  }
  bzero((char *)&serv,sizeof(serv));
  serv.sin_family = AF_INET ;
  serv.sin_port = htons(PORTNO) ;
  serv.sin_addr.s_addr=htonl(INADDR_ANY);
  if( (bind(sock_fd,(struct sockaddr *)&serv, sizeof(serv))) == 1 )
  {
        		perror(" Binding : ");
               close(sock_fd);
		return -1;
  }
  size=sizeof(client);
  for(;;)
  {
  	char buff[100];
        int rec = recvfrom(sock_fd,buff,sizeof(buff),0,(struct sockaddr*)&client, (socklen_t *)&size);
  	perror("rec");
        if(rec==-1)
  	{
     		printf("No Data Rec from client.....");
  	}
  	else
  	{
     		buff[rec]='\0';
  	        printf("Recv Bytes: %d Msg : %s\n",rec,buff);
                chk = sendto(sock_fd,buff,strlen(buff),0,(struct sockaddr*)&client,sizeof(client));
		if(chk==-1)
	  	{
	      		printf("Unable to send Data\n");
	      		return -1;
	  	}
        }
  }
  close(sock_fd);
  return 0;
}
