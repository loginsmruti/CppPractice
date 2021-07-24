#include<stdio.h>
#define ROW 5
#define COLUMN 6

int checkColumn(int , char matrix[ROW][COLUMN]);
int checkReverseRow(int ,char matrix[ROW][COLUMN]);

int main(void)
{
	char matrix[ROW][COLUMN]={"ABCDE","BFGHD","CGIGC","DHGFB","EDCBA"};

	int i=0;
	int flag=1;

	for(;i<ROW;i++){
		if ( checkColumn(i,matrix) ==0 ) { flag=0; break; }
		if ( (i < ROW/2 ) && checkReverseRow(i,matrix) ==0 ) { flag=0; break; }
	}

	if(flag==0) printf("NOT ACROSTIC");
	else printf("ACROSTIC");

	printf("\n");
	return 0;
}

int checkColumn(int r,char  matrix[ROW][COLUMN])
{
	int i=0;
	int flag=1;

	for(;i<COLUMN-1;i++){
		if(matrix[r][i] != matrix[i][r])
		flag=0;
		break;
	}

	return flag;
}

int checkReverseRow(int r,char matrix[ROW][COLUMN])
{
	int i=0;
	int flag=1;

	for(;i<COLUMN-1;i++){
		if(matrix[r][i]!=matrix[ROW-1-r][COLUMN-2-i]){ flag=0;break;}
	}
	return flag;
}
