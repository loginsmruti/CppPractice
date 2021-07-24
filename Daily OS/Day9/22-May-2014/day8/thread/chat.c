#include "header.h"

#define KEY 211

int me;
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

void * th1(void *p)
{
	struct myMsg m;
	int mid1=msgget(KEY, IPC_CREAT| 0660);
	for(;;){
	msgrcv(mid1, &m, sizeof(struct clientData), 10+me, 0);

	printf(" %s\n",m.c1.name);
	printf(" %s\n", m.c1.num);
	}
}


main(int argc, char* argv[])

{

	system("clear");
	me=atoi(argv[1]);
	 int mid1=msgget(KEY, IPC_CREAT| 0660);

	 pthread_t thread_th1;

	printf(" [CLIENT 1 IS PROCESSING ]\n");
	pthread_create(&thread_th1, NULL, th1, NULL);
	// create thread
	for(;;)
{	struct clientData thread1;
	printf("WELCOME , START WRITING \n");
	scanf("%s", thread1.name);
	getchar();
	scanf("%s", thread1.num);
	getchar();


	//pthread_t thread_th1;
//	pthread_t thread_th2;
//	pthread_create(&thread_th1, NULL, th1, (void*)&thread1);

	   struct myMsg m1;
        m1.tag=me;
        m1.c1=thread1;
 //       int mid1=msgget(KEY, IPC_CREAT| 0660);
        msgsnd(mid1,&m1,sizeof(struct clientData),0 );
}
}


