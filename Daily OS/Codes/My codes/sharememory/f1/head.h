#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/shm.h>
       
        `struct rec{
          int x;
	 char arr[10],c;
        };