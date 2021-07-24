#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY 100
#define KEY1 200

int main(void)
{
 int mid , mid1 ;

 mid = msgget(KEY,IPC_CREAT |0600);
 mid1 = msgget(KEY1,IPC_CREAT |0600);

 
 msgctl(mid , IPC_RMID ,NULL );


 int fd1 = open("vicky", O_CREAT |O_APPEND |O_WRONLY ,0600);
 perror("Result :");
 
  
 return (0);
}

