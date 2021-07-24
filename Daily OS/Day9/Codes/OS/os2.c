#include<stdio.h>
int main()
{
    char *args[]={"new",NULL};
    printf("next process id:-%d\n",getpid());
    execvp("./new",args);
    
}
