#include "header.h"

#define KEY 211

struct clientData
{
        char name[10];
        char num[10];
};

struct myMsg
{
        long tag;
        struct clientData c1;
};

main()
{
	system("clear");
	printf(" [server is running ]\n");
	struct clientData s;
	struct myMsg m;
	int mid1=msgget(KEY, IPC_CREAT | 0660);
	for(;;){
	msgrcv(mid1, &m, sizeof(struct clientData), -2, 0);
	struct myMsg m2;
	if(m.tag==1)
	{	m2.tag=12;
	}
	else
	{
		m2.tag=11;
	}
	printf(" %s \n",m.c1.name);
	printf(" %s \n",m.c1.num);
	//struct  myMsg m2;
	//m2.tag=2;
	m2.c1=m.c1;
	msgsnd(mid1, &m2 , sizeof(struct clientData),0);
}
}

