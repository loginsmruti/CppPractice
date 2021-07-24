/*
   pa
   |
   |
   |___Pb executes ls
   |
   |
   |___Pc executes pwd
   |
   |
   |___Pd executes Mubinary...



*/

#include<stdio.h>

int main()
{
 int i ,x ,counter ,cpid[3];
 char *arg0[] = {"gcc","-o","out","./fun.c","-w",NULL};
 char *arg1[] = {"./out",NULL};
 char *arg2[] = {"pwd",NULL};
 char *arg3[] = {"ls","-lrth",NULL};
  
 for(counter = 0; counter < 3 ; counter++)
 {
  x = fork();
   if(!x)
   {
    if(counter == 0) {
        execvp("ls",arg3);   }
    if(counter == 1)  {
        execvp("pwd",arg2);   }
    if(counter == 2) {
        execvp("./out",arg1);     }
   }
 }
  wait();
  execvp("gcc",arg0);
  
 return(0);
}
