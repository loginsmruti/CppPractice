#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>


void ReadFromFile();

void ReadFromFile()
{
  int p1 , x = 1;
  struct stu *var, st;
  var= &st;

  p1 = open("Student.dat",O_RDONLY);
  if(p1 == -1)
    {
      printf("\n\tThere Is Something Problem In Opening File ...");
      exit(0);
    }
     printf("\n\n\t=========================================================================================================");
     printf("\n\tName\t\tAge\t\tRoll No\t\tDate\t\tMonth\t\tYear");
     printf("\n\t=========================================================================================================");

 //     read(p1 ,var , sizeof(st));
   lseek(p1 , -sizeof(st) ,SEEK_END);

   while(read(p1 , var , sizeof(st) ) )
   {
       printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%d",var->name,var->age,var->roll_no,var->dob.date,var->dob.month,var->dob.year);
     if(x == 0 )
        break;
      x = lseek(p1 , -2*sizeof(st) ,SEEK_CUR);
     //  read(p1 , var ,sizeof(st));
   }
    
   printf("\n\t=========================================================================================================\n\n");
   close(p1);
}



int main()
{
   int i;
   struct stu var, *sptr;
   sptr=&var;
 //  FILE *p ,*p1;
   ReadFromFile();
 return 0;
}
