#include<iostream>

class Base {

  public:
    virtual char* getName() { return "Base"; }
 
};

class child : public Base {

  public:
    virtual char* getName() { return "Child"; }

    char* speak() { return "cry"; }
};

int main() {

  std::cout << sizeof(Base) ;

  Base* obj = new child;

  obj->getName();

 return 0;
}
