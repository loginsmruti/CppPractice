#include<stdio.h>
#include<fcntl.h>


int main()
{
 int k ;
 char str[30] = "Smruti Ranjan Panda";
 k = open("vicky",O_RDONLY); 
 
 if(fork())
 {
    sleep(1); 
    
    int count , i ;
    count = 0 ;
    while(str[count] != '\0') {
     i = read(k , &str[count] ,1);
     count++;
    }
    if(i > 0 )
      printf("\n\t File reading Successful....\n");
 } 
 else
 {
  if(k == -1)
  {
   printf("\n\tThere is something problem in file  .....\n");
  }
  else
  {
    sleep(1); 
    int count , i ;
    count = 0 ;
    while(str[count] != '\0') {
     i = read(k , &str[count] ,1);
     count++;
    }
    if(i > 0 )
      printf("\n\t File reading  Successful....\n");
  }
 }

  return (0);
}


