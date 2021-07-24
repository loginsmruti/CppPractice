#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define ROW 4
#define COLUMN 5

//...........................................................................................................

struct person
{
	char  name[100];
	int age;
	float weight; //kg
	float height; //cm
};

char * category[]=
			{
				"Under Weight","Healthy weight","Over weight","Obese"
		        };

char * type_of_food [] ={  "Grain", "Vegetable","Fruit","Liquid" };

struct item
{
	int type;
	char *name;
	float price;
	int calories;
};

//...........................................................................................................

struct item * STORE[ROW][COLUMN];
int cart_items_list[ROW*COLUMN];

//...........................................................................................................

struct person input();
void show(struct person );
float bmi(float height,float weight);
int classify(float bmi);
int required_calories(int category);
int printLine(char ch);
void message();
void coder_details();
struct item * createNewItem(int f_type, char * name , float price , int calories );
int addNewItem(struct item * newItem);
int showItems(int f_type);
int add_item_to_list();
int show_all_items();
int  number_of_items_present(int f_type);
void assign(int i,int j,struct item *newItem);

float addItems_to_basket(int calories);
void addItems_to_basket_for_price(float price);
void show_items_to_basket();
void show_items_of_basket();
void user_interface();
void assign_default_values_to_count_of_items();

//.....................................................................................................

int main()
{

	system("clear");
	system("date");

/*	coder_details();
	printLine('-');
	message();
	printLine('-');

	struct person person1=input();
	printLine('-');

	show(person1);
	printLine('-');

	float person1_bmi=bmi(person1.height,person1.weight);
	printf("BMI   :: %.2f\n",person1_bmi);
//	printLine('-');

	int person1_category=classify(person1_bmi);
	printf("Category :: %s\n",category[person1_category]);
//	printLine('-');

	int calories=required_calories(person1_category);
	printf("Required Calories is :: %d\n",calories);
//	printLine('-');

*/
//0 g
//1 v
//2 f
//3 l

	addNewItem(createNewItem(2,"apple",180,52));
	addNewItem(createNewItem(2,"banana",60,89));

	addNewItem(createNewItem(1,"cabbage",50,25));
	addNewItem(createNewItem(1,"onion",30,40));
	addNewItem(createNewItem(1,"cauliflower",60,31));
	addNewItem(createNewItem(1,"carrot",70.50,41));
	addNewItem(createNewItem(1,"potato",30,25));

	addNewItem(createNewItem(2,"grapes",190.50,69));
	addNewItem(createNewItem(2,"orange",90.60,47));
	addNewItem(createNewItem(2,"lemon",70.30,29));


	addNewItem(createNewItem(3,"Orange Juice",20,39));
	addNewItem(createNewItem(3,"Apple Juice",40,117));
	addNewItem(createNewItem(3,"Grape Juice",60.89,154));
	addNewItem(createNewItem(3,"Pineapple juice",40,132));
	addNewItem(createNewItem(3,"SugarCane juice",50,120));

	addNewItem(createNewItem(0,"Rice",60,111));
	addNewItem(createNewItem(0,"Wheat",80,127));
	addNewItem(createNewItem(0,"Pulse",120,120));
	addNewItem(createNewItem(0,"Rajma",130,150));
	addNewItem(createNewItem(0,"Bread",70,103));

/*	addItems_to_basket(calories);
//	show_items_to_basket();
	show_items_of_basket();
	printLine('*');
//	show_all_items();
*/
	user_interface();

	printf("\n");
	return 0;

}

void user_interface()
{
	message();
	printLine('~');

	int option;
	struct person person1;
	float person1_bmi;
	int person1_category;
	int calories=required_calories(person1_category);
	float price;
	float total_price;

	int flag=1;
	while(flag)
	{
		int flag2=0;
		printf("Enter Option ::\n");
		printf("1 :: Input your Details ::\n");
		printf("2 :: show Calculated values::\n");
		printf("3 :: display recommended food list::\n");
		printf("4 :: display food list for particular price ::\n");
		printf("5 :: Exit::\n");

		printLine('~');

		scanf("%d",&option);
		getchar();

		switch(option)
		{
			int flag2=0;

			printLine('~');
			case 1:
				if(1){

				printLine('~');
				person1=input();
				person1_bmi=bmi(person1.height,person1.weight);
				person1_category=classify(person1_bmi);
				calories=required_calories(person1_category);

				flag2=1;
				}

				break;
			case 2:
				if(flag2==1){

				printLine('~');
//				show(person1);
				printf("Your BMI  value is   :: %.2f\n",person1_bmi);
				printf("Your body Category   :: %s\n",category[person1_category]);
				printf("Required Calories is :: %d\n",calories);
				printLine('~');

				}
				else{
					printf("First You have to enter Your details\n");
				}
				break;
			case 3:
//				printLine('^');

				if(flag2==1){

				total_price=addItems_to_basket(calories);
				show_items_of_basket();
				printLine('*');
				printf("The total price of foods is :: %.2f\n",total_price);
				printLine('*');

				}
				else{
					printf("First You have to enter Your Details \n");
				}
				break;
			case 4:
				printLine('~');
				if(flag2==1){

				printf("Enter The Price :: \n");
				scanf("%f",&price);
				getchar();
				addItems_to_basket_for_price(price);
				show_items_of_basket();
				//printf("This facility is not active now \n");

				}
				else{
					printf("First you have to enter your details\n");
				}
				printLine('~');
				break;
			case 5:
				printLine('~');
				printf("Exiting from Program\n");
				printLine('~');
				flag=0;
				break;
			default:
				printLine('~');
				printf("Your input option is not recoganised\n");
				printLine('~');
				break;
		}

	}
}


void show_items_of_basket()
{
	printLine('^');
	printf("Here is recommended food list ::\n");

	int i=0;
	printf("\tName\t   Category\tPrice\tCalories\tUnit\n");
	printLine('-');
	for(;i<ROW*COLUMN;i++){
		if(cart_items_list[i]!=0){
			struct item * Item=STORE[	i / COLUMN ][ i % COLUMN ];
			printf("%15s	%10s	%3.2f	   %3d	        %3d\n",Item->name,type_of_food[Item->type],Item->price,Item->calories,cart_items_list[i]);
		}
	}
}

void show_items_to_basket()
{
	int i=0;
	for(;i<ROW*COLUMN;i++){
		printf("%d ",cart_items_list[i]);
	}
}

float addItems_to_basket(int required_calories)
{
//	printf("The required calories is %d \n",required_calories);

	assign_default_values_to_count_of_items();

	int temp_calories=0;
	float required_price=0;

	int flag=1;
	while(flag)
	{
		int i=0;
		int j=0;

//		int temp_calories=0;

		for(;i<COLUMN;i++){
			for(j=0;j<ROW;j++){
//			printf("The current calories is %d\n",temp_calories);
				if(temp_calories+STORE[j][i]->calories < required_calories ){
					temp_calories+=STORE[j][i]->calories;
					required_price+=STORE[j][i]->price;
					cart_items_list[ COLUMN*j + i ]+=1;
				}else{
					flag=0;
					break;
				}
			}
		}

	}
	return required_price;

}

void addItems_to_basket_for_price( float price )
{
      assign_default_values_to_count_of_items();

      printf("The required calories is %.2f \n",price);
        float temp_price=0;
        int flag=1;

        while(flag)
        {
                int i=0;
                int j=0;

//              int temp_calories=0;

                for(;i<COLUMN;i++){
                        for(j=0;j<ROW;j++){
                        printf("The current calories is %.2f\n",temp_price);
                                if(temp_price + STORE[j][i]->price < price ){
                                        temp_price+=STORE[j][i]->price;
                                        cart_items_list[ COLUMN*j + i ]+=1;
                                }else{
                                        flag=0;
                                        break;
                                }
                        }
                }

        }

}

void assign_default_values()
{
	int i=0;
	int j=0;
	for(;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			STORE[i][j]=NULL;
		}
	}

}

void assign_default_values_to_count_of_items()
{
	int i=0;
	for(;i<ROW*COLUMN;i++){
		cart_items_list[i]=0;
	}
}

int show_all_items()
{
	showItems(0);
	showItems(1);
	showItems(2);
	showItems(3);
}

int add_item_to_list()
{

	char name[50];
	float price;
	int calories;
	int type;

	printf("Enter Item type :: \n");
	printf("FRUITS :: 1,	GRAINS:: 2,	LIQUID:: 3,	VEGETABLES:: 4\n");
	scanf("%d",&type);

	getchar();

	printf("Enter Item name ::\n");
	gets(name);

	printf("Enter Item price::\n");
	scanf("%f",&price);

	printf("Enter item calories::\n");
	scanf("%d",&calories);

	printf( " ::   %s  %d 	    %f    %d::\n",name,type,price,calories);

	addNewItem ( createNewItem(type-1,name,price,calories) );


	return 1;
}

int showItems(int f_type)
{
	int i=0;
	for(; i < COLUMN && STORE[f_type][i] != NULL ; i++){
		printLine('~');

			printf("TYPE is :: %s\n",type_of_food[ STORE[f_type][i]->type]);
			printf("Name is :: %s\n",STORE[f_type][i]->name);
			printf("Price is:: %.2f\n",STORE[f_type][i]->price);
			printf("Calories is :: %d\n",STORE[f_type][i]->calories);
			printf("Ratio is :: %.2f\n",STORE[f_type][i]->calories/STORE[f_type][i]->price);
	}

	return 1;
}

//....................................................................................................

int addNewItem(struct item * newItem)
{
	int index_of_pre_items=number_of_items_present(newItem->type);
//	printf("Number of previous elements is : %d \n",index_of_pre_items);
	int j;

	int flag=1;

	if(index_of_pre_items <=  COLUMN-1 )
	{
		if(STORE[newItem->type][0]==NULL) {
			STORE[newItem->type][0]=newItem;
			return 1;
		}

		int i=0;

		for(;i<COLUMN && flag;i++)
		{
			if(STORE[newItem->type][i]==NULL) { STORE[newItem->type][i]=newItem; flag=0; break;}

			struct item * tempItem= STORE[newItem->type][i];

			if( tempItem->calories/tempItem->price  < newItem->calories/newItem->price ){
				assign(i,index_of_pre_items,newItem);
				STORE[newItem->type][i]=newItem;
				break;
			}

		}


		return 1;
	}else{
		return 0;
	}

}

void assign(int i,int index_of_pre_items,struct item * newItem)
{
	int j=0;
	for(j=index_of_pre_items-1;j>=i;j--){
		STORE[newItem->type][j+1]=STORE[newItem->type][j];
	}
}

int number_of_items_present(int f_type)
{
	int i=0;
	for(; i<COLUMN && STORE[f_type][i]!=NULL ; i++);
	return i;
}

//....................................................................................................

struct item * createNewItem(int f_type, char * f_name, float f_price, int f_calories )
{

	struct item * newItem=(struct item *) malloc(sizeof(struct item ));
	newItem->type=f_type;
	newItem->name=f_name;
	newItem->price=f_price;
	newItem->calories=f_calories;

	return newItem;
}


//....................................................................................................

void coder_details()
{
	printf("coder# jay kant kumar\n");
	printf("file # case_study.c\n");
	printf("doc  # case_study.txt\n");
}

void message()
{

	printf("   		MODERN SHOPPER STOP \n");
	printf("------------------------------------------------------------\n");
	printf(" 	FIRST YOU HAVE TO PROVIDE YOUR DETAILS \n");
	printf("     SYSTEM CALCULATE BODY MASS INDEX (BMI) \n");
	printf("AFTER THAT YOU WILL GET APPROPRIATE FOODS WITHIN YOUR RANGE\n");
}

int printLine(char ch)
{
	int i=0;
	for(;i<80;i++){
		printf("%c",ch);
	}
	printf("\n");

	return ;
}

int required_calories(int category)
{
	if(category==0) return 2500;
	else if(category==1) return 2300;
	else if(category==2) return 2200;
	else if(category==3) return 2100;
}

int classify(float bmi)
{

	if(bmi < 18.5  ) return 0;
	else if ( bmi > 18.5 && bmi < 24.9 ) return 1;
	else if ( bmi > 25 && bmi < 29.4 ) return 2;
	else return 3;
}



//....................................................................................................


float bmi(float height,float weight)
{
	return   (float)( weight / pow( (height/100), 2) );
}

//....................................................................................................

struct person  input()
{
	struct person p;
	printf("Name	  	   :: ");
	gets(p.name);
	printf("Age [year]         :: ");
	scanf("%d",&p.age);
	printf("Weight [Kilogram]  :: ");
	scanf("%f",&p.weight);
	printf("Height [Centimeter]:: ");
	scanf("%f",&p.height);

	printLine('~');
	return p;
}

//.....................................................................................................

void show(struct person p)
{
	printf("Name   ::%s\n",p.name);
	printf("Age    ::%d\n",p.age);
	printf("Weight ::%.2f\n",p.weight);
	printf("Height ::%.2f\n",p.height);
}

//.....................................................................................................
