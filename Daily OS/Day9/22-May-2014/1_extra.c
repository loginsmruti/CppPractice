#include<stdio.h>

int main()
{
	int i;
	int j;
	int k;

	int count=5;

	for(i=1;i <= count;i++)
	{
		for(j=1;j<=count-i;j++){
			printf("  ");
		}

		for(j=1;j<=i;j++){
			printf("%d ",j);
		}

		for(j=i-1;j>0;j--){
			printf("%d ",j);
		}

		printf("\n");
	}

	return 0;
}
