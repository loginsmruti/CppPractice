#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>

void example1()
{
   std::set<std::string> setOfDepartments;

   setOfDepartments.insert("First");
   setOfDepartments.insert("Second");
   setOfDepartments.insert("Third");
//   std::for_each(setOfDepartments.begin(), setOfDepartments.end(), );

   // Now Try to change the element

   std::set<std::string>::iterator it = setOfDepartments.find("Second");
   if(it != setOfDepartments.end())
   {
      std::cout << std::endl<< *it;
      //*it = "Fourth"; // NOT ALLOWED
   }

}
int main()
{
   example1();
   return 0;
}
