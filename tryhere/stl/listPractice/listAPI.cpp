#include <list>
#include <iterator>
#include <iostream>
#include <string>

template <typename T>
auto print = [] (std::string str, const std::list<T>& container) {
    std::cout << str;
    for(const auto & val : container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
};

class SampleStr
{
    private:
        std::string s = "";
    
    public:
        SampleStr(std::string str) : 
            s(std::move(str)) 
            { 
                std::cout << " constructed\n"; 
            }
    
        SampleStr(const SampleStr& o) : s(o.s)
            { 
                std::cout << " copy constructed\n"; 
            }
    
        SampleStr(SampleStr&& o) : 
            s(std::move(o.s)) 
            { 
                std::cout << " move constructed\n"; 
            }
    
        SampleStr& operator=(const SampleStr& other)
        {
            s = other.s;
            std::cout << " copy assigned\n";
            return *this;
        }
    
        SampleStr& operator=(SampleStr&& other)
        {
            s = std::move(other.s);
            std::cout << " move assigned\n";
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const SampleStr& str) {
            os << str.s ;
            return os;
        }
};

struct FunctionObj
{
    int operator()(const int& value) { return (value % 3 == 0 ); }
};

int main()
{
    //Constructor
        //empty
            std::list<std::string> myList;
        //fill
            std::list<int> fillList(10, 100);
        //range
            std::list<int> rangeList(fillList.begin(), fillList.end());
        //copy
            std::list<int> copyList(rangeList);
        //move
            std::list<int> moveList(std::move(copyList));
        //initializer list
            std::list<int> initList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

        SampleStr str("SampleName");
        std::list<SampleStr> sampleList;
        sampleList.assign(10, str);

    //destructor
        //~list()

    //Iterator
        //begin
        //cbegin
        //rend
        //crend
        //end
        //cend
        //crend
        //rend
        std::list<SampleStr>::iterator it;
        for(it = sampleList.begin(); it != sampleList.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        for (auto &&val : sampleList)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        print<SampleStr>("Priniting SampleStr Obj list: ", sampleList);
        

    //Element Access
        //front
        //back
        std::cout << "\n" << sampleList.front() << std::endl;
        std::cout << "\n" << sampleList.back() << std::endl;

    //Capacity
        //empty
            if(sampleList.empty())
                std::cout << "List is empty." << std::endl;
        //size
            std::cout << "SIZE: " << sampleList.size() << std::endl;
        //max_size
            std::cout << "max_size" << sampleList.max_size() << std::endl;
        //resize
            sampleList.resize(20, SampleStr("Hello"));
        
        print<SampleStr>("SampleStr List: ", sampleList);


    //Modifier
        //clear
        //insert
            sampleList.insert(sampleList.begin(), 5, SampleStr("DiscoDancer"));
            sampleList.insert(sampleList.begin(), SampleStr("Best Dancer"));
            print<SampleStr>("SampleList Post insertion: ", sampleList);
        //erase
        //emplace
            sampleList.emplace(sampleList.begin(), "Vicky Don");
        //emplace_front
            sampleList.emplace_front("Don" );
        //emplace_back
            sampleList.emplace_back("Second Last Don");
        //push_front
            sampleList.push_front(SampleStr("Don Check"));
        //push_back
            sampleList.push_back(SampleStr("Don"));
        //pop_front
            sampleList.pop_front();
        //pop_back
            sampleList.pop_back();

            print<SampleStr>("Final List Data: ", sampleList);
        //swap
        std::list<SampleStr>().swap(sampleList);
        print<SampleStr>("Final List Data: ", sampleList);

    //List Operations
        std::list<int> fooList({11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
        std::list<int> barList({21, 22, 23, 24, 25, 26, 27, 28, 29, 30});
        //merge
        fooList.merge(barList);
        print<int>("FooList: ", fooList);
        barList.merge(fooList, [] (int lhs, int rhs) -> bool {return rhs > lhs ; });
        print<int>("BarList: ", barList);
        //splice
            //check example here https://cplusplus.com/reference/list/list/splice/

        //remove
        std::list<int> mylist1({11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
        auto callback = [](int num) { return (num % 10 == 0); };
        mylist1.remove(30);
        
        //remove_if
        mylist1.remove_if(callback);
        mylist1.remove_if(FunctionObj());
        print<int>("Remove_remove_if operation: ", mylist1);
        //reverse
        mylist1.reverse();
        mylist1.push_back(11);
        print<int>("Reverse operation: ", mylist1);
        //unique
        mylist1.unique();
        //sort
        mylist1.sort([](const int& lhs, const int& rhs) -> bool {
            return static_cast<bool>(lhs > rhs);
        });
        print<int>("Unique_sort operation: ", mylist1);
    //LookUp

    //Observer
    
    //Allocator
        //get_allocator
}