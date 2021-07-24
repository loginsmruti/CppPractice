/**
*	Hrere Client is Writing First & Then Server is reading that  value   & 
*       after that server is echoing/writing the same value to client pipe 
*       & client is just reading & printing that value 
*		i.e Echoing Server....
**/



#include<stdio.h>
#include<string.h>


int main(void)
{
 int pid , pipe1[2] ,pipe2[2];
 pipe(pipe1);
 pipe(pipe2);

 pid = fork();

 if(pid)   //.............................Serever
 {
  int n ;
  char s[80] ;
  close(pipe1[0]); close(pipe2[1]);
  
  while(1)
  {
   n = read(pipe2[0] , s ,80 );
   if(n == 0)
     break;

    write(pipe1[1] , s , n );
  }
  
    close(pipe1[1]);  close(pipe2[0]);
    wait();
 }
 else			//........................client
 {
  close(pipe1[1]); close(pipe2[0]);
  
  while(1)
  {
    char str[80]  , str1[80];
    int n1 ;
    printf("\n\tEnter Something To Echo :");
    scanf("%s",str);
    if(!(strcmp(str ,"exit")))
    {
    break;
    }
    else
    {
     write( pipe2[1] , str ,strlen(str));
     n1 = read(pipe1[0] ,str1 ,80);
     str1[n1] = '\0';
     printf("\n\t Data From Server : %s",str1);
    }
  }
  close(pipe1[0]); close(pipe2[1]);
 }
 printf("\n\n");
 return (0);
}

