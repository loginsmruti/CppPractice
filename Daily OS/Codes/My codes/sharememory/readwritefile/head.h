#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/shm.h>

    struct DOJ
    {
      int date;
      int month;
      int year;
    };
    typedef struct Employee
    {
      int eid;
      char name[20];
      struct DOJ d;
      float Basic;
      float Da;
      float Hra;
      float Cca;
      float NetSal;
    }EMP;
