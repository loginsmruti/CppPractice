#include<iostream>
 
int main()
{
   int i=10;
   int &j=i;
   int k=20;
   j=k;
   std::cout << i << j<< k ;
   return 0;
}
