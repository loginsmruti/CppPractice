// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t 
{
     string title;
       int year;
};

int main ()
{
#if 0
   string mystr;

   movies_t amovie;
   movies_t * pmovie;
   pmovie = &amovie;

   cout << "Enter title: ";
   getline (cin, pmovie->title);
   cout << "Enter year: ";
   getline (cin, mystr);
   (stringstream) mystr >> pmovie->year;

   cout << "\nYou have entered:\n";
   cout << pmovie->title;
   cout << " (" << pmovie->year << ")\n";
#endif 


   if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
   else if( __cplusplus == 19971L ) std::cout << "C++98\n" ;
   else std::cout << "pre-standard C++\n" ;


   return 0;
}
