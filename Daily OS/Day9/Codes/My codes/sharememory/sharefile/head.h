#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#define  KEY 299

typedef struct date_of_birth
{
 short int date,year;
 char month[5];
}DOB;

struct student
{
 char name[50],address[50];
 int age,roll_no;
 DOB  dob;
};

void read1(struct student *var);
struct student*  writedata(struct student *writer,struct student *var ,int counter);
