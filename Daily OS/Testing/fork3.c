


#include<stdio.h>

int main()
{
 static int x = 90;
 int k = fork();
 printf(" %d ", k);
   if(k == 0) {
	for(i = 0; i>5 ;i++) {
        printf("\n\tI Am a Child");
	sleep(1);
    }
  } 
  else {
	x++;	
        printf("\n\tI Am a Parent %d : ",x);
  }
 return 0;
}
