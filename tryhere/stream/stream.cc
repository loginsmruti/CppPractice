
#if 0   
#include <iostream>

int main()
{
   using namespace std;
   
//   char* p = "David";
//   std::string str = p;
  
   //str[0] = 'F';
////   p[0] = 'F'; 
//A C++ string can return a C character pointer to its contents. But...
//   Not possible to change the string with this pointer
//   Don't use the pointer after the string has been destroyed
   
   std::string str1 = "Cocacola";
   const char* p1 = str1.c_str();

   str1[0] = 'F';
   
   cout << "Pointed String :: " << p1 << endl;
   cout << "My string :: " << str1 << endl;
   
   return 0;
}
#endif

// redefine tied object
#include <iostream> 
#include <fstream> 

int main () 
{
   std::ostream *prevstr;
   std::ofstream ofs;
   ofs.open ("test.txt");

   std::cout << "tie example:\n";

   *std::cin.tie() << "This is inserted into cout";
   prevstr = std::cin.tie (&ofs);
   *std::cin.tie() << "This is inserted into the file";
   std::cin.tie (prevstr);

   std::cout.setf(std::ios::showpos); // turn on the ios::showpos flag
   //std::cout.setf(std::ios::showpos | std::ios::uppercase | std::ios::hex | std::ios::showbase); // turn on the ios::showpos flag
   std::cout << 27 << std::endl;
   std::cout << std::cout.setprecision(3) << 123.456 << std::endl; 
   ofs.close();

   return 0;
}



