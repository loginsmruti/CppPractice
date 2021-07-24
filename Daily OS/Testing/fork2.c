

#include<stdio.h>

int main()
{
 int i;
 int k = fork();
 printf(" %d ", k);
   if(k == 0) {
	for(i = 0; i>5 ;i++) {
        printf("\n\tI Am a Child");
	sleep(1);
    }
  } 
  else {
	//for(i = 1 ;i <=5 ; i++) {
	//printf("\n\tI am a Parent");
	//sleep(1);
   //}
   wait(); 
  }
 return 0;
}
