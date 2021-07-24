#include"header.h"
int main()
{
    int mid = msgget(MSGKEY,IPC_CREAT|0660);
    int shmid=shmget(SHMKEY,sizeof(struct student),IPC_CREAT|0660);
    struct student *shmptr;
    void *p=shmat(shmid,(void *)0,0);
    int *num,ch,i;
    num=p;
    shmptr=(struct student *)(num+1);
    struct msg msg1;
    struct resmsg rm;
    do
    {
       printf("1-add a record\n");
       printf("2-display records\n");
       printf("3-exit\n");
       scanf("%d",&ch);
       getchar();
       switch(ch)
       {
          case 1:
             printf("Enter name:- \n");
             gets(msg1.st.name);
             printf("Enter roll number:-  \n");
             scanf("%d",&msg1.st.roll);
             msg1.mtype=1;
             msgsnd(mid,&msg1,sizeof(struct student),0);
             msgrcv(mid,&rm,25,2,0);
             printf("%s...\n",rm.msg);
             break;
          case 2:
             printf("number of record...%d\n",*num);
             for(i=0;i<*num;i++)
             {
                printf("%s ",(shmptr+i)->name);
                printf("   %d \n",(shmptr+i)->roll);
             }
             break;
       }
    }while(ch!=3);
    strcpy(msg1.st.name,"exit");
    msg1.st.roll=-1;
    msg1.mtype=1;
    msgsnd(mid,&msg1,sizeof(struct student),0);
}

