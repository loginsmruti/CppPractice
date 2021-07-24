#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
int main()
{
   std::vector<int> vecArr;
   std::vector<int>::iterator it;
   
   for(int i = 1; i <= 10; i++)
      vecArr.push_back(i);

    it = vecArr.begin();
   for(; it != vecArr.end(); it++)
      std::cout<<(*it)<<"  ";

   std::cout<<std::endl;

   it = vecArr.begin();

   // Insert an element in position 2,
   vecArr.insert ( it + 2 , 1 , 200 );
   
   it = vecArr.begin();

   // Now old iterator it has become invalidated
   // SO, using it as it is can result in undefined behavior

   for(; it != vecArr.end(); it++)   // Undefined Behavior
      std::cout<<(*it)<<"  ";          // Undefined Behavior

   return 0;
}
