#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>


template <typename K, typename V>
auto print = [] (std::string str , const std::unordered_map<K, V>& container) {
    std::cout << str;
    for(const auto& containerVal: container) {
        std::cout << containerVal.first << " : " << containerVal.second << "\n";
    }
    std::cout << std::endl;
};

int main(int argc, char const *argv[])
{
    //Constructor
        //initializer_list
        std::unordered_map<int, std::string, std::hash<int>, std::equal_to<int>> initUdMap({{1, "A"},
                                                        {2, "B"}, {3, "C"}, {4, "D"},{5, "E"},
                                                        {6, "F"}, {7, "G"}, {8, "H"}, {9, "I"} });
        //empty
        std::unordered_map<int, std::string> emptyUdMap;
        
        //range
        std::unordered_map<int, std::string> rangeMap(initUdMap.begin(), initUdMap.end());

        //copy
        std::unordered_map<int , std::string> copyUdMap(rangeMap);

        //move
        std::unordered_map<int , std::string> moveUdMap(std::move(copyUdMap));


    //Destructor
        //~unordered_set

    //Iterator
        //begin
        //cbegin
        //rbegin
        //crbegin
        //cend
        //rend
        //crend
        
        for(const auto& udm: moveUdMap) {
            std::cout << "\nudm.first: " << udm.first << " udm.second: " << udm.second;
        }
        for(const std::pair<int, std::string>& udmPair: moveUdMap) {
            std::cout << "\nudmPair.first: " << udmPair.first << " udmPair.second: " << udmPair.second;
        }
        std::unordered_map<int, std::string>::iterator iter = moveUdMap.begin();
        while(iter != moveUdMap.end()) {
            std::cout << "\niter->first: " << iter->first << " iter->second: " << iter->second << std::endl;

            iter++;
        }
        for_each(moveUdMap.begin(), moveUdMap.end(), [](const std::pair<int, std::string>& udMapIter) {
            std::cout << "\nfor_each iterator: " << udMapIter.first <<" " << udMapIter.second;
        });
    //Element Access
        //at
        //operator[]
        moveUdMap[10] = "k";
        moveUdMap.at(1) = "a"; 
    //Capacity
        //empty
        //size
        //max_size
        if(!moveUdMap.empty()) {
            std::cout << "\nSIZE: " << moveUdMap.size();
            std::cout << "\nmax_size: " << moveUdMap.max_size() << "\n";
            print<int, std::string>("unordered_map capacity: ", moveUdMap);
        }

    //Modifiers
        //clear
        //insert
            /*
             *   (1)	pair<iterator,bool> insert ( const value_type& val );
             *   (2)	template <class P>    pair<iterator,bool> insert ( P&& val );
             *   (3)	iterator insert ( const_iterator hint, const value_type& val );
             *   (4)	template <class P>    iterator insert ( const_iterator hint, P&& val );
             *   (5)	template <class InputIterator>    void insert ( InputIterator first, InputIterator last );
             *   (6)	void insert ( initializer_list<value_type> il );
             * 
             */
            //hint based    
            moveUdMap.insert(moveUdMap.begin(), std::make_pair<int, std::string>(12, "K"));
            moveUdMap.insert(moveUdMap.begin(), std::make_pair<int, std::string>(13, "L"));
            //single element insertion
            std::pair< std::unordered_map<int, std::string>::iterator, bool > retPair;
            retPair = moveUdMap.insert(std::pair<int, std::string>(14, "M"));
            if(retPair.second)
                std::cout << "\n <Key, Value> pair inserted successfully." << std::endl;

            auto myIterator = moveUdMap.insert(moveUdMap.begin(), std::make_pair<int, std::string>(14, "M"));
            std::cout << "myIterator->first: " << myIterator->first << "\tmyIterator->second: " << myIterator->second;
        //erase
            /**
             * 
             * by position (1)	iterator erase ( const_iterator position );
             * by key      (2)  size_type erase ( const key_type& k );
             * range       (3)  iterator erase ( const_iterator first, const_iterator last );
             * 
             */
            
            moveUdMap.erase(moveUdMap.begin());
            size_t n = moveUdMap.erase(12);
            if(n) {
                std::cout << "\n <Key, Value> pair erased successfully." << std::endl;
            }
            moveUdMap.erase(++moveUdMap.begin(), moveUdMap.end());
            moveUdMap[14] = "M";
        
        std::unordered_map<int, std::string> unMap1({{1, "A"},
                                                        {2, "B"}, {3, "C"}, {4, "D"},{5, "E"},
                                                        {6, "F"}, {7, "G"}, {8, "H"}, {9, "I"} });
        std::unordered_map<int, std::string> unMap2({{10, "A"},
                                                        {20, "B"}, {30, "C"}, {40, "D"},{50, "E"},
                                                        {60, "F"}, {70, "G"} });

        //swap
        std::unordered_map<int, std::string> myUdMap;
        myUdMap[1] = "a";
        myUdMap[2] = "b";
        myUdMap[3] = "c";
        myUdMap[4] = "d";

        unMap1.swap(unMap2);
        //emplace
        unMap2.emplace(5, "e");
        //emplace_hint
        unMap2.emplace_hint(myUdMap.end(), 6, "f");

        print<int , std::string>("\nPrint unMap1 container: ", unMap1);
        print<int , std::string>("\nPrint unMap2 container: ", unMap2);

    //List Operation

    //Lookup
        //count
        std::cout << "\nmyUdMap.count(): " << unMap1.count(40);
        //find
        auto foundItr = unMap1.find(30);
        std::cout << "\nFound unordered_map it: " << foundItr->first << " " << foundItr->second;
        //equal_range
        typedef std::unordered_map<int, std::string>::iterator UDMIterator;
        std::pair<UDMIterator, UDMIterator> UDMret = unMap1.equal_range(30);
        std::cout << "\nUDMret.first: " << UDMret.first->first << "\nUDMret.second: " << UDMret.second->second;

    //Observers
        //hash_function
        std::unordered_map<int, std::string>::hasher fn = unMap1.hash_function();
        std::cout << "\nHasher val: " << fn(10);

        //key_eq
        std::unordered_map<std::string,std::string> mymap;
        bool case_insensitive = mymap.key_eq()("test","TEST");

        std::cout << "mymap.key_eq() is ";
        std::cout << ( case_insensitive ? "case insensitive" : "case sensitive" );
        std::cout << std::endl;
    //Allocators
        //get_allocator

    return 0;
}
