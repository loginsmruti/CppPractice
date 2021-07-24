#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define THERSHOLD 200

void show(int * store,int num);
int exact_match(int * store,int num,int required_len);
int cut_cloth(int  * store,int num,int required_len);

int main(void)
{
	system("clear");

	int store[10];
	int num;
	printf("\tEnter number of yan[cloth bundle]:");
	scanf("%d",&num);
	getchar();

	int i=0;
	for(;i<num;i++){
		printf("\tEnter length of cloth [meter] in [%d] yan :",i+1);
		scanf("%d",&store[i]);
	}

	int ch=1;
	int flag=1;

	while(ch)
	{

		printf("______________________________________________________________\n");
		printf(" \tSelect your option:\n");
		printf(" \t[1] show present status of yans \n");
		printf(" \t[2] sell colth \n");
		printf(" \t[3] Exit\n");

		int option;
		scanf("\t\t%d",&option);

		int index;
		int required_len;
		switch(option)
		{
		case 1:
			show(store,num);
			break;

		case 2: printf("\tEnter The length of cloth :");
		        scanf("%d",&required_len);

			if( (index=exact_match(store,num,required_len) )!=-1){
//				printf("\tSell is done from [%d] YAN \n",index+1);
				printf("\tSell is done\n");
			}
			else if(index=cut_cloth(store,num,required_len)!=-1){
//				printf("\tSell is done from [%d] YAN \n",index+1);
				printf("\tSell is done\n");
			}
			else{
				printf("\tRequired length is not present:\n");
			}
			break;

		case 3:flag=0;break;
	}

	printf("\t........................................................\n");
	if(flag==0) break;
	printf("\tYou want to continue [1 : continue /0: no] :");
	scanf("%d",&ch);
	getchar();
}
	return 0;
}

int exact_match(int * store,int num,int required_length)
{
	int flag=-1;
	int i =0;

	for(;i<num ;i++){
		if(store[i]==required_length && store[i]!=0){
			store[i]=0;
			flag=i;
			break;
		}
	}

	return flag;
}

int cut_cloth(int * store,int num,int required_length)
{
	int j=0;
	int flag=-1;
	for(;j<num;j++ ){
			if( store[j] > required_length && store[j]!=0 ){
				store[j]=store[j]-required_length;
				flag=j;
				break;
			}
	}

	return flag;
}

void show(int * store,int num)
{
	printf("\t___________________________________\n");
	printf("\tNow length of yans are :\n");
	int i=0;
	for(;i<num;i++){
		printf("\t[%d] \t   %d\n",i+1,store[i]);
	}
	printf("\t___________________________________\n");
}


