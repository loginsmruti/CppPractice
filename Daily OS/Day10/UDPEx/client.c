
#include"header.h"

int main()
{
  int sock_fd , ret;
  struct sockaddr_in serv,client;
  char buff[100],buff1[100];
  sock_fd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
  if(sock_fd==-1)
  {
      printf("Socket Creation Problem...\n");
      return -1;
  }
  bzero((char *)&serv,sizeof(serv));
  serv.sin_family = AF_INET ;
  serv.sin_port = htons(PORTNO) ;
  ret = inet_aton("127.0.0.1", &(serv.sin_addr));
  if(ret == 0)
  {
      printf("Address Is Not Valid...\n");
      return 0;
  }
  bzero((char *)&client,sizeof(client));
  client.sin_family = AF_INET ;
  client.sin_port = htons(0);
  ret = inet_aton("127.0.0.1", &(client.sin_addr));
  if(ret == 0)
  {
      printf("Address Is Not Valid...\n");
      return 0;
  }
  if((bind(sock_fd,(struct sockaddr * )&client, sizeof(client))) == -1)
  {
    		perror(" ABinding : ");
		close(sock_fd);
		return -1;
  }
  for(;;)
  {
  	printf("\n Enter String :\n");
        scanf(" %[^\n]",buff);
        int chk= sendto(sock_fd,buff,strlen(buff),0,(struct sockaddr*)&serv,sizeof(serv));
  	if(chk==-1)
  	{
      		printf("Unable to send Data\n");
      		close(sock_fd);
      		return -1;
  	}
        else
        {
             int rec =recvfrom(sock_fd,buff1,sizeof(buff1),0,(struct sockaddr*)&serv,(void *)sizeof(serv));
             buff1[rec]='\0';
             printf("Message from Server :%s ",buff1);
        }
   }
   close(sock_fd);
   return 0;
}
