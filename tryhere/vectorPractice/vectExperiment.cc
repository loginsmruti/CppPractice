#include<iostream>
#include<vector>

struct Sample
{
  Sample() {}
  Sample(const Sample& obj) {
    std::cout << "Sample copy constructor called\n";
  }

  Sample& operator=(const Sample& obj)
  {
    if(this == &obj)
      return *this;

    return *this; 
  }

};

int main()
{
  std::vector<Sample> sampleObj;
  
  //sampleObj.reserve(6);  
  
  std::cout <<"capacity : " << sampleObj.capacity() << "size : " << sampleObj.size() << std::endl;
  int capacity = sampleObj.capacity()+1;
 
  for(int i =0; i < capacity + 1 ; i++) {
    sampleObj.push_back(Sample());
  }

  std::cout <<"capacity : " << sampleObj.capacity() << "size : " << sampleObj.size() << std::endl;

  std::vector<int> num = {1 , 2 ,3 , 4 ,5 ,6 , 7,  8 , 9 ,10 ,11};
  
  //print content
  for(int it : num) {
    std::cout << it << " ,";
  }
  std::cout << "\n";
  
  //find specified value & erase
  auto it = std::find(num.begin() , num.end() , 7);
   
  if(it != num.end())
    it = num.erase(it);

  //print content
  for(int it : num) {
    std::cout << it << " ,";
  }
  std::cout << "\n";

  it = num.begin();
  // Insert an element in position 2,
  num.insert( it + 2 , 1 , 200 );
  // Reinitialize the invalidated iterator to the begining.
  it = num.begin();

  //try the same through vector itartor
  std::vector<int>::iterator it1;
  
  //find specified value & erase
  it1 = std::find(num.begin() , num.end() , 6);

  if(it1 != num.end()) {
   
    it1 = num.erase(it1);
  }

  it1 = num.begin();

  //print content
  while(it1 != num.end()) {
    std::cout << *it1 << " ,";
    
    it1++;
  }
  std::cout << "\n";
  
  return 0;

}
