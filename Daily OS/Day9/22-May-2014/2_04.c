#include<stdio.h>
int main(void)
{
	int i;
	char ch;
	char word[50];

	printf("word:: ");
	scanf("%s",word);
	getchar();
	printf("Char:: ");
	scanf("%c",&ch);

	for(i=0;word[i]!='\0';i++){
		if(word[i]==ch){
			printf("position is %d\n",i+1);
		}
	}
	return 0;
}
