
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include"header.h"
#include<pthread.h>

//struct myMsg msg;
int cid, mfriend ;

void* sndmsg(void *p)
{
	struct myMsg msg;	
	msg.mtype = 2;
	msg.m.id = cid ;
	msg.m.fid = mfriend ;

	while(1)
	{
		int mid = *(int*)p;
			
		printf("Enter Data:");
		scanf(" %[^\n]s",msg.m.data);

		msgsnd(mid,&msg,sizeof(struct Msg),0);
	}	
}


void* rcvmsg(void *p)
{
	struct myMsg msg;

	while(1)
	{
		int mid = *(int*)p;
		msgrcv(mid,&msg,sizeof(struct Msg),cid,0);
		system("clear");
		printf("--> %s\n",msg.m.data);		
	}
	
}

main()
{
	struct myMsg msg;
	//msg.m.i = 100;
	
	printf("Enter ID:");
	scanf("%d",&cid);
	//cid = msg.m.id;
	
	printf("Enter Friend ID:");
	scanf("%d",&mfriend);
	//int friend = msg.m.fid;
	int mid = msgget(100,IPC_CREAT|0660);
	
	pthread_t send,rcv;
	pthread_create(&send,NULL,sndmsg,(void*)&mid);
	pthread_create(&rcv,NULL,rcvmsg,(void*)&mid);
	pthread_join(send,NULL);
	pthread_join(rcv,NULL);

	
	/*while(1)
	{
		
		if(!fork())
		{
			msgrcv(mid,&msg,sizeof(struct Msg),cid,0);
			system("clear");
			printf("--> %s\n",msg.m.data);
		}
		else
		{
			msg.mtype = 2;
			
			printf("Enter Data:");
			scanf(" %[^\n]s",msg.m.data);

			msgsnd(mid,&msg,sizeof(struct Msg),0);
		}
		
	}*/

}
