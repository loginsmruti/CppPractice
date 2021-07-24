#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<signal.h>
#include<string.h>

struct student
{
char name[10];
int id;
int grade;
};

struct mystudent
{
   long mtype;
   struct student st;
};

void a(int x);
void b(int x);
void child_term(int x);


int main()
{
  int x;
  x=fork();
  if(x)
    {
     while(1)
       {
      int ch;
             printf("----------******MENU*********-------\n");
             printf("1.insert into shared memory\n");
             printf("2.modify in shared memory\n");
             printf("3.read from shared memory\n");
             printf("4.write in file and EXIT\n");

      printf("make a choice\n");
      scanf("%d",&ch);
      int mid;
      struct mystudent myt;
      int idno,gr;
      int i=0; 
      switch(ch)
         {
          case 1: //printf("---------------\n");
                  //struct mystudent myt;
                  myt.mtype=1;
                  mid=msgget(100,IPC_CREAT|0660);
                  //int i=0;
                   while(i<3)
                     {
                      printf("enter the name, id and grade\n");
                      scanf("%s %d %d",myt.st.name,&myt.st.id,&myt.st.grade);
                     }
                    msgsnd(mid,&myt,sizeof(struct student),0);
                    kill(x,SIGUSR1);
                    wait();
                    break;

          case 2:  //int mid;
                  // int idno,gr;
                  // struct mystudent myt;
                   myt.mtype=1;

                   mid=msgget(100,IPC_CREAT|0660);
                   printf("enter the id where u want to modify\n");
                   scanf("%d",&idno);
                   printf("enter the grade u want to update\n");
                   scanf("%d",&gr);
                   int id=shmget(111,10*sizeof(struct student),IPC_CREAT|0660);                    
                   void *p=shmat(id,0,0);
                    
                   struct student *recptr=p;
                   for(i=0;i<3;i++)
                     {
                       if(recptr->id==idno)
                          {
                            recptr->grade=gr;
                           }
                         else
                            {
                             i++;
                              recptr++;
                             }
                        }
                    myt.mtype=2;
                   msgsnd(mid,&myt,sizeof(struct student),0);        
                   kill(x,SIGUSR2);
                   break;
  
        default: kill(x,SIGCHLD);
                   
         }
      }
   }


else
{
printf("\n\t I am In Else...");
signal(SIGUSR1,a);
signal(SIGUSR2,b);
signal(SIGCHLD,child_term);

//void a(int x);
//void b(int x);
//void child_term(int x);
}
}
void a(int x)
{
   int mid; 
   struct mystudent myt;
   myt.mtype=1;
   mid=msgget(100,IPC_CREAT|0660);
   msgrcv(mid,&myt,sizeof(struct student),1,0);
   
  int id=shmget(111,10*sizeof(struct student),IPC_CREAT|0600);
  void *p=shmat(id,0,0);
  
   struct student obj;
    struct student *recptr=p;
    memcpy(recptr,&obj,sizeof(obj));
    int i=0;
    while(i<3)
      {
       i++;
       strcpy(recptr->name,myt.st.name);
       recptr->id=myt.st.id;
       recptr->grade=myt.st.grade;
       recptr++;
      }
   printf("manager has written all the contents in shared memory\n");
  }  
     
     
  void b(int x)
    {
        int mid; 
        struct mystudent myt;
        myt.mtype=2;
        mid=msgget(100,IPC_CREAT|0660);
        msgrcv(mid,&myt,sizeof(struct student),2,0);
   
       int id=shmget(111,10*sizeof(struct student),IPC_CREAT|0600);
       void *p=shmat(id,0,0);
  
       struct student obj;
       struct student *recptr=p;
       memcpy(recptr,&obj,sizeof(obj));
       int i=0;
       while(i<3)
        {
          i++;
          strcpy(recptr->name,myt.st.name);
          recptr->id=myt.st.id;
          recptr->grade=myt.st.grade;
          recptr++;
        }
       printf("manager has modified  all the contents in shared memory\n");
   }

    void child_term(int x)
      {
        int n=open("myrecord",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
        int id=shmget(111,10*sizeof(struct student),IPC_CREAT|0660);
        void *p=shmat(id,0,0);

        struct student *recptr=p;
 
        int i=0;
       while(i<3)
           {
             i++;
             write(n,&recptr,sizeof(struct student));
             recptr++;
           }
        // dispaly();
      printf("manager wrote contents in file and is terminated\n"); 
      }
  

 
