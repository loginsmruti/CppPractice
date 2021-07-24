#include<stdio.h>

int main(void)
{
	int arr[3][3]={	{10,20,30} , {40,50,60}, {70,80,90} };

	int row[3];
	int column[3];
	int sum=0;

	int i,j;

	for(i=0;i<3;i++)
	{
		sum=0;
		for(j=0;j<3;j++){
			sum+=arr[i][j];
		}
		row[i]=sum;

		sum=0;
		for(j=0;j<3;j++){
			sum+=arr[j][i];
		}

		column[i]=sum;
	}

	printf("ROW ::\t ");
	int sum1=0;
	for(i=0;i<3;i++){
		sum1+=row[i];
		printf("%d\t",row[i]);
	}

	int sum2=0;
	printf("\nCOL ::\t");
	for(j=0;j<3;j++){
		sum2+=column[j];
		printf("%d\t",column[j]);
	}

	printf("\nSum Row :: %d",sum1);
	printf("\nSum Col :: %d",sum2);

	printf("\n");
	return 0;
}



