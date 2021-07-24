#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>
#include <string.h>                           //HEADER FILES
#include "./../include/employee.h" 


void display1();				//DISPLAYING The Employee Database Results


void display1()					//DISPLAYING The Employee Database Results
{
    FILE *p ;
    EMP var;

  p = fopen("./../SERVERLOG","rb");
  if(p == NULL)
    {
      printf("\n\tThere Is Something Problem In Opening File ...\n\n");
      exit(0);
    }
     printf("\n\n\t=========================================================================================================");
     printf("\n\tEmp_ID\tName\t Date Of Joining\tBasicSalary\tDA\tHRA\tCCA\tNetSalary");
     printf("\n\t=========================================================================================================");

     fread(&var , sizeof(var) ,1 , p);
     while(!feof(p))
     {
       printf("\n\t%s \t%s\t  %hd  %hd %hd  \t\t%d\t\t  %d\t%d\t%d\t%d",var.e_id,var.name,var.doj.DD,var.doj.MM,var.doj.YYYY,var.basic.basic_sal,var.basic.DA,var.basic.HRA,var.basic.CCA,var.basic.NetSal);
       fread(&var , sizeof(var) ,1 , p);
     }
    printf("\n\t=========================================================================================================\n\n");
   fclose(p);
}


int filecopying()
{
 int fd1 , fd2 , result ;
 char x; 
 fd1 = open("./SERVERLOG",O_CREAT |O_APPEND |O_WRONLY ,S_IWUSR |S_IRUSR);
 fd2 = open("./../../Employee.dat",O_RDONLY);
 printf("\n\t FD1 : %d  FD2: %d\n",fd1,fd2); 
 while(read(fd2 , &x ,1))
   result = write(fd1 , &x ,1);
 
  if(result != -1) {
    close( fd1 );
    close( fd2 );

    return 0;
   }
  else {
    close( fd1 );
    close( fd2 ); 
   
     return 1;
    }
}

void copyfile(int signal)
{
  int success ;
  printf("\n\t ......Server Notified Modification To Client Log......\n\n");
 
 success = filecopying();
 if(success == 1)
 {
  printf("\n\t Successful Uptation To Server Log\n");
  printf("\n\t ++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  display1();
 }
 
 
}

void clientstatus(int sig)
{
 printf("\n\t Client Application Closed....\n");
 printf("\n\t  Server Application Closing....\n");
 printf("\n\t  Successfully Exited....\n");
 
 exit(0);
}



int main(void)
{


   signal( SIGUSR1 , copyfile );
   signal(SIGUSR2 , clientstatus);

  
   printf("\n\t PID  : %d ",getpid() );
   printf("\n\t Pausing....");
     for( ; ; )
       pause();
 
    
 
 return (0);
}
