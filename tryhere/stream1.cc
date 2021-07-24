// swapping ostringstream objects
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream

int main () 
{
   using namespace std;
#if 0
   std::string str ;
   std::cin >> str ;    

   std::stringstream ss(str);

   //ss << 100 << ' ' << 200;

   int foo=0 ;
   std::string bar;
   ss >> foo >> bar;

   std::cout << "foo: " << foo << '\n';
   std::cout << "bar: " << bar << '\n';
#endif

   stringstream os;
   os.str("xxxxxxxxxx");
   os << "World!";
   cout << os.str() << endl;

   
   return 0;
}
