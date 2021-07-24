#include<stdio.h>
int u_strlen(char * word);
void u_charAt(char * word,int i);

int main(void)
{
	char word[50];
	int i;

	printf("word:: ");
	scanf("%s",word);
	printf("Index::");
	scanf("%d",&i);

	u_charAt(word,i);
	return 0;
}

int u_strlen(char * word)
{
	int len=0;
	while(*word!='\0'){
		len++;
		word++;
	}
	return len;
}

void u_charAt(char *word,int i)
{
	if( i < u_strlen(word) ) printf("%c\n",word[i]);
	else printf("NO\n");
}

