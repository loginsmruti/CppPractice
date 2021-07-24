
#include <sys/types.h>          /*  */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define IP "127.0.0.1"
#define PORT 6500


typedef struct Msg
{
	char message[80];
}MSG;

struct connected_clients
{
	char userId[12];
}CLIENT_LIST;
