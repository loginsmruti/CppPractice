#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>

#define KEY 2019
#define MSG_KEY 2020

/*-------------------------- structure defintion ---------------------------*/
struct record
{
	int roll;
	char name[40];
};

struct send_record
{
	int type;
	struct record msg;
};
/*--------------------------- function prototype ----------------------------*/
int user_interface(int msg_id,struct record * initial_ptr,int *total);
struct record take_details();
void show(struct record * initial_ptr,int total);
int perform_action(struct record * initial_ptr,int * total,struct send_record sd);
void add(struct record * initial_ptr,int total,struct record rd);
int modify(struct record * initial_ptr,int total,struct record rd);
void copy_to_shared_memory(struct record * initial_ptr,int * total);
void copy_to_file(struct record * initial_ptr,int total);
/*---------------------------- main execution starts here ----------------------*/

int main()
{
	system("clear");

	/*------------------------- get shared memory ---------------------------------*/
	int shmid=shmget(KEY,10000,IPC_CREAT|0660);
	struct record * shmptr=shmat(shmid,0,0);
	/*-------------------------- get message queue -------------------------------*/
	int msg_id=msgget(MSG_KEY,IPC_CREAT|0660);
	int total=0;

	int pid=fork();
	/*-----------------------parent process acts like manager --------------------*/
	if(pid)
	{
		copy_to_shared_memory(shmptr,&total);
		printf("So Number of records of file was :[%d] in manager.\n",total);
		/*----------------send total number to user process --------------*/
		struct send_record sd;
		sd.type=4;
		sd.msg.roll=total;
		msgsnd(msg_id,&sd,sizeof(struct record),0);
		printf("so : %d \n",sd.msg.roll);

		for(;;)
		{
			/*------------------ receiving message from user ----------------------*/
			struct send_record sd;
			msgrcv(msg_id,&sd,sizeof(struct record),-3,0);
			int value;
			value=perform_action(shmptr,&total,sd);

			struct send_record sd1;
			sd1.type=5;
			sd1.msg.roll=value;
			msgsnd(msg_id,&sd1,sizeof(struct record),0);

			if(value==2)break;
		}
	}
	/*------------------child process acts like user -----------------------------------*/
	else
	{
	/*---------------- receive total number of file from manager...........*/
		struct send_record sd;
		msgrcv(msg_id,&sd,sizeof(struct record),4,0);

		total=sd.msg.roll;
		printf("So Number of records of file was :[%d] in user. \n",total);
		int value;
		for(;;)
		{
			/*--------------user interface -------------------------*/
			if ( user_interface(msg_id,shmptr,&total) ==0) break;
		}
	}
	printf("so it's copy to file .\n");
	/*---------------- de attached shared memory ------------------------*/
	shmdt(shmptr);
	msgctl(msg_id,IPC_RMID,0);

	return 0;
}

int perform_action(struct record * initial_ptr,int * total,struct send_record sd)
{
	printf("so message received is :%s\n ",sd.msg.name);

	int flag=-1;
	int option=sd.type;
	printf("so option is requested by user [%d]\n",sd.type);
	switch(option)
	{
		case 1:
			if(*total < 10) {
			add(initial_ptr,*total,sd.msg);
//			printf("so---------------------total is :%d .........\n",*total);
			*total=*total+1;
			}
			else{
			flag=0;
			}
			break;
		case 2:
			flag=modify(initial_ptr,*total,sd.msg);
			break;
		case 3:
			copy_to_file(initial_ptr,*total);
			flag=2;
			break;
	}
	return flag;
}


int user_interface(int msg_id,struct record * initial_ptr,int *total)
{
	int flag=1;
	int option;
	printf("\t[shared memeory problem solution.]\n");

		printf("\tAvailable options .[1,2,3,4] \n");
		printf("\t[1] add new details .\n");
		printf("\t[2] modify details.\n");
		printf("\t[3] show new details.\n");
		printf("\t[4] exit.\n");

		printf("\tYour selection : ");
		scanf("%d",&option);
		getchar();

		struct record rd;
		struct send_record sd;

		int value;
		switch(option)
		{
			case 1:
				/*----------------- add new  record -------------------------*/
				rd=take_details();
				sd.type=1;
				sd.msg=rd;
				/*------------------- message is sent to manager ----------------*/
				msgsnd(msg_id,&sd,sizeof(struct record),0);
				printf("message is send to manager to add new record .[2] \n");
				*total=*total+1;

				value=msgrcv(msg_id,&sd,sizeof(struct record),5,0);
				if(value) printf("success\n");
				else printf("failure\n");
			        break;
			case 2:
				rd=take_details();
				sd.type=2;
				sd.msg=rd;
				msgsnd(msg_id,&sd,sizeof(struct record),0);

				value=msgrcv(msg_id,&sd,sizeof(struct record),5,0);
				if(value) printf("success\n");
				else
					printf("failure\n");
				break;
			case 3:
				show(initial_ptr,*total);
				break;
			case 4:
				rd.roll=-1;
				sd.type=3;
				sd.msg=rd;
				msgsnd(msg_id,&sd,sizeof(struct record),0);

				value=msgrcv(msg_id,&sd,sizeof(struct record),5,0);
				if(value==2) printf("existed success.\n");
				flag=0;
				break;
			default:
				printf("[select correct option.]\n");
				break;

		}
	return flag;
}

struct record take_details()
{
	struct record rd;
	printf("\tEnter Your ROLL NUMBER :");scanf("%d",&rd.roll);getchar();
	printf("\tEnter Your NICE   NAME :");scanf("%[^\n]s",rd.name);getchar();
	return rd;
}

void add(struct record * initial_ptr,int total,struct record rd)
{
printf("so [%s] will be added at pos [%d] \n",rd.name,total);

	int count=0;
	initial_ptr += total ;
	//while(count < total){
	//	initial_ptr+=sizeof(struct record);
	//	count++;
	//}
	memcpy(initial_ptr,&rd,sizeof(struct record));
//	printf("\t[data is written..]\n");
}

int modify(struct record * initial_ptr,int total,struct record rd)
{

//	printf("------------------- so modified data is :%d   %s  and total is %d \n",rd.roll,rd.name,total);

	int count=0;
	struct record temp;
	int flag=0;
	while(count < total)
	{
//		printf("++++++++++++++++++++++++++\n");

		memcpy(&temp,initial_ptr,sizeof(struct record));
//		printf("---> %d %s\n",temp.roll,temp.name);
		if(temp.roll==rd.roll){
//			printf("--------------------->>>>>>>>>>>>>>>> found .........at [%d]",count);
			flag=1;
			strcpy(temp.name,rd.name);
			memcpy(initial_ptr,&temp,sizeof(struct record));
			break;
		}
		initial_ptr++ ;//=sizeof(struct record);
		count++;
	}
	if(flag==0){
		printf("\t[Your selection is not present.]\n");
	}
	return flag;
}

void show(struct record * initial_ptr,int total)
{
	printf("\n\tmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
	printf("\t\t  ROLL \t        Name \n");
	printf("\t-----------------------------------------------------------------\n");
 	struct record * read_ptr=initial_ptr;
        int count=0;
        while(count < total)
        {
                struct record rd2;
                memcpy(&rd2,read_ptr,sizeof(struct record));
                printf("\t\t%5d\t\t%s\n",rd2.roll,rd2.name);
                read_ptr++ ;//=sizeof(struct record);
                count+=1;
        }
	printf("\n\tmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
}

void copy_to_shared_memory(struct record * initial_ptr, int * total)
{
	int fd=open("db",O_CREAT | O_RDONLY , S_IRUSR | S_IWUSR );
	struct record rd;
	int count=0;


	//struct fstat st ;
	//fstat(fd, &st) ;
	read(fd, initial_ptr, (*total)*sizeof(struct record)) ;
	while ( read (fd,&rd, sizeof(struct record) ) ){
		add(initial_ptr,count,rd);
		count++;
	}
	*total=count;
	close(fd);
}

void copy_to_file(struct record * initial_ptr,int total)
{
	int fd=open("db",O_WRONLY );
	int count=0;
	struct record rd;
	while(count < total )
	{
		printf("so added to file .\n");
		memcpy(&rd,initial_ptr,sizeof(struct record) );
		write(fd,&rd,sizeof(struct record) );

		initial_ptr++ ;//=sizeof(struct record);
		count++;
	}
	close(fd);
}
