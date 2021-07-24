
#include<stdio.>


int main(void)
{
 int ret ,o ;
 
 o = open("./vicky",O_RDONLY);
 if(o == -1)
   printf("\n\tThere Something Problem In File.... \n");
 

 return(0);
}
