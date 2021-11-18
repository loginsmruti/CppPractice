#include<iostream>
#include<list>
#include<initializer_list>

int main()
{
  std::list<int> integer;
  std::initializer_list<std::string> name = {"vicky" , "mama" , "baba" , "rocky" , "family"};

  std::list<std::string> myString(name);
  std::list<std::string>::iterator itr = myString.begin();


  //std::advance() 
  myString.insert(itr , "members");

  for(size_t i = 0 ; i<10 ; i++) {
    integer.push_back(i);
  }

  for(size_t i = 10 ; i > 0 ; i--) {
    integer.push_front(i);
  }

  std::for_each(integer.begin() , integer.end() , [](int value) {
      std::cout << value << " "; 
      });
  
  std::cout << std::endl;

  std::copy(myString.begin() , myString.end() , std::ostream_iterator<std::string>(std::cout << " "));

  std::cout << std::endl;

  for(int value : integer) {

    std::cout << value << " ";
  }
  
  std::cout << std::endl;

  //erase elements whille iterating
  auto it = std::find(myString.begin(), myString.end(), "vicky");

  if(it != myString.end()) {
    it = myString.erase(it);
  }
  
  for(std::string value : myString) {

    std::cout << value << " " ;
  }

  std::cout << std::endl;
  //How to get element by index in List, std::list doesn’t have operator []

  auto index = myString.begin();
  std::advance(it , 2);  
  if(it != myString.end()) {
    std::cout << *it << std::endl ;
  }

  std::cout << std::endl;

  auto index1 = std::next(myString.begin(), 2);

  if(index1 != myString.end()) {
    std::cout << *index1 << std::endl ;
  }



  return 0;

}
