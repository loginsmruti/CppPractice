
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
  
  mid =msgget(KEY ,IPC_CREAT | 0600);

 

 msgrcv(mid , &m ,sizeof(STU),1 , 0);

  printf("Name :%s   ID : %s \n",m.s.name,m.s.id);
 return (0);

}
