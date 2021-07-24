#include<stdio.h>

int u_strlen(char * word)
{
	int len=0;
	while(*word!='\0')
	{
		len++;
		word++;
	}
	return len;
}

int main(void)
{
	char word[50];
	printf("Word:: ");
	scanf("%s",word);

	int i=0;
	char temp;
	for(i;i<u_strlen(word)/2;i++){
		temp=word[i];
		word[i]=word[u_strlen(word)-1-i];
		word[u_strlen(word)-1-i]=temp;
	}
	word[u_strlen(word)]='\0';

	printf("%s\n",word);

	return 0;
}


