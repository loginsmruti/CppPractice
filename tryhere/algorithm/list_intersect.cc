// set_intersection example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector
#include <list>

int main () 
{
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  
  std::list<int> firstList(first , first + 5);
  std::list<int> secondList(second , second + 5);
  std::list<int> thirdList;
  std::list<int>::iterator it;
  std::sort (firstList.begin() , firstList.end());
  std::sort (secondList.begin() , secondList.end());

// it = std::set_intersection (firstList.begin() , firstList.end() , secondList.begin() , secondList.end(), thirdList.begin());
                                               
  thirdList.resize(thirdList.size());                      

  std::cout << "The intersection has " << (v.size()) << " elements:\n";
 
  for (it=thirdList.begin(); it!=thirdList.end(); ++it)
    std::cout << ' ' << *it;
  
  std::cout << '\n';
  
  //for (int it : thirdList)
  //  std::cout << ' ' << it;

  //std::cout << '\n';
  
  return 0;
}
