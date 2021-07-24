#include <string>
#include <iostream>

class Animal // This Animal is an abstract base class
{
  protected:
    std::string m_name;

  public:
    Animal(std::string name)
      : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // note that speak is now a pure virtual function
};

class Cow: public Animal
{
  public:
    Cow(std::string name)
      : Animal(name)
    {
    }

    virtual const char* speak() { return "Moo"; }
};

int main()
{
  Cow cow("Betsy");
  std::cout << cow.getName() << " says " << cow.speak() << '\n';
}
