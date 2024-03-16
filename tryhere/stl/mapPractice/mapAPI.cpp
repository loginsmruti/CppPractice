#include <iostream>
#include <map>
#include <iterator>
#include <string> 
#include <utility>

template <typename k, typename v>
auto print = [] (std::string str, const std::map<k,v>& container) {
    std::cout << str;
    for(const auto & val : container) {
        std::cout << "\nval.first: " << val.first << "\tval.second: " << val.second;
    }
    std::cout << std::endl;
};

auto lambdaComparator = [] (int lhs,  int rhs) -> bool {
    return lhs > rhs;
};

bool externalComparator( int lhs,  int rhs) {
    return lhs > rhs;
}

struct FuncObjExternalComparator
{
     bool operator()( int lhs,  int rhs) const {
        return lhs > rhs;
    }
};


int main(int argc, char const *argv[])
{
    //Constructor
        std::map<int, std::string> map2 {{1, "Vicky"}, 
        {2, "Rocky"}, {3, "Mama"}, 
        {4, "baba"}, {5, "subha"}, 
        {6, "sanvi"}, {7, "badaV"}, {8, "chhotaV"}};
        //empty
        std::map<int , std::string> map1;
        //range
        std::map<int, std::string, std::less<int>> map3(map2.begin(), map2.end());
        //copy
        std::map<int, std::string> map4(map3);
        //move
        std::map<int, std::string> (std::move(map4));
        
        //using external comparator
        // 1.>
        std::map<int, std::string, decltype(lambdaComparator)> mapComparator1{
            {1, "Vicky"}, 
        {2, "Rocky"}, {3, "Mama"}, 
        {4, "baba"}, {5, "subha"}, 
        {6, "sanvi"}, {7, "badaV"}, {8, "chhotaV"}};
        
        // 2.>
        bool (*funcPointer)( int, int) = externalComparator;
        std::map<int, std::string, bool(*)(int, int)> mapComparator2;
        
        // 3.>
        std::map<int, std::string, FuncObjExternalComparator> mapComparator3;
         mapComparator3.insert(std::make_pair<int, std::string>(0 , "First" ) );
         mapComparator3.insert(std::make_pair<int, std::string>(1 , "Second") );
         mapComparator3.insert(std::make_pair<int, std::string>(2 , "Third" ) );
    //derstructor
        //~map()


    //Iterator
        //begin
        //end
        //cbegin
        //cend
        //rbegin
        //rend
        //crbegin
        //crend
        std::cout << "Map Content: " ;
        //std::copy(mapComparator3.begin(), mapComparator3.end(), std::ostream_iterator<std::pair<int, std::string>>(std::cout, " "));
        std::map<int, std::string, FuncObjExternalComparator>::iterator it = mapComparator3.begin();
        while (it != mapComparator3.end()) {
            std::cout << "\n" << it->first << " " << it->second;
            it++;
        }
        std::cout << std::endl;

    //Element Access
        //at
        //operator
        std::map<int, std::string> myMap1;
        myMap1.insert(std::make_pair<int, std::string>(1, "A"));
        myMap1.insert(std::make_pair<int, std::string>(2, "B"));
        myMap1.insert(std::make_pair<int, std::string>(3, "C"));
        myMap1.insert(std::make_pair<int, std::string>(4, "D"));
        myMap1.insert(std::make_pair<int, std::string>(5, "E"));
        myMap1.insert(std::make_pair<int, std::string>(6, "F"));
        myMap1.insert(std::make_pair<int, std::string>(7, "G"));
        myMap1.insert(std::make_pair<int, std::string>(8, "H"));
        myMap1[10] = "I";
        myMap1[11] = "J";

        //std::ostream_iterator<std::pair<const int, std::string>> out_it(std::cout, " ");
        //std::copy(myMap1.begin(), myMap1.end(), out_it);
        std::cout << "\n Print via range based loop: \n";
        for(const std::pair<int, std::string>&  mapVal: myMap1) {
         std::cout << "\nmapVal.first: " << mapVal.first << "\tmapVal.second: " << mapVal.second;    
        }

        std::cout << "\nPrint via for_each:\n";
        for_each(myMap1.begin(), myMap1.end(), [](const std::pair<int, std::string>&  mapVal) {
            std::cout << "\nmapVal.first: " << mapVal.first << "\tmapVal.second: " << mapVal.second; 
        });

        std::map<int, std::string>::iterator loopItr = myMap1.begin();
        while(loopItr != myMap1.end()) {
            std::cout << "\nloopItr->first: " << loopItr->first << "\tloopItr->second: " << loopItr->second;
            loopItr++;
        }

    //Capacity
        //empty
        //size
        //max_size
        if(!myMap1.empty()) {
            std::cout << "\nSIZE: " << myMap1.size();
            std::cout << "\nmax_size: " << myMap1.max_size() << "\n";
        }
        
    //Modifiers
        //clear
        //insert
        myMap1.insert(myMap1.begin(), std::make_pair<int, std::string>(12, "K"));
        myMap1.insert(myMap1.begin(), std::make_pair<int, std::string>(13, "L"));

        std::pair< std::map<int, std::string>::iterator, bool > retPair;

        retPair = myMap1.insert(std::make_pair<int, std::string>(14, "M"));
        if(retPair.second)
            std::cout << "\n <Key, Value> pair inserted successfully." << std::endl;

        auto myIterator = myMap1.insert(myMap1.begin(), std::make_pair<int, std::string>(14, "M"));
        std::cout << "myIterator->first: " << myIterator->first << "\tmyIterator->second: " << myIterator->second;

        
        //erase

        size_t result = myMap1.erase(14);
        if(result == 1 ) {
            std::cout << "\nKey erased." << std::endl;
        } else {
            std::cout << "\nFailed to erase the key.\n";
        }

        std::map<int, std::string>::iterator eraserItr = myMap1.begin();
        myMap1.erase(eraserItr);
        print<int, std::string>("Pre erase:", myMap1);
        myMap1.erase(++myMap1.begin(), --myMap1.end());

        print<int, std::string>("Post erase:", myMap1);
        //swap
        map2.swap(myMap1);
        print<int, std::string>("map2 post swap:", map2);
        print<int, std::string>("myMap1 post swap:", myMap1);
        
        //emplace
            //emplace_hint
            //map2.empalce(9, "Hi--V");
            //map2.emplace_hint(map2.end(), 10, "Bye--V");
            //print<int, std::string>("emplace_&_emplace_hint: ", map2);

    //List Operation

    //Lookup
        //count
        std::cout << "myMap1.count(): " << myMap1.count(4);
        //find
        auto removeItr = myMap1.find(4);
        myMap1.erase(removeItr);
        print<int, std::string>("find & remove: ", myMap1);
        //lower_bound
        auto lowerBoundItr = myMap1.lower_bound(3);
        //upper_bound
        auto upperBoundItr = myMap1.upper_bound(6);
        auto boundItr = myMap1.erase(lowerBoundItr, upperBoundItr);
        boundItr = myMap1.begin();
        print<int, std::string>("lowe_upper_bound_operation:  ", myMap1);
        
        //equal_range
        std::map<char,int> mymap;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';

    //Observer
        //key_comp
        //value_comp

    //Allocator
        //get_allocator


    return 0;
}
