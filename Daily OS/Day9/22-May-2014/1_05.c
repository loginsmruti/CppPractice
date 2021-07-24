#include<stdio.h>

int main(void)
{
	char ch;
	int count=0;

	int i;

	for(i=1;i<=5;i++){
		scanf("%c",&ch);
		getchar();
                if( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch =='u' ){
                        count++;
                }
	}

	printf("%d\n",count);
	return 0;
}
