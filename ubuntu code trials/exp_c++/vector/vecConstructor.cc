// constructing vectors
#include <iostream>
#include <vector>

int main ()
{
    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

    std::cout << "First size::"<<first.size()<< std::endl;
    std::cout << "First capacity::"<<first.capacity()<< std::endl;


    std::cout << "second size::"<<second.size()<< std::endl;
    std::cout << "second capacity::"<<second.capacity()<< std::endl;

    std::cout << "third size::"    <<third.size()<< std::endl;
    std::cout << "third capacity::"<<third.capacity()<< std::endl;
    
    std::cout << "fourth size::"<<fourth.size()<< std::endl;
    std::cout << "fourth capacity::"<<fourth.capacity()<< std::endl;

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "fifth size::"<<fifth.size()<< std::endl;
    std::cout << "fifth capacity::"<<fifth.capacity()<< std::endl;
    
    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
