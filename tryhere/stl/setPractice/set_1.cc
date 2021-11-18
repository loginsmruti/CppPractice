#include<iostream>
#include<set>

int main()
{
  std::set<int> numbers;
  std::set<int>::iterator it;
  std::pair<std::<set>::iterator, bool> setPair;
   
  setPair = numbers.insert(1);
  it = setPair.first;
  
  if(setPair.second == true) {
    std::out <<  "Element " << *it << "inserted" << "\n";
  } else {
    std::out <<  "Element failed to insert\n";
  } 

  numbers.insert(1);
  numbers.insert(2);
  numbers.insert(2);

  return 0;
}
