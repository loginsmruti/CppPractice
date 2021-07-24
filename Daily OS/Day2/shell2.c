
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 mysystem(char *command)
{
   if(fork())
         wait();
    else
    {
         char *p,*args[10],arr[6][10];
         int count=0;
          p=strtok(command," ");
          do
           {
               strcpy(arr[count],p);
               args[count]=arr[count];
                  count++;
           }while(p=strtok(NULL," "));
          args[count]='\0';
        execvp(args[0],args);
    }
} 

int main()
{
 char name[10],command[20];
 printf("\n\tEnter Your Login Name : ");
  gets(name);

   while(1)
   {
  printf("\n\n%s ## ",name);
  gets(command);
 // ptr=command;
   if(strcmp(command,"exit")!=0)
   {
  mysystem(command);
   }  
   else
   {
     exit(1);
   }
  
  }
return 0;
}
