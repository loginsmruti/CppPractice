#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   int fd1[2],fd2[2];
   pipe(fd1);
   pipe(fd2);
   
   
   if(fork())
   {   //server
     char arr[10];
     close(fd1[0]);      //close read
     close(fd2[1]);      //close write
    
    while(1)
    {   
    int n=read(fd2[0],arr,10);
       if(n==0)break;  
     write(fd1[1],arr,n);
   }    
   }
   else
   {    //client
    

     char str[10],str1[10];
    
     close(fd1[1]);   //close write
     close(fd2[0]);   //close read
     do
      {
     printf("Enter the data ");
      gets(str);
      write(fd2[1],str,strlen(str)); 
      int n= read(fd1[0],str1,9);
      str1[n]='\0';
     printf("Server Echo : - %s\n",str1);
    } while(strcmp(str,"exit"));
   }

 return 0;
}
