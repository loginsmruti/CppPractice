#include<pthread.h>
#include<stdio.h>
#include<string.h>
 struct thread
{
        int num;
        char name[10];
};

void * th1(void *p)
{
	sleep(5);
	printf(" m in second thread \n");
}

void * th(void *p)
{
	struct thread *q=(struct thread *)p;
	sleep(3);
	printf(" m in thread \n");
	printf(" in thread , pid : %d\n",getpid() );
	printf(" value of i %d\n",q->num );
	printf(" name %s\n ", q->name);
}

main()
{

	struct thread var1;
	var1.num=1;
	strcpy(var1.name, " jay");

	pthread_t test_th;
	pthread_t test_th1;
	pthread_create(&test_th, NULL, th, (void*)&var1);
	pthread_create(&test_th1, NULL, th1,NULL);
	printf(" in main , pid : %d \n", getpid());
	pthread_join(test_th1,NULL);
	pthread_join(test_th, NULL);
	printf(",..........\n");
}
