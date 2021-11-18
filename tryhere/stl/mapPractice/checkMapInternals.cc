#include <iostream>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>

void example2()
{
   // Map of Department and Employee count in that Department
   std::map< int , std::string> mapOfDepEmpCount;

   mapOfDepEmpCount.insert(std::make_pair(0 , "First" ) );
   mapOfDepEmpCount.insert(std::make_pair(1 , "Second") );
   mapOfDepEmpCount.insert(std::make_pair(2 , "Third" ) );

   std::map< int , std::string >::iterator it = mapOfDepEmpCount.find(0);
   if(it != mapOfDepEmpCount.end())
   {
      //std::cout << std::endl << "Department = "<< it->first << " :: No. Of Employees = " << it->second << std::endl;
      // You can change the value associated with the key
      it->second = "1st";
      //it->first = "sss"; // You cannot chage the key
   }
   
   it = mapOfDepEmpCount.find(1);
   if(it != mapOfDepEmpCount.end())
   {
      //std::cout << std::endl << "Department = "<< it->first << " :: No. Of Employees = " << it->second << std::endl;
      // You can change the value associated with the key
      it->second = "2nd";
      //it->first = "sss"; // You cannot chage the key
   }
   
   it = mapOfDepEmpCount.find(2);
   if(it != mapOfDepEmpCount.end())
   {
      //std::cout << std::endl << "Department = "<< it->first << " :: No. Of Employees = " << it->second << std::endl;
      // You can change the value associated with the key
      it->second = "3rd";
      //it->first = "sss"; // You cannot chage the key
   }
   
   it = mapOfDepEmpCount.begin();
   while(it != mapOfDepEmpCount.end())
   {
      std::cout << std::endl << "Department = "<< it->first << " :: No. Of Employees = " << it->second << std::endl;
      it++;
   }
}

int main()
{
   example2();
   return 0;
}

