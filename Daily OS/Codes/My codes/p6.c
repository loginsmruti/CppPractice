// WAP  which will work similar to pwd

#include<stdio.h>
#include<stdlib.h>
mysystem(char *cmd)
{
  if(fork())
   wait();
  else
  {
   char *arg[]={cmd,NULL};
   execvp(cmd,arg);
   printf("mysystem :%s:no such comand\n",cmd); 
 }
}
int main()
{
 int x;
 printf("1 pid is %d\n",getpid());
// system("pwd");
 mysystem("pwd");

printf("2 pid is %d\n",getpid());
 return 0;
}
