#include<iostream>

class Base
{
  public:
    // This version of getThis() returns a pointer to a Base class
    virtual Base* getThis() { std::cout << "Base::getThis()\n"; return this; }
};

class Derived: public Base
{
  public:
  // Normally override functions have to return objects of the same type as the base function
  // However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
  virtual Derived* getThis() { std::cout << "Derived::getThis()\n"; return this; }
};

int main()
{
  Base *base = new Base;
  base->getThis();

  Derived *drvd = new Derived;
  drvd->getThis();  

  Base* dBase = new Derived();
  dBase->getThis();

  return 0;
}
