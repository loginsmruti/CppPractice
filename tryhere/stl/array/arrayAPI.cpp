#include<array>
#include <iostream>
#include <iterator>
#include <experimental/iterator>

int main() 
{

    //You can construct the array via its constructors & You can only modify the std::array by swap API, at, operator[], front, back
    //The irony is there is no other API available to modify the std::aray

//Constructor
    //default initialization
    std::array<int , 5> myArray = {0};
    
    //initializer list
    std::array<int, 5> myArray_2({1, 2, 3, 4, 5});

    //copy initialization
    std::array<int, 5> myArray_1 = myArray_2;

//Destructor

//Iterator
    //begin
    //cbegin
    //rbegin
    //crbegin
    //end
    //cend
    //rend
    //crend
    std::array<int, 5>::iterator it = myArray_2.begin();
    while (it != myArray_2.end())
    {
        std::cout << *it << "\n";
        it++;
    }
    std::cout << std::endl;

    std::copy(myArray_2.begin(), myArray_2.end(), std::ostream_iterator<int>(std::cout, " ") );

    for (const auto& i : myArray_2)
        std::cout << i ;
    
    std::cout << std::endl;
    for(size_t i = 0 ; i < myArray_2.size(); i++)
        std::cout << myArray_2[i] << ':';
    std::cout << std::endl;

    

//Element Access
    //at
    //operator
    //front
    //back
    for (size_t i = 0; i< myArray_2.size(); i++) {
        myArray_2.at(i) = myArray_2.at(i) + myArray_2[i] + myArray_2.back() + myArray_2.front();
    }
    std::copy(myArray_2.begin(), myArray_2.end() , std::ostream_iterator<int>(std::cout, "/"));

//Capacity
    //empty
    //size
    //max_size
    std::cout << "\n";
    std::cout << std::boolalpha << myArray_2.empty() << std::endl;

    std::cout << "size: " << myArray_2.size() << " max_size: " << myArray_2.max_size() << std::endl;

//Modifier
    //swap
    myArray.swap(myArray_2);

    std::copy(myArray.begin() , myArray.end(), std::ostream_iterator<int>(std::cout, "/"));
    std::cout << std::endl;

    std::copy(myArray_2.begin(), myArray_2.end(), std::experimental::make_ostream_joiner(std::cout, ",")); //prints {0,0,0,0,0}
    std::cout << std::endl;

//List Operations

//LookUp

//Observers

//Allocator

}
