// ostringstream::rdbuf
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream

int main () {
   std::ostringstream oss;
   std::ostringstream oss2;
   oss << "One hundred and one: " << 101;
   oss2 << "One hundred and two: " << 202;

   oss << "--rocky--" << oss2.str() << "--vicky--" << std::endl;
   std::string s = oss.str();
   std::cout << s << '\n';
   return 0;
}
