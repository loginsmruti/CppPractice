#include<stdio.h>
int main(void)
{
	char word[50];
	printf("Word:: ");
	scanf("%s",word);

	int i;

	for(i=0;word[i]!='\0';i++){
		if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
			printf("The position of vowel %c is :: %d\n ",word[i],i+1);
	}

	return 0;
}


