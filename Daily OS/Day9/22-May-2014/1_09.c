#include<stdio.h>
int main()
{
	int i;
	int j;
	int count=5;

	for(i=1;i<=count;i++){
		for(j=1;j<=i;j++){
			printf("%d ",j);
		}
		printf("\n");
	}

	return 0;
}


