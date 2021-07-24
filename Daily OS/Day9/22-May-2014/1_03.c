#include<stdio.h>

int main()
{
	int num[10];

	int count=0;
	int i;

	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}

	for( i=0;i<10;i++){
		if( num[i] > 50 )
			count++;
	}
	printf("%d\n",count);
}

