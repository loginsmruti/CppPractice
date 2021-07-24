#include "header.h"

#define KEY 100

struct user_data
{
	char name[40];
	char num[40];
};
struct user_data user_inpt();
void add_data(struct user_data * shm_ptr, int *a_total);
void modify_data(struct user_data * shm_ptr, int total);
void display_data(struct user_data *shm_ptr, int total);

void modify_data(struct user_data * shm_ptr, int total)
{
	char num[10];
	printf("Enter number to modify:" );
	scanf("%s", num);
	getchar();
	struct user_data temp;
	int count=0;
	int flag=0;
	while(count< total)
	{
		memcpy(&temp, shm_ptr, sizeof(struct user_data));
		if(temp.num==num)
		{
			printf("Enter name u wanna modify \n");
			scanf("%s", temp.name);
			memcpy(shm_ptr, & temp, sizeof(struct user_data));
			break;
		}
		shm_ptr++;
		count++;

	}
	if (flag==0)
	{
		printf(" DATA is not present\n");
	}
}	




void display_data(struct user_data *shm_ptr, int total)
{
	int count=0;
	struct user_data *new_ptr=shm_ptr;
	printf("your no:     your name\n" );
	while(count<total)
	{
		struct user_data temp;
		memcpy(&temp, new_ptr, sizeof(struct user_data));
		printf(" %s\t %s\n", temp.name, temp.num);
		new_ptr++;
		count+=1;
	}
	printf(" END OF UR DATA    END OF UR DATA      END OF UR DATA\n");
	printf(" SMILE  PLEASE\n");


}

void add_data(struct user_data * shm_ptr , int *a_total)
{
	int count=0;
	struct user_data var1;
	struct user_data *new_ptr=shm_ptr;
	while(count<*a_total)
	{
		count++;

	}
	 var1=user_inpt();
	 memcpy(new_ptr, &var1,sizeof(struct user_data) );
	*a_total=*a_total+1;


}
struct user_data user_inpt()
{
	struct user_data temp;
	printf("Enter string :");
	scanf("%s", temp.name);
	getchar();
	printf("Enter string :");
	scanf("%s", temp.num);
	getchar();
	printf("=======================================\n");
	return (temp);
}
main()
{
	system("clear");
	int shm_id=shmget(KEY, 10*sizeof(struct user_data), IPC_CREAT | 0660);
	void *shm_ptr=shmat(shm_id, 0, 0);

	struct user_data *new_ptr=shm_ptr;
	int total=0;

	int option;
	int flag=1;
	while(flag==1)
	{
		printf("[Enter ur option]\n");
		printf("\t\t 1: Add_data\n");
		printf("\t\t 2: modify data\n");
		printf("\t\t 3: display data\n");
		printf("\t\t 4: exit\n");
		printf("_____________________________________\n");
		scanf("%d", &option);
		getchar();
		printf("______________________________________\n");

		switch (option)
		{
			case 1:
				add_data(shm_ptr, &total);
				break;
			case 2:
				modify_data(shm_ptr, total);
				break;

			case 3:
				display_data(shm_ptr,total);
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
	}
}
