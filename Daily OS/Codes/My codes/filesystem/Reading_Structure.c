#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Student
{
   char name[20],address[40];
   int age;
   float fee;
}stu;

int main()
{
   stu var;
   int fd=open("student_file",O_RDONLY);
   printf("\n");
   printf("======================================================\n");
   printf("Name    \t");
   printf("Address    \t");
   printf("Age    \t");
   printf("Fees    \t");
   printf("\n");
   while(read(fd,&var,sizeof(stu)))
   {
       printf("%s    \t",var.name);
       printf("%s    \t",var.address);
       printf("%d    \t",var.age);
       printf("%f    \t",var.fee);
       printf("\n");
       lseek(fd,0,SEEK_SET);
   }
   printf("======================================================\n");
}
