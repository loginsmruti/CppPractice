//Remove all occurences of an element from vector in O(n) complexity
#include<iostream>
#include<vector>
#include<algorithm>


void removeAllMatchingElements_nonEfficient(std::vector<int>& numbers , int elem)
{
  std::vector<int>::iterator it = numbers.begin();

  while(it != numbers.end()) {
  
    if(*it == elem) 
      it = numbers.erase(it);
    else
      it++;
  }

}

void removeAllMatchingElements_Efficient(std::vector<int>& numbers , int elem)
{
  numbers.erase(std::remove(numbers.begin() , numbers.end() , elem) , numbers.end());
}

void displayVector(std::vector<int>& num)
{
  std::vector<int>::iterator it = num.begin();

  while(it != num.end()) {
    std::cout<<(*it++)<<" ";
  }
  std::cout<<std::endl;
}

int main() 
{
  int array[] = { 1, 2, 5, 4, 5, 1, 5, 7, 8, 9, 5 , 5 };

  std::vector<int> numbers(array , array + (sizeof(array)/sizeof(int)) );
  displayVector(numbers);

  removeAllMatchingElements_nonEfficient(numbers , 5); //complexity will be O(n^2)

  std::vector<int> vec2(array , array + 10);
  removeAllMatchingElements_Efficient(vec2, 5); //requires O(n) complexity.
  displayVector(vec2);

  return 0;
}

