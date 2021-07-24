#include<stdio.h>
int main(void)
{
	int i;
	int j;
	int count=5;

	for(i=1;i<=count;i++)
	{
		for(j=1;j<=count;j++){
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
