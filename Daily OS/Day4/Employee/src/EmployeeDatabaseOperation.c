#include<stdio.h>
#include <string.h>                           //HEADER FILES
#include "./../include/employee.h"
#include <stdlib.h>

FILE *p , *temp;                            //GLOBAL FILE POINTERS
EMP var;



void insertEmployee(void); 
void updateEmployee(void);
void deleteEmployee(void);
void display(void);

void insertEmployee()                         //FUNCTION TO Insert New Employee
{
  /*char send[10];
  int i=0;
   char *x ;
      x =  generateId(2);
   while(*(x+i) !='\0')
   {
     *(send+i)=*(x + i++);   
   }
    *(send+i) = '\0'; 
   printf("\n\n\t%s\n",send); 

   extern FILE *p ;
   extern EMP var;
   */

   static int count=0 ;
   char ch;
   char send[10];
   
   p = fopen("./../Employee.dat","a+b");
   if(p == NULL)
    {
      printf("\n\tThere Is Something Problem In Opening File ...\n\n");
      exit(0);
    }
  printf("\n\n\t ....................Enter Employee Related Data's ...............");
   
  while(1)
  { 
   char emp_id[10];
    ++count;
    printf("\n\tEnter The Employee Name :");
    scanf("%s",var.name);
    getchar();        
    /* 
 *     int i=0 ;
 *       char *x ;
      x =  generateId(count);
   while(*(x+i) !='\0')
   {
     *(send+i)=*(x + i++);
   }
    *(send+i) = '\0';
   //printf("\n\n\t%s\n",send);
     strcpy(var.e_id,send); */

       sprintf(emp_id,"EMP_%d" , count);
   strcpy(var.e_id,emp_id);     
    printf("\n\tEnter The Employee Date Of Joining(Ex : DD MM YYYY) :");
    scanf("%hd %hd %hd",&var.doj.DD,&var.doj.MM,&var.doj.YYYY);
    getchar();
    if(var.doj.DD<1 || var.doj.DD>31 )
      break;
    if(var.doj.MM<1 || var.doj.MM>12 )
      break;
    if(var.doj.YYYY<1900 || var.doj.YYYY>2014 )
      break;
     

    printf("\n\tEnter The Employee Basic Salary :");
    scanf("%d",&var.basic.basic_sal);
    getchar();
    var.basic.DA = generate_DA(var.basic.basic_sal);
    var.basic.HRA = generate_HRA(var.basic.basic_sal);
    var.basic.CCA = generate_CCA(var.basic.basic_sal);
    var.basic.NetSal = generate_NetSal(var.basic.basic_sal , var.basic.DA ,var.basic.HRA , var.basic.CCA);

    fwrite(&var,sizeof(var),1,p);
    printf("\n\tEmployee's Entry Successfull...... ");
    printf("\n\tEnter Your Choice (Y/y)For Again Employee Entry (N/n)To Exit ... :");
    ch=getchar();
      if(ch=='N'|| ch=='n')
           break;    
    
    printf("\n\t.....********......");
  } 
   fclose(p);
}

void updateEmployee()                                   //FUNCTION TO updateEmployee  Basic Salary & corresponding Allowances
{
   extern FILE *p ;
   extern EMP var;

    char ch;
 
    while(1)
    {
      char empId[20];  
      printf("\n\tSpecify Employee's ID to Which You Want Modification : ");   
      scanf("%s",empId);
      getchar();
      p = fopen("./../Employee.dat","r+b");
       if(p == NULL)
      {
        printf("\n\tThere Is Something Problem In Opening File ...\n\n");
        exit(0);
      }
      rewind(p);
      
      while(fread(&var , sizeof(var) , 1 ,p)== 1)
      {
        if(strcmp(var.e_id , empId)==0)
        {  
         printf("\n\tEnter Employee's Basic Salary To Update His Remuneration Faciities : ");
         scanf("%d",&var.basic.basic_sal);
         var.basic.DA = generate_DA(var.basic.basic_sal);
         var.basic.HRA = generate_HRA(var.basic.basic_sal);
         var.basic.CCA = generate_CCA(var.basic.basic_sal);
         var.basic.NetSal = generate_NetSal(var.basic.basic_sal , var.basic.DA ,var.basic.HRA , var.basic.CCA);
         //printf("\n\tNow My Cusor Position Is : %ld \n",ftell(p));
         fseek(p , -sizeof(var) ,SEEK_CUR);
         //printf("\n\tNow My Cusor Position Is : %ld \n",ftell(p));
         fwrite(&var , sizeof(var) , 1 , p);
         printf("\n\tEmployee's Salry Updation Successfull.....  \n");
         break;
        }
      }
     
      printf("\n\tEnter Your Choice (Y/y) To Update  Another Employee's Entry (N/n)To Exit ... :");
      ch=getchar();
       
      if(ch != 'n')
           break; 
    }
}

void deleteEmployee()					//FUNCTION To Delete Employee Entries
{
   extern FILE *p ,*temp;
   extern EMP var;

 while(1)
 {   
      char empId[30];
      char ch;
      printf("\n\tEnter The Employee_Id To Delete Respective Entry : ");
      scanf("%s",empId);      
      //fgets(empId,20, stdin);
      temp = fopen("./../Temp.dat","wb");
      p = fopen("./../Employee.dat","rb");
      if(p == NULL)
      {
        printf("\n\tThere Is Something Problem In Opening File ...\n\n");
        exit(0);
      }
      if(temp == NULL)
      {
        printf("\n\tThere Is Something Problem In Opening File ...");
        exit(0);
      }
      rewind(p);
      while(fread(&var , sizeof(var) , 1 , p))
      {
         if(strcmp(var.e_id ,empId) != 0) 
           fwrite(&var , sizeof(var) , 1 ,temp); 
      }
	                                 
      fclose(p);
      fclose(temp);
      remove("./../Employee.dat");
      rename("./../Temp.dat","./../Employee.dat");
       
      printf("\n\tEmployee's Entry Deletion Successfull...... \n");
       
      p = fopen("Employee.dat","rb+");
      if(p == NULL)
      {
        printf("\n\tThere Is Something Problem In Opening File ...");
        exit(0);
      }
      
      printf("\n\tEnter Your Choice (Y/y) To Delete Another Employee Entry (N/n)To Exit ... :");
      ch=getchar();
       getchar();
      if(ch != 'n')
           break;
 }
}

void display()					//DISPLAYING The Employee Database Results
{
   extern FILE *p ;
   extern EMP var;

  p = fopen("./../Employee.dat","rb");
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



