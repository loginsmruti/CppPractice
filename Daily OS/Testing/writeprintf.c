#include<stdio.h>
#include<string.h>

int main(void)
{
  char s[10];
 //printf("\n\t God Is Great.....\n");
 // write(1, "\n", 1);                       
 //write(1, "\t God Is Great.....\n", 20	);

 //write(1 ,"\n",1);
 write(1 ,"\n\t Enter Some Text Here.... : " ,30);
 

 //scanf("%s",s);
 //printf("\n\t %s \n",s);
 
 read(0, s, 5);
 
 write(1 , s ,5);
 

 return (0);
}
