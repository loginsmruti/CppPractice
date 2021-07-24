#include<stdio.h>

int main()
{
	int num[10];

	int count=0;
	int i;

	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}

	int max=num[0];
	for( i=1;i<10;i++){
		if( max < num[i] )
			max=num[i];
	}

	int min=num[0];
	for(i=1;i<10;i++){
		if(min > num[i]){
			min=num[i];
		}
	}

	printf("Max:: %d\n",max);
	printf("Min:: %d\n",min);

	return 0;
}

