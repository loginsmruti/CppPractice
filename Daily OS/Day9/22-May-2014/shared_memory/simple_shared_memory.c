#include<stdio.h>
#include<string.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<sys/ipc.h>
#include<sys/shm.h>

#define KEY 101

struct record
{
	int roll;
	char name[40];
};

void user_interface(struct record * initial_ptr,int *total);
struct record take_details();
void show(struct record * initial_ptr,int total);
void add(struct record * initial_ptr,int total,struct record rd);
void modify(struct record * initial_ptr,int total);
void copy_to_shared_memory(struct record * initial_ptr,int * total);
void copy_to_file(struct record * initial_ptr,int total);

int main()
{
	system("clear");

	int shmid=shmget(KEY,1000,IPC_CREAT|0660);
	struct record * shmptr=shmat(shmid,0,0);

	int total=0;

	copy_to_shared_memory(shmptr,&total);

	printf("so total is : %d \n",total);

	user_interface(shmptr,&total);

	copy_to_file(shmptr,total);

	printf("so it's copy to file .\n");
	shmdt(shmptr);
	return 0;
}

void user_interface(struct record * initial_ptr,int *total)
{
	int flag=1;
	int option;
	printf("\tshared memeory problem solution. [ya allah jan lega tera isq.]\n");
	while(flag)
	{
		printf("\tAvailable options .[1,2,3,4] \n");
		printf("\t[1] add new details .\n");
		printf("\t[2] modify details.\n");
		printf("\t[3] show new details.\n");
		printf("\t[4] exit.\n");

		printf("\tYour selection : ");
		scanf("%d",&option);
		getchar();

		switch(option)
		{
			case 1:
				add(initial_ptr,*total,take_details());
				*total=*total+1;
			        break;
			case 2:
				modify(initial_ptr,*total);
				break;
			case 3:
				show(initial_ptr,*total);
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("[what happened sexy ] select na correct one.\n");
				break;
		}
	}
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
	int count=0;
	while(count < total){
		initial_ptr+=sizeof(struct record);
		count++;
	}

	memcpy(initial_ptr,&rd,sizeof(struct record));

	printf("\t[data is written..]\n");
}

void modify(struct record * initial_ptr,int total)
{
	int roll;
	printf("\t [Enter Your ROll NUMBER ] :");
	scanf("%d",&roll);
	getchar();

	int count=0;
	struct record rd;
	int flag=0;
	while(count < total)
	{
		memcpy(&rd,initial_ptr,sizeof(struct record));
		if(rd.roll==roll){
			flag=1;
			printf("\t[Enter YOUR NICE NAME ]:");
			scanf("%[^\n]s",rd.name);
			getchar();
			memcpy(initial_ptr,&rd,sizeof(struct record));
			break;
		}
		initial_ptr+=sizeof(struct record);
		count++;
	}
	if(flag==0){
		printf("\t[Your selection is not present.]\n");
	}
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
                read_ptr+=sizeof(struct record);
                count+=1;
        }
	printf("\n\tmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
}

void copy_to_shared_memory(struct record * initial_ptr, int * total)
{
	int fd=open("db",O_CREAT | O_RDONLY , S_IRUSR | S_IWUSR );
	struct record rd;
	int count=0;

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

		initial_ptr+=sizeof(struct record);
		count++;
	}

	close(fd);
}
