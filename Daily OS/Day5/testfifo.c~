#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(void)
{
 int ret ,o , n ;
 char str[10];
 
// ret = mkfifo("./vicky",S_IWUSR |S_IRUSR);
 //if(ret == -1)
  // printf("\n\tThere Something Problem In Creating FIFO File.... \n");

 o = open("./vicky",O_RDWR);
 if(o == -1)
   printf("\n\tThere Something Problem In File.... \n");
   
 write(o ,"Vicky Don",strlen("Vicky Don"));
  
 n = read(o , str ,9); 
 str[n] ='\0';


 printf("MY FIFO FILE DATA IS : %s\n",str);
 return(0);
}
