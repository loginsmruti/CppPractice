#include<stdio.h>

int check_3_digits_num(int num);

int main()
{
	int num[10];

	int count=0;
	int i;

	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}

	for( i=0;i<10;i++){
		if( check_3_digits_num(num[i]) )
			count++;
	}
	printf("%d\n",count);
}

int check_3_digits_num(int num)
{
	int count=0;
	while(num!=0){
		num/=10;
		count++;
	}

	if(count==3)
		return 1;
	else return 0;
}
