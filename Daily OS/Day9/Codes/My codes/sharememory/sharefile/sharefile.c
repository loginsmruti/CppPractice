
#include "structure.h"

void ReadFromShm(struct stu *temp , int counter )
{
     int  i= 0 ;
     printf("\n\n\t=========================================================================================================");
     printf("\n\tName\t\tAge\t\tRoll No\t\tDate\t\tMonth\t\tYear");
     printf("\n\t=========================================================================================================");
     while(i < counter)
     {
        printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%d",temp->name,temp->age,temp->roll_no,temp->dob.date,temp->dob.month,temp->dob.year);
	i++; temp++;
     }
     printf("\n\t=========================================================================================================\n\n");
}


//struct stu *
int WriteStructureToShm( struct stu *var , struct stu *writer )
{   
  char choice ;
  int counter  = 0;
    printf("\n\n\t ....................Enter Student Related Data's ...............");
  while(1)
  { 
    counter ++;
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
    printf("\n\t Enter choice To Write Again To Shared Memory...");
    scanf("%c",&choice);
    getchar();
	   
    memcpy(writer , var , sizeof(struct stu));    	  // printf("\n\tCounter = %d\n ",counter); 
    if(choice == 'n')
     break;
    writer++ ;
  }
   return counter ;   
}

int main(void)
{
	int  p , p1 ;
	int i , ch , counter ; 
        char choice ;
	struct stu var, *sptr , *temp , temporary2;
	sptr=&var;        
          
  	int shmid ;	
	void *shmptr ;
	shmid = shmget(KEY, 800, IPC_CREAT | 0660) ;
	shmptr = shmat(shmid, (void *)0, 0) ;
//        shmdt(shmptr);
 	
	struct stu *writer = shmptr ;
          

do {
   printf("\n\n\t=========================================================================================================\n");
   printf("\t\tMenu Driven Employee database Operation");
   printf("\n\t=========================================================================================================\n");
   printf("\t\t1.Insert Employee Details To Shared Memory...");  
   printf("\n\t\t2.Read Employee Details From Shared Memory...");  
   printf("\n\t\t3.To Exit From This Application  :::: Save To File...");
   printf("\n\t\t4.Display Employee Record From File ...");     
   printf("\n\n\t=========================================================================================================\n");
   printf("\n\t Enter Your Choice :");
   scanf("%d",&ch);
   printf("\tsize : %ld",sizeof(struct stu));
   switch(ch)
   {
     case 1:
           //temp = 
	   counter = WriteStructureToShm(sptr , writer);  
printf("\n\tCounter = %d\n ",counter);
   	   ReadFromShm(writer , counter);              
	   break;
           
          
     case 2:
   	   ReadFromShm(writer , counter);               
           break;
  
     case 3:
	   p = open("./Employee.dat",O_CREAT | O_APPEND |O_RDWR ,S_IWUSR |S_IRUSR );
           if(p == -1)
           {
             printf("\n\tThere Is Something Problem In Opening File ...\n\n");
             exit(0);
           }

           i = write(p , writer, counter*sizeof(struct stu) );
	   if(i > 0)
	     printf("\n\tSuccessfuly Written To file...");

           printf("\n\t*** Thanks for using the program! Goodbye. ***\n\n");
	   close(p);
           exit(0);
           break;

     case 4:
	    
	    p1 = open("./Employee.dat",O_CREAT | O_APPEND |O_RDWR ,S_IWUSR |S_IRUSR );
            if(p1 == -1)
            {
              printf("\n\tThere Is Something Problem In Opening File ...\n\n");
              exit(0);
            }
            printf("\n\n\t=========================================================================================================");
            printf("\n\tName\t\tAge\t\tRoll No\t\tDate\t\tMonth\t\tYear");
            printf("\n\t=========================================================================================================");
	    while(read(p1 , &temporary2 , sizeof(struct stu)))
	    {
		//read(p1 , &temporary2 , sizeof(struct stu));
            	printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%d",temporary2.name,temporary2.age,temporary2.roll_no,temporary2.dob.date,temporary2.dob.month,temporary2.dob.year);
	    }
            printf("\n\t=========================================================================================================\n\n");
	    close(p1); 
    default:
           printf("\n\t PROGRAM OVER\n\n"); 
           break;
   }
   printf("\n\tEnter Your Choice To Start The Application Again : ");
   scanf(" %c",&choice);
   getchar();
 }while(choice != 'n');
  
 return 0;
}

