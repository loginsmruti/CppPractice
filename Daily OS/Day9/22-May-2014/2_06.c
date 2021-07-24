#include<stdio.h>

int u_strlen(char * word);
int palindrome(char * word);

int main(void)
{
	char word[100];

	printf("Word::\n");
	scanf("%s",word);

	palindrome(word) ? printf("Palindrome\n")  : printf("Not a palindrome\n");

	return 0;
}

int palindrome(char * word)
{
	int i=0;
	int flag=1;

	for(;i < u_strlen(word)/2; i++){
		if( word[i] !=	word[u_strlen(word)-1-i] ){
			flag=0;
			break;
		}
	}

	return flag;
}


int u_strlen(char * word)
{
	int len=0;
	while(*word != '\0') { len++; word++;}
	return len;
}
