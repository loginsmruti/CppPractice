
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include"header.h"

main()
{
	struct myMsg msg;
	while(1)
	{
		int mid = msgget(100,IPC_CREAT|0660);
		printf("\tGarena Server Started\n");
		msgrcv(mid,&msg,sizeof(struct Msg),2,0);
		
		printf("Read Data from Client to server-- i : %d, data : %s, id : %d, fid = %d\n",msg.m.i,msg.m.data,msg.m.id,msg.m.fid);
	
		printf("Writing message q via server\n");

		msg.mtype = msg.m.fid;
		msgsnd(mid,&msg,sizeof(struct Msg),0);
	}
}

