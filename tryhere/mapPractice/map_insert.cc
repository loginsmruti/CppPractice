#include<map>
#include<iostream>


struct Compare {

  bool operator()(const std::string lhs ,const std::string rhs) const{
    return lhs < rhs;
  }
};

int main()
{
  std::map<std::string , int> mapElem;
  std::pair<std::map<std::string , int>::iterator , bool> result;

  mapElem.insert(std::make_pair("vicky", 1));
  mapElem.insert(std::pair<std::string , int>("rocky", 2));
  mapElem.insert(std::pair<std::string , int>("mama", 3));
  mapElem.insert(std::make_pair("baba", 4));
  mapElem["member"] = 5;

  
  std::cout << "=============" << std::endl;
  for(std::pair<std::string , int> pairVal : mapElem) {
    std::cout << pairVal.first << " ::: " << pairVal.second ;
  }

  std::cout << "\n=============" << std::endl;
  mapElem.erase("member");
  auto itr = mapElem.find("vicky");
  
  if(itr != mapElem.end()) {
    itr = mapElem.erase(itr);
  }
  

  std::cout << "=============" << std::endl;
  std::for_each(mapElem.begin() , mapElem.end() , [](const std::pair<std::string , int>& pairVal) {
      std::cout << pairVal.first << ":::" << pairVal.second ;
    });


  std::map<std::string , int , Compare> familyMembers;
  familyMembers.insert(std::make_pair("vicky", 1));
  familyMembers.insert(std::pair<std::string , int>("rocky", 2));
  familyMembers.insert(std::pair<std::string , int>("mama", 3));
  familyMembers.insert(std::make_pair("baba", 4));
  familyMembers["member"] = 5;

  std::cout << "=============" << std::endl;

  return 0;
}
