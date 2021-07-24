#include<stdio.h>
int u_strlen(char *word);

int main(void)
{
	char word[3][30]=
		{
			"MANGO","APPLE","BANANA"
		};

	int i=0;
	int j=0;
	char temp;
	for(;i<3;i++){
		for(j=0;j<u_strlen(word[i])/2;j++){
			temp=word[i][j];
			word[i][j]=word[i][ u_strlen(word[i]) -1-j ];
			word[i][ u_strlen(word[i])- 1-j]=temp;
		}
	}

	for(i=0;i<3;i++){
		printf("%s\n",word[i]);
	}

	return 0;
}

int u_strlen(char * word)
{
	int len=0;
	while(*word!='\0'){
		word++;
		len++;
	}

	return len;
}
