#include<stdio.h>
int main(void)
{

	int i;
	int j;
	int k;

	int count=9;

	for(i=0;i<count;i++){

		for(j=1;j <= count-i;j++){
			printf("%d ",j);
		}

		for(j=0;j < 2*i-1;j++){
			printf("  ");
		}

		if(i==0){

			for(k=count-1;k > 0;k--){
				printf("%d ",k);
			}
		}
		else{
			for(k=count-i;k > 0 ;k--){
				printf("%d ",k);
			}
		}

		printf("\n");
	}
	return 0;
}
