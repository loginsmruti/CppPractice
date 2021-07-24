#include <stdio.h>                          //HEADER FILES
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<signal.h>

int menu(void);                              //FUNCTION PROTOTYPES

int menu(void)                               //FUNCTION TO PRINT MAIN MENU AND RETURN THE CHOICE
{
   char choice; 
   printf("\n\n\t=========================================================================================================\n");
   printf("\t\tMenu Driven Employee database Operation");
   printf("\n\t=========================================================================================================\n");
   printf("\t\t1.Insert Employee Details");  
   printf("\n\t\t2.Update Employee Details");  
   printf("\n\t\t3.Delete a Employee's Record From database");  
   printf("\n\t\t4.Display Employee Details");  
   printf("\n\t\t5.To Exit From This Application");   
   printf("\n\n\t=========================================================================================================\n");
   printf("\n\n\tEnter Your Choice Considering above Menu :");
   scanf(" %c",&choice); 
       getchar();
      if((isdigit(choice))&&((choice>=49)&&(choice<=53)))
      return (choice-48);                    // returns choice (int)type 
}


int main()                                   //MAIN() STARTS 
{
 
 int ch ,pid;
  
  printf("\n\t Enter PID Of Server : ");
  scanf("%d",&pid);
  getchar();
  
  
  do 
 {
    ch=menu();                               //CALLING menu()
   switch(ch)
   {
     case 1:
           insertEmployee();                 //CALLING  insertEmployee()
            kill(pid ,SIGUSR1);
           break;
          
     case 2:
	   updateEmployee();                 //CALLING updateEmployee()
           kill(pid ,SIGUSR1);
           break;
  
     case 3:
	   deleteEmployee();		     //CALLING deleteEmployee()
	   display();
           break;

     case 4:
	   display();			     //CALLING display()
           break;
     case 5:
           printf("\n\t*** Thanks for using the program! Goodbye. ***\n\n");
            kill(pid ,SIGUSR2);
           exit(0);
           break;
    default:
           printf("\n\t PROGRAM OVER\n\n"); 
           break;
   }
    /*printf("\n\t\t Want To Exit From The Employee Database Application Then Press y : ");
    getchar();
    ch = getchar(); */
  }while(ch != 5);
}
