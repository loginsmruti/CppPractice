#include<stdio.h>

int fact(int num);

int main(void)
{
	int num;
	printf("NUMBER:: ");
	scanf("%d",&num);

	int f=fact(num);
	printf(" %d\n",f);

	return 0;
}

int fact(int num){
	if(num==1)
		return 1;
	else
		return 	num*fact(num-1);
}
