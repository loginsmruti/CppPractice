#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>


#define KEY 100
#pragma pack(1)

typedef struct stud 
{

 char name[20];
 char id[10];
}STU;

typedef struct msg 
{
 long type ;
 STU s;
}MSG;

int main(void)
{
 MSG m ;

 int mid , res ;
 m.type = 1;
 strcpy(m.s.name , "Vicky");
 strcpy(m.s.id ,"001");
  
  mid =msgget(KEY ,IPC_CREAT | 0600);

  res = msgsnd(mid ,&m , sizeof(STU) ,0);
 
    printf("\n %d \n",res);


 return (0);

}
