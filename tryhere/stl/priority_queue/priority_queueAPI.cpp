#include <queue>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

class StringComparator {
    private:
        bool reverse;
    public:
        StringComparator(bool reverse = false) : 
                        reverse(true) 
                                {}
        bool operator()(const std::string& lhs, const std::string& rhs) const {
            // Compare each character of the strings one by one
/*           
            size_t i = 0;
            while (i < lhs.length() && i < rhs.length()) {
               char c1 = std::tolower(lhs[i]);
               char c2 = std::tolower(rhs[i]);
               if (c1 != c2) {
                   if(reverse)
                       return c1 > c2;
                   else
                       return c1 < c2;
               }    
               ++i;
            }
            // If both strings are equal up to the length of the shortest string,
            // the shorter string should be considered less.
            return lhs.length() < rhs.length(); */
            return reverse ? (lhs > rhs) : (lhs < rhs);
        }

};


int main(int argc, char const *argv[])
{
    std::vector<std::string> strings = {"Banana", "apple", "banana", "Apple"};
    std::vector<int> vectOfInts ({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15});

    std::priority_queue<int> myPq;

    //std::priority_queue<std::string, std::vector<std::string>, StringComparator> pqString(strings);

    std::priority_queue<int, std::vector<int>, std::less<int>> pqGreatInt;

    typedef std::priority_queue<std::string, std::vector<std::string>, StringComparator>  MyPqString;

    MyPqString myPqString;
    myPqString.push("apple");
    myPqString.push("banana");
    myPqString.push("papaya");
    myPqString.push("grapes");
    myPqString.push("kiwi");
    myPqString.push("pinaple");
    myPqString.push("guava");

    MyPqString myPqRevString(StringComparator(true));
    myPqRevString.push("apple");
    myPqRevString.push("banana");
    myPqRevString.push("papaya");
    myPqRevString.push("grapes");
    myPqRevString.push("kiwi");
    myPqRevString.push("pinaple");
    myPqRevString.push("guava");


    //Element access
        //top
        pqGreatInt.push(1);
        pqGreatInt.push(2);
        pqGreatInt.push(3);
        pqGreatInt.push(4);
        pqGreatInt.push(5);
        pqGreatInt.push(6);
        pqGreatInt.push(7);
        pqGreatInt.push(8);
        pqGreatInt.push(9);
        pqGreatInt.push(10);
        std::cout << "\n pqGreatInt.top(): " << pqGreatInt.top() << std::endl;
        //capacity
            //empty
            //size
        std::cout << "\n pqGreatInt.size(): " << pqGreatInt.size() << std::endl;
        std::cout << "\n Print pqGreatInt: ";
        while (!pqGreatInt.empty()) {
            std::cout  << pqGreatInt.top() << " ";
            pqGreatInt.pop();
        }

        std::cout << "\n SIZE: " << pqGreatInt.size() << std::endl;
        
  
    //modifiers
        //push
        //pop
        //emplace
        myPqString.emplace("Jackfruit");
        myPqRevString.emplace("Mango");
        //swap
            //void swap (priority_queue& x) noexcept (/*see below*/);

        std::cout << "\n Final print myPqString.size(): " << myPqString.size() << std::endl;
        std::cout << "\n Final Print myPqString: ";
        while (!myPqString.empty()) {
            std::cout  << myPqString.top() << " ";
            myPqString.pop();
        }
        std::cout << std::endl;

        std::cout << "\n Final print myPqRevString.size(): " << myPqRevString.size() << std::endl;
        std::cout << "\n Final Print myPqRevString: ";
        while (!myPqRevString.empty()) {
            std::cout  << myPqRevString.top() << " ";
            myPqRevString.pop();
        }
        std::cout << std::endl;

    return 0;
}
