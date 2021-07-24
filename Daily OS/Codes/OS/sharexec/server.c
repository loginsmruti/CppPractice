#include"header.h"
int main()
{
    int mid = msgget(MSGKEY,IPC_CREAT|0660);
    int shmid=shmget(SHMKEY,sizeof(struct student),IPC_CREAT|0660);
    struct student *shmptr,st;
    void *p=shmat(shmid,(void *)0,0);
    int *num=p,i,mtype;
    *num=0;
    shmptr=(struct student *)(num+1);
    struct msg msg1;
    struct resmsg rm;
    int fd = open("database",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if(fd==-1)
    {
        printf("Could not open file \n");
        exit(0);
    }
    //st=msg1.st;
    printf("here\n");
    printf("count=%d\n",*num);
    while(read(fd,&st,sizeof(struct student)))
    {
        *shmptr=st;
        *num=*num+1;
        shmptr++;
    }
    
    printf("count=%d\n",*num);
    while(1)
    {
       msgrcv(mid,&msg1,sizeof(msg1),-2,0);
       printf("message recieved\n");
       st=msg1.st;
       mtype=msg1.mtype;
       switch(mtype)
       {
           case 1:
	       if(st.roll==-1)
	       {
		   shmptr = (struct student *)(num+1);
		   lseek(fd,0,0);
		   for(i=0;i<*num;i++)
		   {
		       write(fd,shmptr+i,sizeof(st));
		   }
		   exit(0);
	       }
              *shmptr=st;
              *num=*num+1;
              shmptr++;
              rm.mtype=3;
              strcpy(rm.msg,"success");
              msgsnd(mid,&rm,25,0);
          case 2:       
             shmptr=(struct student *)(num+1);
             while(i<*num)
             {
                if(strcmp(shmptr->name,msg1.st.name)==0)
                {
                   *shmptr=msg1.st;                  
                }
               i++;
               shmptr++;
             }  
             rm.mtype=3;
             strcpy(rm.msg,"updated");
             msgsnd(mid,&rm,25,0);
             break;
       }
       
    }
}
