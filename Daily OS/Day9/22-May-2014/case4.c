#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int date;
	int month;
	int year;
}DATE;

typedef struct
{

	double sum_assured;
	int ppt;
	int policy_term;
}POLICY;

typedef struct
{
	char city[50];
	char district[50];
	char state[50];
	long int pin;
}ADDRESS;

typedef struct
{
	POLICY policy_details;
	long int policy_number;
	char policy_holder[100];
	double premium_amount;
	int mode_of_payment;
	DATE date_of_commencement;
	DATE opening_date;
	DATE next_payment_date;
	ADDRESS user_address;

}ACCOUNT;


char * mode_of_payment_name[]={"Yearly","Half-Yearly","Quarterly"};


POLICY get_policy_details()
{
	POLICY policy1;

	policy1.sum_assured=200000;
	policy1.ppt=20;
	policy1.policy_term=30;

	return policy1;
}


void set_id(long int id)
{
	FILE *fp=fopen("account_id","w");
	fprintf(fp,"%ld",id);
	fclose(fp);
}

long int get_id()
{
	long int id=0;
	FILE *fp=fopen("account_id","r");
	if(fp==NULL){
		printf("First user");
		return 0;
	}
	fscanf(fp,"%ld",&id);
	return id;
}


double get_premium_amount(double premium_amount,int mode_of_payment)
{
	if(mode_of_payment==1){
		return premium_amount*1.05;
	}
	else if(mode_of_payment==2){
		return premium_amount*1.1;
	}
	else{
		return premium_amount;
	}
}

DATE get_update_date(DATE temp_date,int dd,int mm,int yy)
{
	if(temp_date.date + dd > 31 ){
		temp_date.month+=1;
	}
	temp_date.date+=dd;

	if(temp_date.month+mm > 12 ){
		temp_date.year+=1;
	}
	temp_date.month+=mm;

	temp_date.year+=yy;

	return temp_date;
}

void add_account(ACCOUNT account)
{

	FILE *fp=NULL;
	fp=fopen("accountDB","a");

	fwrite(&account,sizeof(ACCOUNT),1,fp);

	fclose(fp);
}

void show_details()
{
	long int policy_number;
	printf("\tEnter policy number : ");
	scanf("%ld",&policy_number);
	getchar();

	FILE *fp=NULL;
	fp=fopen("accountDB","r");

	ACCOUNT account;

	printf("________________________________________________________________________________________________________________\n\n");

	while( fread(&account,sizeof(ACCOUNT),1,fp)==1)
	{
		if(account.policy_number==policy_number){
		printf("\t[1] Policy number 		:: %ld\n",account.policy_number);
		printf("\t[2] Policy Holder 		:: %s\n",account.policy_holder);
		printf("\t[3] Policy Opening date 	:: %d/%d/%d \n",account.opening_date.date,account.opening_date.month,account.opening_date.year);
		printf("\t[4] Policy Commencement Date	:: %d/%d/%d \n",account.date_of_commencement.date,account.date_of_commencement.month,account.date_of_commencement.year);
		printf("\t[5] Premium amount 		:: %.2lf\n",account.premium_amount);
		printf("\t[6] Policy mode of payment  	:: %s\n",mode_of_payment_name[account.mode_of_payment]);
		printf("\t[7] Policy ppt in years	:: %d\n",account.policy_details.ppt);
		printf("\t[8] Policy terms in years 	:: %d\n",account.policy_details.policy_term);
			break;
		}
	}

	printf("________________________________________________________________________________________________________________\n\n");
	fclose(fp);
}

void show_all(int mode_of_payment)
{
	FILE *fp=NULL;
	fp=fopen("accountDB","r");

	ACCOUNT account;

	printf("\tSo under [\"%s\"] category accounts are :\n",mode_of_payment_name[mode_of_payment]);
	printf("\t_____________________________________________\n");
	printf("\tAccount Number :\t Policy Holder\n");
	printf("\t______________________________________________\n");
        while( fread(&account,sizeof(ACCOUNT),1,fp)==1)
        {
		if(account.mode_of_payment==mode_of_payment){
			printf("\t%10ld\t%20s\n",account.policy_number,account.policy_holder);
		}
        }

	printf("\t_____________________________________________\n");
	fclose(fp);
}

void take_details()
{
//	printf("take details is now invoked \n");

	set_id(get_id()+1);

	ACCOUNT account1;

	account1.policy_details=get_policy_details();
	account1.policy_number=get_id();

	char name[100];
	printf("\tEnter Policy Holder : ");
	scanf("%s",account1.policy_holder);
	getchar();

	printf("\tEnter mode of payment :\n");
	printf("\t[0] Yearly\n");
	printf("\t[1] Half Yearly\n");
	printf("\t[2] Quarterly\n");

	scanf("\t%d",&account1.mode_of_payment);
	getchar();

	account1.premium_amount=get_premium_amount(account1.policy_details.sum_assured/account1.policy_details.ppt,account1.mode_of_payment);


	DATE today;
	today.date=28;
	today.month=04;
	today.year=2014;

	account1.opening_date=today;
	account1.date_of_commencement=get_update_date(account1.opening_date,0,0,account1.policy_details.policy_term);

	int dd;
	int mm;
	int yy;

	if(account1.mode_of_payment==0){dd=0;mm=0,yy=1;}
	else if(account1.mode_of_payment==1){ dd=0;mm=6;yy=0;}
	else {dd=0;mm=4;yy=0;}
	account1.next_payment_date=get_update_date(account1.opening_date,dd,mm,yy);

	add_account(account1);
}


int main(void)
{

	system("clear");

	printf("\tVishwas Insurance pvt. limited \n");
	printf("\t.................................................\n");

	int flag=1;
	while(flag)
	{
		printf("\tChoose your option : \n");
		printf("\t[1]:\tInsert new policy_account\n");
		printf("\t[2]:\tShow all Account_details\n");
		printf("\t[3]:\tShow particular account details\n");
		printf("\t[4]:\tExit\n");
		int option,mode;
		scanf("%d",&option);
		getchar();

		switch(option)
		{
			case 1:
				take_details();
				break;
			case 2:
				printf("\tSelect Your mode:\n");
				printf("\tEnter The Mode Of category :\n");
				printf("\t[0]:\tYearly\n");
				printf("\t[1]:\tHalf Yearly\n");
				printf("\t[2]:\tQuarterly\n");

				scanf("%d",&mode);
				getchar();
				show_all(mode);

				break;
			case 3: show_details();
				break;
			case 4: flag=0;break;
			default:printf("Choose right option .\n");break;
		}
	}

	return 0;
}



