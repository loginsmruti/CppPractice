#include <iostream>
#include <unordered_set>
#include <algorithm>

//requires c++11 compiler

// Custom Hash Functor that will compute the hash on the
// passed string objects length
struct StringHashBySize {
   public:
      size_t operator()(const std::string & str) const {
         int size = str.length();
         return std::hash<int>()(size);
      }
};

// Custom comparator that compares the string objects by length
struct StringEqualBySize {
   public:
      bool operator()(const std::string & str1, const std::string & str2) const {

         if (str1.length() == str2.length())
            return true;
         else
            return false;
      }
};

int main() {
   // Declaring unordered_set with Custom Hash Function and comparator
   std::unordered_set<std::string, StringHashBySize, StringEqualBySize> setOfStrs;

   setOfStrs.insert("First");
   setOfStrs.insert("second");

   // Try to insert element with same length as "First"
   // It will not be added
   setOfStrs.insert("third");

   // Try to insert element with same length as "Second"
   // It will not be added

   setOfStrs.insert("second");
   setOfStrs.insert("five");

   // Only three elements are added in set
   // Display them
   for (std::string s : setOfStrs)
      std::cout << s << std::endl;
}
