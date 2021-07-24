// string assigning
#include <iostream>
#include <string>
#if 0
int main ()
{
   std::string str1;
   str1 = "vicky";
   str1 = "rocky";

   str1.assign("mystring");
   //std::cout << str << '\n';         // "c-string"

   std::cout << str1  << '\n';
   return 0;
}


// string::clear
#include <iostream>
#include <string>

int main ()
{
   char c;
   std::string str;
   std::cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
   do {
      c = std::cin.get();
      str += c;
      if (c=='\n')
      {
         std::cout << str;
         str.clear();
      }
   } while (c!='.');
   return 0;
}


#endif

#include <log4cplus/configurator.h>
#include <log4cplus/logger.h>
#include <log4cplus/helpers/loglog.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace log4cplus::spi;

int main()
{
    log4cplus::tostringstream string = "myString";
    log4cplus::tostringstream string1 ;

    string1 << string;
   
  
}
