#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,arr[10];
    for(i=0;i<10;i++)
    {
       arr[i]=fork();
       if(!arr[i])
       {
          if(i==0)
          {
             printf("i m first child\n");
          }
          else
          {
             printf("previous id=%d \n",arr[i-1]);
          }
          sleep(2);
          printf("exit...\n");
          exit(0);
       }
    }
    for(i=0;i<10;i++)
    {
       wait4(arr[i],NULL,0,NULL);
    }
       printf("Exiting main...\n");
}
