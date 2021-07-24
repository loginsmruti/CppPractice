#include <string>
#include <iostream>

#include <string>
#include <iostream>

class MyString
{
   private:
      std::string m_string;
   public:
      explicit MyString(int x) // allocate string of size x
      {
         m_string.resize(x);
      }

      explicit MyString(const char *string) // allocate string to hold string value
      {
         m_string = string;
      }

      friend std::ostream& operator<<(std::ostream& out, const MyString &s);

};

std::ostream& operator<<(std::ostream& out, const MyString &s)
{
   out << s.m_string;
   return out;
}

int main()
{
   MyString x = "x"; // use copy initialization for MyString
   std::cout << x;
   return 0;
}
