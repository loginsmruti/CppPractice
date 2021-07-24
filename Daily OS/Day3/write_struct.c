#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
void WriteStructureToFile(struct stu *);


void WriteStructureToFile(struct stu *var)
{   
   char ch;
   int p , i;
//    struct stu st;
//     var = &st;
   p = open("Student.dat",O_CREAT|O_APPEND|O_WRONLY,S_IRUSR|S_IWUSR);
   if(p == -1)
    {
      printf("\n\tThere Is Something Problem In Opening File ...");
      exit(0);
    }
  printf("\n\n\t ....................Enter Student Related Data's ...............");
   
  while(1)
  { 
    printf("\n\tEnter The Student Name :");
    scanf("%s",var->name);
    //fgets(var->name,17,stdin);
    getchar();
    
    printf("\n\tEnter The Student Age :");
    scanf("%d",&var->age);
    getchar();

    printf("\n\tEnter The Student Roll :");
    scanf("%d",&var->roll_no);
     getchar();
    printf("\n\tEnter Student Birth Date :");
    scanf("%hd",&var->dob.date);
    getchar();
 
    printf("\n\tEnter Student Month Of Birth :");
    scanf("%s",var->dob.month);
    getchar();

    printf("\n\tEnter Student Birth Year:");
    scanf("%hd",&var->dob.year);
    getchar();   

    i = write(p,var,sizeof(struct stu));
      
    if(i > 0 )
      printf("\n\t 1 Structure Data Is written ....\n");
    
   printf("\n\tEnter Your Choice (Y/y)For Again Student Entry (N/n)To Exit ... :");
    ch=getchar();
      if(ch=='N'|| ch=='n')
           break;    
     
      
    printf("\n\t.....********......");
    //return p;
  } 
   close(p);
}

int main()
{
   int i;
   struct stu var, *sptr;
   sptr=&var;
   WriteStructureToFile(sptr);
 return 0;
}
