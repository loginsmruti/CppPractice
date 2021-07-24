#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;

void print_line(char ch)
{
	printf("\n");
	int i=0;
	for(;i<120;i++){
		printf("%c",ch);
	}
	printf("\n");
}

struct doj
{
	int date;
	int month;
	int year;
};

struct emp
{
	int id;
	char name[100];
	struct doj emp_doj;
	float basic;
	float da;
	float hra;
	float cca;
	float net_sal;
};

void set_id(int id,int num)
{
        FILE *fp=fopen("id","w");
        fprintf(fp,"%d",id);
	fprintf(fp,"%c",' ');
	fprintf(fp,"%d",num);

        fclose(fp);
}

void set_num(int num)
{
	int id;
	FILE *fp=fopen("id","w");
        fprintf(fp,"%d",id);
        fprintf(fp,"%c",' ');
        fprintf(fp,"%d",num);
        fclose(fp);
}

int get_id()
{
        int id,num;
        FILE *fp;
	if( (fp=fopen("id","r") ) == NULL ){
		return 0;
	}
	char ch;
        fscanf(fp,"%d",&id);
	fscanf(fp,"%c",&ch);
	fscanf(fp,"%d",&num);

	fclose(fp);
        return id;
}

int get_num()
{
        int id,num;
        FILE *fp=NULL;
        if( (fp=fopen("id","r") ) == NULL ){
                return 0;
        }
	char ch;
        fscanf(fp,"%d",&id);
	fscanf(fp,"%c",&ch);
        fscanf(fp,"%d",&num);

	fclose(fp);

        return num;
}

void other_salary(float basic,float * da,float * hra,float * cca,float * net_sal)
{
        *da=basic*0.6;
        *hra=*da*.3;
        *cca=basic*.5;
        *net_sal=basic+*da+*hra+*cca;
}

struct emp show_details(char * name)
{
	print_line('~');
	FILE * fp=NULL;
	if( (fp=fopen("db","r"))==NULL ){
		printf("File db cannot be opened\n");
		exit(4);
	}

	struct emp temp;
	int i=0;
	while(i< get_id()){
		fread(&temp,sizeof(struct emp),1,fp);
		if(strcmp(temp.name,name)==0){
			break;
		}
	}
	fclose(fp);

	printf("Name       :: %s \n",temp.name);
	printf("Basic sal  :: %.2f \n",temp.basic);
	printf("DA  sal    :: %.2f \n",temp.da);
	printf("HRA sal    :: %.2f\n",temp.hra);
	printf("CCA sal    :: %.2f\n",temp.cca);
	printf("NET sal	   :: %.2f\n",temp.net_sal);
	printf("DOJ is     :: %2d/%2d/%4d\n",temp.emp_doj.date,temp.emp_doj.month,temp.emp_doj.year);
	print_line('~');

	return temp;
}

void update_record(struct emp temp)
{
	FILE *fp=NULL;

	if ( (fp=fopen("db","r+"))==NULL )
	{
		printf("The db file is not opened\n");
		exit(6);
	}

	int i=0;
	while(i < get_id() )
	{
		struct emp temp1;
		long int pos=ftell(fp);
		fread(&temp1,sizeof(struct emp),1,fp);
		if(temp1.id==temp.id){
			fseek(fp,pos,SEEK_SET);
			fwrite(&temp,sizeof(struct emp),1,fp);
			break;
		}
		i++;
	}
	fclose(fp);
}

void user_update_details()
{
	struct emp temp;
	char option;

	printf("Enter emp name  :");
	scanf("%s",temp.name);
	getchar();

	printf("..........................................................................\n");
	temp=show_details(temp.name);

	printf("You want to update details y/n::");
	scanf("%c",&option);
	getchar();

	if(option=='n'){
		printf("OK leave deletion \n");
		return ;
	}

	printf("Enter Basic salary :: ");
	scanf("%f",&temp.basic);
	other_salary(temp.basic,&temp.da,&temp.hra,&temp.cca,&temp.net_sal);

	update_record(temp);
}
//.......................................................................

//not used method saved for future reference
void show_delete_record(long int pos)
{
	FILE *fp=NULL;
	fp=fopen("db","r+");

        fseek(fp,pos,SEEK_SET);
	struct emp temp;
	fread(&temp,sizeof(struct emp),1,fp);
	printf("Name is :%s\n",temp.name);

	while(pos <= ((get_id()-1)*sizeof(struct emp) ) ){
		fseek(fp,pos,SEEK_SET);

		struct emp temp;
		fread(&temp,sizeof(struct emp),1,fp);
		fseek(fp,pos-sizeof(struct emp),SEEK_SET);
		fwrite(&temp,sizeof(struct emp),1,fp);
		pos=pos+sizeof(struct emp);
	}
	set_id(get_id(),get_num()-1);
	fclose(fp);
}

//..............................................................................
void delete_record()
{
	printf("Enter the emp name:");
	char name[100];
	scanf("%s",name);
	getchar();

	FILE *fp=NULL;
	if( (fp=fopen("db","r+"))==NULL  ){
		printf("File can't be opened\n");
		exit(7);
	}

	int i=0;
	long int pos;
	while(i < get_id() ){
		struct emp temp;
		fread(&temp,sizeof(struct emp),1,fp);
		if(strcmp(temp.name,name)==0){
			pos=ftell(fp);
			fseek(fp,pos-sizeof(struct emp),SEEK_SET);
			temp.id=-1;
			fwrite(&temp,sizeof(struct emp),1,fp);
			break;
		}
		i++;
	}
	set_id(get_id(),get_num()-1);

	fclose(fp);
}

struct emp * take_input()
{
	set_id(get_id()+1,get_num()+1);
	struct emp * temp_emp=(struct emp *) malloc(sizeof(struct emp));

	temp_emp->id=get_id();

	printf("Enter name       ::");
	scanf("%s",temp_emp->name);
	getchar();
	printf("Enter Basic      ::");
	scanf("%f", &(temp_emp->basic) );
	getchar();

	struct doj temp_doj;

	while(1){
		printf("Enter DD Of DOJ :: ");
		scanf("%d",&(temp_emp->emp_doj).date);
		if( (temp_emp->emp_doj).date >0 && (temp_emp->emp_doj).date <=31 ){
			break;
		}else{
			printf("Date should be [1-31] ");
		}
	}
	getchar();

	while(1){
		printf("Enter MM of doj  ::");
		scanf("%d",&(temp_emp->emp_doj).month);
		if(  (temp_emp->emp_doj).month > 0 && ( temp_emp->emp_doj).month <=12 ){
			break;
		}else{
			printf("Month should be [1-12]");
		}
	}
	getchar();

	while(1){
		printf("Enter YY of doj  ::");
		scanf("%d",&(temp_emp->emp_doj).year);
		if( ( temp_emp->emp_doj).year >1947 && (temp_emp->emp_doj).year < 2015 ){
			break;
		}
		else{
			printf("Year should be less than [2015]");
		}
	}
	getchar();

	other_salary(temp_emp->basic,&temp_emp->da,&temp_emp->hra,&temp_emp->cca,&temp_emp->net_sal);
	return temp_emp;
}

void message()
{
	printf("# JAY KANT KUMAR :\n");
	printf("# 26 april 2014  :\n");
	printf("# CASE STUDY 03  :\n");
	printf("# create an application capables to store employee details,add new employee, update and delete existing employee details:\n");
}

void display()
{
	FILE * fp=NULL;
	if( (fp=fopen("db","r"))==NULL ){
		printf("File db.txt is not openable :: ERROR\n");
		exit(0);
	}
	print_line('_');
	int j=0;
        printf("EMPID    NAME    	 BASIC            DA              HRA              CCA          NETSAL            DOJ\n");
	printf("_______________________________________________________________________________________________________________________\n\n");

	char coll[10];

	while(j< get_id()){
		struct emp temp;
		fread(&temp,sizeof(struct emp),1,fp);
		if(temp.id!=-1){

			if(temp.id<10) strcpy(coll,"EMP00");
			else if(temp.id<100) strcpy(coll,"EMP0");
			else strcpy(coll,"EMP");

			struct doj temp_doj=temp.emp_doj;
			printf("%s%-3d  %-15s %-7.2f 	%-7.2f 	%-7.2f 	%-7.2f 	%-7.2f 	%2d/%2d/%4d\n",coll,temp.id,temp.name,temp.basic,temp.da,temp.hra,temp.cca,temp.net_sal,temp_doj.date,temp_doj.month,temp_doj.year);
		}
		j++;
	}
	printf("________________________________________________________________________________________________________________________\n");

	fclose(fp);
}

void add(struct emp * temp_emp)
{
	FILE *fp=NULL;
	if(  (fp=fopen("db","a"))==NULL )
	{
		printf("File db.txt is not openable :: ERROR \n");
		exit(0);
	}
	else{
	}

	if(fwrite(temp_emp,sizeof(struct emp),1,fp)==1){
	}else{
		printf("Record is not saved \n");
	}
	fclose(fp);
}

void user_interface()
{
	struct emp * emp1=NULL;
	int flag=1;
	int id;
	char name[100];
	while(flag)
	{
	        printf("\nSelect Option for processing :\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("[1] Show all employee details::\n");
		printf("[2] Add a new employee details :\n");
		printf("[3] Delete an existing details:\n");
		printf("[4] Show a particular employee details:\n");
		printf("[5] Update an existing employee details:\n");
		printf("[6] Exit from program:\n");
		printf("_________________________________________________\n");
        	int option;
	        scanf("%d",&option);
		getchar();

		switch(option)
		{
			case 1:
				display();
				break;
			case 2:
				emp1=take_input();
				add(emp1);
				break;
			case 3:
				delete_record();
				break;
			case 4:
				printf("Enter name ::");
				scanf("%s",name);
				show_details(name);
				break;
			case 5:
				printf("User Details ::\n");
				user_update_details();
				break;
			case 6:
				flag=0;
				break;
			default:
				break;
		}
	}
}

int main(void)
{
	system("clear");
	message();

	user_interface();
	return 0;
}
