#include <string>

class Something
{
   private:
      std::string m_value = "vicky"; //only possible in c++11 (in-class member initializers)

   public:
      Something(const std::string &value="") { m_value= value; } 

      const std::string& getValue() const { return m_value; } // getValue() for const objects
      std::string& getValue() { return m_value; } // getValue() for non-const objects
};

int main()
{
   //std::string myString("Hi"); 
   //Something something(myString);
   //something.getValue() = "Hi"; // calls non-const getValue();

   Something something;
   something.getValue() = "Hi"; // calls non-const getValue();
   
   const Something something2;
   something2.getValue(); // calls const getValue();

   const std::string mVal(something2.getValue()); 
    
   std::string trial = mVal;

   return 0;
}
