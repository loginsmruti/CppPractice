#include<stdio.h>
#include<string.h>

int main()
 {

   int pipe1[2],pipe2[10];
   if(fork())
   { //server
   
   char rp[80];
   close(pipe1[0]);
   close(pipe2[1]);

   while(1)
    {
       int n=read(pipe2[0],rp,80);
       if(n==0)break;
       write(pipe1[1],rp,n);

    }
     close(pipe1[1]);
     close(pipe2[0]);
   wait();

   }
   else
    {
       char rc[80],wc[80];
          close(pipe1[1]);
          close(pipe2[0]);
  
         do{
             printf("\n\tEnter data : ");
            scanf("%s",wc);
	     getchar();
            write(pipe2[1],wc,strlen(wc));
              int n=read(pipe1[0],rc,80);
               rc[n]='\0';
                printf("\n\tdata from serv :%s\n",rc);  
           }while(strcmp(wc,"exit"));
        close(pipe1[0]);
         close(pipe2[1]);

    }
    
return 0;
}   
