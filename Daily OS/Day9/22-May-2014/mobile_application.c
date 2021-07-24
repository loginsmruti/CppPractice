#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

 /* declaration the structure....................*/

struct list
{
	char mob_num[20];
	char Firstname[80];
	char Lastname[80];
	char mail_id[60];
};
int add_data_in_file(struct list);
int validate_mail_id(char * mail_id);
int validate_mob_num(char * mob_num);
int number_data_file();
void sorting_data_mob();


void sorting_data_mob()
{
	FILE *fp=fopen("db","r+");
	if(fp==NULL)
	{
		printf("File opening is problem");
	}
	struct list data1;
	struct list data2;
	struct list data3;
	int total=number_data_file();
	int i,j,temp;
	for(i=0;i<total-1;i++)
	{
		rewind(fp);
		for(j=0;j<total-1-i;j++)
		{
			int pos1=ftell(fp);
			fread(&data1,sizeof(data1),1,fp);
			int pos2=ftell(fp);
			fread(&data2,sizeof(data2),1,fp);

			if(strcmp(data1.mob_num, data2.mob_num) > 0 )
			{
				fseek(fp,pos1,SEEK_SET);
				fwrite(&data2,sizeof(data2),1,fp);
				fseek(fp,pos2,SEEK_SET);
				fwrite(&data1,sizeof(data1),1,fp);
			}
			fseek(fp,pos2,SEEK_SET);
		}
	}
	fclose(fp);
}

int number_data_file()
{
	FILE *fp=fopen("db","r");
	if(fp==NULL)
	{
		printf("File opening problem");
		exit(4);
	}
	int total=0;
	struct list temp;
	while( fread(&temp,sizeof(temp),1,fp)==1)
	{
		total++;
	}
	fclose(fp);
	return total;
	
}


int add_data_in_file(struct list user_details)
{
	FILE *fp=fopen("db","a");
	if(fp==NULL)
	{
		printf("File opening is problem ");
	}
	fwrite(&user_details,sizeof(user_details),1,fp);
	fclose(fp);
	return 1;
}


int validate_mob_num(char *  mob_num)
{
	int flag=0;
	 int len=strlen(mob_num);

       	 if((len==10)&&(mob_num[0]=='9') &&((mob_num[1]=='8') || (mob_num[1]==1) || (mob_num[1]==2)))
                                {
                                        flag=1;
				}
			return  flag;


/*
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
*/

}

int validate_mail_id(char * mail_id)
{
	int  i, pos1=0;
	int  pos2=0;
	int apersand_flag=0;
	int space_flag=0;
	int dot_flag=0;
	for(i=0; i<strlen(mail_id);i++)
	{
		if(mail_id[i]=='@') 
		{
			apersand_flag=1;
			pos1=i;
		}
		else if(mail_id[i]==' ')
		{
			space_flag=1;
		}
		else if(mail_id[i]=='.')
		{
			dot_flag=1;
			pos2=i;

		}

//		printf("%d  %d %d %d ",space_flag, apersand_flag , dot_flag,pos1, pos2);


	}

//  printf("%d  %d %d %d %d ",space_flag, apersand_flag , dot_flag,pos1, pos2);

	if((space_flag==0) &&(apersand_flag==1)&&(dot_flag==1)&&(pos1<pos2))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void insert(struct list b)
{
	int value=0;
	while(value==0)
	{
		printf("Enter the mob_num :");
		scanf("%s",b.mob_num);
		getchar();
		 value=validate_mob_num(b.mob_num);
	}

	printf("Enter the first name :");
	scanf("%s",b.Firstname);
	getchar();
	printf("Enter the last name :");
	scanf("%s",b.Lastname);
	getchar();

	int value1=0;
	while(value1==0)
	{
		printf("Enter the mail_id :");
		scanf("%s",b.mail_id);
		getchar();
		value1=validate_mail_id(b.mail_id);
	}

	add_data_in_file(b);
}
void display()
{
	FILE *fp=fopen("db","r");
	struct list temp;

	while(fread(&temp,sizeof(temp),1,fp)  ==1)
	{
		printf("%s\n ",temp.mob_num);
		printf("%s\n",temp.Firstname);
		printf("%s\n",temp.Lastname);
		printf("%s\n",temp.mail_id);
		
	}
	fclose(fp);
}

main()
{
//	for checking the validation function is working or not........
//	int var=validate_mail_id("bcoolpreety@gmail.com");
//	printf("show thw result is %d ",var);
	struct list b;
	int flag=1;
	while(flag)
	{
		printf("Enter your choice :\n" );
		printf("\t\t\t[1] : Insert \n");
		printf("\t\t\t[2] : Dispaly \n");
		printf("\t\t\t[3] : Sorted data \n");
		printf("\t\t\t[4] : Exit \n");
		int choice;
		scanf("%d", &choice);
		getchar();
		printf("**************************************************\n");	
	
		switch (choice)
		{
			case 1:
				insert(b);
				break;
			case 2:
				display(b);
				break;
			case 3:
				sorting_data_mob();
				break;
			case 4:
				flag=0;
				break;
			default:
				break;
		}
	}
	
}

