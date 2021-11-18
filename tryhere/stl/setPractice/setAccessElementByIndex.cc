#include<iostream>
#include<set>

template <typename T>
std::pair<T , bool> getNthIndexValue(std::set<T>& numbers , const int index)
{
  std::pair<T , bool> result;

  if(numbers.size() > index) {

    result.first  = *std::next(numbers.begin() , index);
    result.second = true;

  } else {
    
    result.second = false;
  } 

  return result; 
}


int main()
{
  std::set<int> numbers;
  std::pair<int , bool> result;

  numbers.insert(1);
  numbers.insert(2);
  numbers.insert(3);
  numbers.insert(4);
  numbers.insert(5);

  for(int num : numbers) {
    std::cout << num << " " ;
  }
  
  result = getNthIndexValue(numbers , 1);
  
  if(result.second == true) {
    std::cout << result.first << std::endl;
  }

  return 0;
}
