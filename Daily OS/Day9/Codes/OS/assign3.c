#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int mysystem(char *cmd)
{
    if(!fork())
    { 
       int i=0;
       char *args[10];
       char *p;
         p=strtok(cmd," ");
       do
       {
         args[i]=p;
         i++;
       }while((p=strtok(NULL," "))!=NULL);
       args[i]=NULL;
       execvp(args[0],args);
       printf("command not found\n");
       exit(0);
    }
    else
    {
       wait();
    }
}
int main()
{
    char cmd[10],name[25];
    FILE *fp=fopen("login","a+");
    printf("Enter your name:- ");
    gets(name);
    time_t t,t1;
    time(&t);
    fprintf(fp,"%s log in at %s ",name,ctime(&t));
    fclose(fp);
    do
    {
      printf("%s::$ ",name);
      gets(cmd);
      if(strcmp(cmd,"exit")==0)
             break;
      mysystem(cmd);
    }while(1);
    fp=fopen("login","a+");
    time(&t1);
    fprintf(fp,"%s log out at %s ",name,ctime(&t1));
    fprintf(fp,"Duration of your is:- %lf\n\n",difftime(t1,t));
    fclose(fp);
}
