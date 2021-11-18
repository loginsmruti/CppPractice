#include<iostream>
#include<vector>

class StringInitializer
{
  public:
    StringInitializer(const std::initializer_list<std::string>& names)
      : stringName(names)
    { }

    void displayString()
    {
      for(const std::string& names : stringName) {
        std::cout << names <<" ";
      }
      std::cout << "\n";
    }
  private:
    std::vector<std::string> stringName;

};

int main(int argc , char* argv[])
{
  StringInitializer names = {"Vicky", "rocky", "mama" , "baba", "family" };

  names.displayString();
  
  return 0;
}
