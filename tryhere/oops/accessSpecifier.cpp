#include<iostream>

class Container
{
  private:
    int i;

  public:
    void setValue(int value) {
      i = value;
    }
    int& getValue() { return i; }
};


int main() {

  Container obj;
  obj.setValue(5);

  int &myValue = obj.getValue();

  myValue += 1;

  std::cout << "My Vlaue :: " << myValue << std::endl; 
  return 0;
}

