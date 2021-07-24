
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#define  KEY 299



#pragma pack(1)
typedef struct date_of_birth
{
 short int date,year;
 char month[5];
}DOB;

struct stu
{
 char name[50],address[50];
 int age,roll_no;
 DOB  dob;
};




//struct stu *
int WriteStructureToShm(struct stu * , struct stu *);
void ReadFromShm(struct stu * , int);




