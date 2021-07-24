#include<vector>
#include<iostream>

int main()
{
    std::vector<int> vecInteger;
    std::vector<int> vecIntegerCtr;
    std::vector<int>::iterator vecItr;
    std::vector<int>::iterator vecItrCtr;
    
    vecInteger.assign(7 , 100);

    vecItr = vecInteger.begin();

    for( ; vecItr != vecInteger.end() ; vecItr++ ) {
        std::cout << *vecItr << " "; 
    }
    std::cout << "\nSize ::" << vecInteger.size() << std::endl; 

    int arr[] = {101 , 102 , 103 ,104 , 105};
    vecIntegerCtr.assign(arr , arr+5); 

    vecItrCtr = vecIntegerCtr.begin();

    for( ; vecItrCtr != vecIntegerCtr.end() ; vecItrCtr++ ) {
        std::cout << *vecItrCtr << "  "; 
    }
    std::cout << "\nSize ::" << vecIntegerCtr.size() << std::endl; 

    vecIntegerCtr.assign(vecInteger.begin() , vecInteger.end());

    vecItrCtr = vecIntegerCtr.begin();

    for( ; vecItrCtr != vecIntegerCtr.end() ; vecItrCtr++ ) {
        std::cout << *vecItrCtr << "    "; 
    }
    std::cout << "\nSize ::" << vecIntegerCtr.size() << std::endl; 

    return 0;
}
