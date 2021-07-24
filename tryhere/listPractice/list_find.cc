#include<iostream>
#include<list>
#include<algorithm>
#include<iomanip>

struct Person {
  int id;
  std::string name;

  Person(int mob , std::string myName) 
    : id(mob),
      name(myName)
  {  }

  bool operator<(const Person& lhs ) const {
   return id < lhs.id; 
  }
};

struct PersonComparator {
  
  bool operator()(const Person& lhs ,const Person& rhs) {
    if(lhs.name == rhs.name) 
      return lhs < rhs;
    
    return lhs.name < rhs.name;
  }
};

template<typename T>
bool findMe(std::list<T> myValues, const T& elem) {
  
  auto it  = std::find(myValues.begin() , myValues.end() , elem);
  
 return it != myValues.end(); 
}

int main()
{
  std::list<std::string> name({"name" , "address" , "block" , "lane" , "pin", "parents_name","house number" , "city"});

  std::list<int> number({1,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 , 10 , 11 , 12 , 13, 14 ,15 ,1 , 22 ,3 ,3 ,4 ,6 ,4 , 5 ,6 });
  std::list<int>::iterator it ;

   number.erase(std::remove(number.begin() , number.end() , 6) , number.end());
  
   it = number.begin();

  for(auto intValues : number) {
    std::cout << intValues << " " ;
  }
  std::cout<< std::endl;
  
  auto itr = std::find(name.begin() , name.end() , "paarents_name");
  if(itr != name.end()) {
    name.erase(itr);
  }


  std::for_each(name.rbegin() , name.rend() , [](const std::string& addressComponents) {
        std::cout << " " << addressComponents;
      });
  std::cout<< std::endl;


  std::list<Person> listofPlayers = { Person(22, "Sid"),
                                      Person(3, "Laura"),
                                      Person(43, "Riti"),
                                      Person(30, "Angel"),
                                      Person(2, "Laura"),};
    

  std::for_each(listofPlayers.begin() , listofPlayers.end() , [](const Person& person) {
        std::cout << person.id << " : " << person.name << std::endl;
      });


  //default comparator 
  listofPlayers.sort();

  std::cout << "Default Comparator" <<std::endl; 
  std::for_each(listofPlayers.begin() , listofPlayers.end() , [](const Person& person) {
        std::cout << person.id << " : " << person.name << std::endl;
      });
  std::cout << std::endl; 

  //comparator using lambda function
  std::cout << "Comparator using lambda function" <<std::endl; 
  listofPlayers.sort([](const Person& p1 , const Person& p2) {
        if(p1.name == p2.name)
          return p1< p2;

          return p1.name < p2.name;
       
      }); 

  std::for_each(listofPlayers.begin() , listofPlayers.end() , [](const Person& person) {
        std::cout << person.id << " : " << person.name << std::endl;
      });
  std::cout << std::endl; 
  
  //custom comparator
  std::cout << "Comparator using custom comparator" <<std::endl; 
  listofPlayers.sort(PersonComparator());
   
  std::for_each(listofPlayers.begin() , listofPlayers.end() , [](const Person& person) {
        std::cout << person.id << " : " << person.name << std::endl;
      });
  std::cout << std::endl; 

  return 0;
}
