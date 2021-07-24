#include<stdio.h>
#include<dirent.h>

int main()
{
 char name[20];
 struct dirent *dirp ;
 DIR *dp ;

  dp = opendir("..");
  dirp = readdir(dp);
  
  printf("Inode Number %ld : \n\n",dirp->d_ino);
  
  printf("Directory Name %s \n\n ",dirp->d_name);
 
  return(0);
}
