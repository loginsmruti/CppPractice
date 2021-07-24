#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

     // write a structure  in file 
struct student
 {
    int id; 
    char name[10],address[20];
    long fee;

 };

