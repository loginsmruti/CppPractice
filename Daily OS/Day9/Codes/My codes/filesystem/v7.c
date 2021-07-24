// WAP  which is similar to SHELL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
myshell(char *cmd)
 {
    if(fork())
       wait();
    else
     {      
           
         char *p,*args[10],arr[6][10];
         int counter=0;
         p=strtok(cmd," ");
         do{
               strcpy(arr[counter],p);
               args[counter]=arr[counter];
                   counter++;
          }while(p=strtok(NULL," "));
              args[counter]='\0';
           execvp(args[0],args);              
        
 
           /*char *arg[]={cmd,NULL};
           execvp(cmd[i],arg);
           printf("NO such command found %s",cmd);
            */
          
     }
 }

int main()
{ 
 int n,i;
 char cmd[20],name[20];
 printf("Enter your login =");
 gets(name);
 while(1)
 {
  printf("$%s$",name);
  gets(cmd);
   if(strcmp(cmd,"exit")!=0)
   {
     myshell(cmd);
    }
    else
    {
      exit(1);
   }
 }
 return 0;
 }






























