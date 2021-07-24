
#include "file.h"
	
			// Server ................
char *str_upr(char *str)
{
 char buffer[20];
 char *p = str; 
 int i =0 ;
 
 while(p[i] != '\0')
 {
  buffer[i] = p[i] - 32 ;
  i++; 
 }
 buffer[i] = '\0';
// printf("%s",buffer);

 return buffer;
}
			
char *string_concat(char *p ,char *q)
{
 int i =0,j=0;
 
 while(*(p+i) != '\0')
    i++;
  
 while(*(q+j) != '\0')
      *(p + i++) = *( q + j++);
  
  *(p+i) ='\0';
     
 return p; 
}

 int main(void)
 {
	int fd1 ,f , n, start ,total ,i =0 ;
	short int flagValue ;
	char buffer[200] , newbuf[200] ,newbuf1[200], x ,temp[10],temp1[200];

	fd1 = open("printer",O_RDWR);
	perror("success");
	
	 read(fd1 , &q  ,sizeof(q) );
	flagValue = q.flag ;
	strcpy(buffer , q.fileName);	
	start = q.startByte ;
	total = q.totalBytes ;
	
	if(flagValue == 1)
	{
	  f = open("file1",O_RDWR |O_TRUNC);
	  perror("File Opened ...");
	  //lseek(f , start ,SEEK_SET);
	   while(read(f , temp , 10 ))
	  {
	    temp[n] ='\0' ;
	    string_concat(temp1 ,temp );	
	  }
		
	  
	  newbuf[i] ='\0';
	  //printf("\n\t Reading File : %s",temp1);
//	  //str_upr(temp1);
	  strcpy(newbuf , str_upr(temp1));
	  for(i = 0 ; i <total ; i++)
	     newbuf1[i] = newbuf[start];
	  
 	    newbuf1[i] ='\0'; 

	  write(fd1 ,newbuf1 ,strlen(newbuf1));
	}
	printf("\n\tServer Response Is Written ....\n" );
		
  return (0);

 }
