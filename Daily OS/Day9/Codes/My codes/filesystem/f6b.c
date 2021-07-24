 #include "f6c.h"
      int main()
      {
       int x=1;
         struct student var;
        int fp;
       printf("\n reading the file \n\n");
   
        fp=open("new",O_RDONLY);
        printf("id\t | name\t |address \t| fee \n");
         lseek(fd,-sizeof(stu),SEEK_END);
        while(read(fp,&var,sizeof(struct student)))
         {
            printf("%d\t %s\t %s\t %ld\n",var.id,var.name,var.address,var.fee);
            if(x==0)break;
          lseek(fp,-2*sizeof(stu),SEEK_CUR);

         }
         close(fp);
     }
