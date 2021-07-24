#include<stdio.h>
int main(void)
{
	int a;
	int b;
	int c;
	printf("1 num:: ");
	scanf("%d",&a);
	printf("2 num:: ");
	scanf("%d",&b);
	printf("3 num:: ");
	scanf("%d",&c);

	int min=a;
	if(min < b && min < c)printf("min is a :: %d",a);
	else if (b < min && b < c) printf("min is b :: %d",b);
	else printf("min is c :: %d",b);
	return 0;
}
