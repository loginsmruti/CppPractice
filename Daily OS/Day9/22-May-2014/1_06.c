#include<stdio.h>

int u_pow(int a,int b);

int main()
{
	int a;
	int b;

	scanf("%d",&a);
	scanf("%d",&b);

	int p=u_pow(a,b);
	printf("%d\n",p);

	return 0;
}

int u_pow(int a,int b)
{
	int i;
	int mul=1;
	for(i=1;i<=b;i++){
		mul*=a;
	}

	return mul;
}
