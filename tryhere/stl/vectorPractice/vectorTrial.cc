#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::vector;

int main() {

  std::vector<int> numbers;
  std::vector<int>::iterator it;

  for(size_t i =0 ; i < 10 ; i++) {
    numbers.push_back(i);
  }

  it = numbers.begin();
  while(it != numbers.end())
  {
    cout << *it << ", ";
    it++;
  }
  cout << std::endl;


  for (size_t i = 0 ; i< numbers.size() ; i++) {
    cout << numbers.at(i) << ", ";
  }

  cout << std::endl;


  for (size_t i = 0 ; i< numbers.size() ; i++) {
    cout << numbers[i] << ", ";
  }


  std::vector<int> initInteger = {1 ,2 ,3 , 4 ,5};

  it = initInteger.begin();
  while(it != initInteger.end())
  {
    cout << *it << ", ";
    it++;
  }
  cout << std::endl;

  std::vector<int> initInteger1(10 , 2);

  for(const int &numbers : initInteger1) {
   
   cout << numbers << ", "; 
  }
  cout << std::endl;

  std::vector<int> initInteger2(10);

  for(const int &numbers : initInteger2) {
   
   cout << numbers << ", "; 
  }
  cout << std::endl;

  std::string nameArr[] = {"vicky" , "rocky" , "mama" , "baba" }; 

  std::vector<std::string> strName(nameArr , nameArr + (sizeof (nameArr) / sizeof(std::string)));
  for(const std::string &names : strName) {

    cout << names << ", ";
  }
  cout << std::endl;

  std::initializer_list<std::string> vectInitialize = {"string1" , "string2", "string3" , "string4" };
  
  std::vector<std::string> stringVector(vectInitialize);

  for(const std::string& str : stringVector) {

    std::cout << str << " , " ;

  }

  cout << std::endl;


  return 0;
}


