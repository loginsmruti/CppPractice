#include<iostream>
#include<vector>
#include<string>

typedef std::vector<int> VectorOfInts;
typedef VectorOfInts::iterator VectorIterator;

typedef std::vector<string> VectorOfStrings;
typedef VectorOfStrings::iterator VectorOfStringIterator;

int main()
{
    // This is a vector of int
     VectorOfInts vecOfInts;

    // While Adding it automatically adjusts it's size
    for(int i = 0; i < 10; i++)
        vecOfInts.push_back(i);
   
    VectorIterator vectorItr = vecOfInts.begin();

    for( ;vectorItr != vecOfInts.end() ; vectorItr++)
        std::cout << " " << *vectorItr << std::endl;

    std::string names[] = {"vicky" , "rocky" , "mama"};

    VectorOfStrings stringNames(names , names + sizeof(names)/sizeof(std::string));


    VectorOfStrings initStrings(sizeof(names)/sizeof(std::string) , "Vicky");

    VectorOfStringIterator strItr = stringNames.begin();

    for(;strItr!= stringNames.end() ; strItr++)
        std::cout << *strItr << std::endl ;

    VectorOfStringIterator initStrItr = initStrings.begin();

    for(;initStrItr != initStrings.end() ; initStrItr++)
        std::cout << *strItr << std::endl;

    return 0;
}
