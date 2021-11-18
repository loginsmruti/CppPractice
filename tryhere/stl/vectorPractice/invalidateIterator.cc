#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
int main()
{
   std::vector<int> vecArr;
   std::vector<int>::iterator  it;

   for(int i = 1; i <= 10; i++)
      vecArr.push_back(i);

   for(it = vecArr.begin(); it != vecArr.end(); it++)
      std::cout<<(*it)<<"  ";

   std::cout << std::endl;

   // Erase and element with value 5.
   it = std::find(vecArr.begin(), vecArr.end(), 5);
   if(it != vecArr.end())
      it = vecArr.erase(it); //solution to iterator invalidation

   // Now iterator 'it' is invalidated because it still points to
   // old location, which has been deleted. So, if you will try to
   // do the use the same iterator then it can show undefined
   // behavior.

   for( ; it != vecArr.end(); it++)   // Unpredicted Behavior
      std::cout<<(*it)<<"  ";          // Unpredicted Behavior

   return 0;
}
