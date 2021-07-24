#include<stdio.h>

int main()
{

 int x ;

 x= fork();

 if(x) {
  sleep(30);
   wait();
  }
}
