#include "head.h"
void read1(struct student *var )
{
     printf("\n\n\t=========================================================================================================");
     printf("\n\tName\t\tAge\t\tRoll No\t\tDate\t\tMonth\t\tYear");
     printf("\n\t=========================================================================================================");
     // while(i < counter)
      while(var->age)
     {
        printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%d",var->name,var->age,var->roll_no,var->dob.date,var->dob.month,var->dob.year);
	 var++;
     }
     printf("\n\t=========================================================================================================\n\n");
}


struct student*  writedata(struct student *writer,struct student *var ,int counter)
 {  
    char choice ;
    printf("\n\n\t ....................Enter Student Related Data's ...............");
  do
  { 
    counter++;
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
    printf("\n\t DO YOU WANT TO ENTER MORE DATA (y/n)");
    scanf("%c",&choice);
    getchar();
    memcpy(writer,var,sizeof(struct student));   
    writer++ ;
  }while(choice!='n'); 
  return writer;
}

 int main()
  {
     int fp,i;
     int ch,counter=0;
     char choice=' ';
     struct student var, *sptr ,temp;
     sptr=&var; 

     int sid=shmget(KEY,10*sizeof(struct student),IPC_CREAT | 0660);                 
     void *p=shmat(sid,(void *)0,0);
     struct student *writer=p; 
     struct student *readdata=p;
   while(1)
   {
   printf("\n\n==================================================================\n\n");
   printf("\t\t1.Insert record");  
   printf("\n\t\t2.Read  record");
   printf("\n\t\t3.save data in file "); 
   printf("\n\t\t4.read data from file ");
   printf("\n\t\t4.exit  ");  
   printf("\n\n\t================================================================\n");
   printf("\n\t Enter Your Choice :");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
             fp=open("new",O_WRONLY|O_CREAT|S_IRUSR|S_IWUSR);
             writer=writedata(writer,sptr,counter);
                   break;
          
     case 2:
   	   read1(readdata);               
           break;
     case 3:
            fp = open("studentrecord",O_CREAT | O_APPEND |O_RDWR ,S_IWUSR |S_IRUSR );
            if(fp == -1)
           {
             printf("\n\tThere Is Something Problem In Opening File ...\n\n");
             exit(0);
           }
	    while(readdata->age)
	   {
            i = write(fp,readdata,sizeof(struct student) );
	    readdata++ ; 
	   }
	   if(i > 0)
	     printf("\n\tSuccessfuly Written To file...");

           printf("\n\t*** Thanks for using the program! Goodbye. ***\n\n");
	   close(fp);
           exit(0);
           break;
     case 4: 
           fp = open("studentrecord",O_RDONLY);
            if(fp == -1)
            {
              printf("\n\tThere Is Something Problem In Opening File ...\n\n");
              exit(1);
            }
            printf("\n\n\t=========================================================================================================");
            printf("\n\tName\t\tAge\t\tRoll No\t\tDate\t\tMonth\t\tYear");
            printf("\n\t=========================================================================================================");
	    while(read(fp,&temp,sizeof(struct student)))
	    {
		//read(p1 , &temporary2 , sizeof(struct stu));
            	printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t\t%d",temp.name,temp.age,temp.roll_no,temp.dob.date,temp.dob.month,temp.dob.year);
             
	    }
            printf("\n\t=========================================================================================================\n\n");
	    close(fp); 
     case 5:
             exit(1);
    default:
           printf("\n\t PROGRAM OVER\n\n"); 
           break;
    }
   
  }
 return 0;
}

