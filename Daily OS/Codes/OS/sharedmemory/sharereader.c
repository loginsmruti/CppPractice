#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
struct student
{
   char name[50];
   int age;
};
int main()
{
    int shid = shmget(101,sizeof(struct student),IPC_CREAT|0660);
    struct student *st=shmat(shid,(void*)0,0);
    printf("Name : %s\n",st->name);
    printf("Age : %d\n",st->age);
}
