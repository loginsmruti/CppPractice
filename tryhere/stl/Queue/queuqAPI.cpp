#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

template <typename T>
auto QPRINT = []( std::string str, std::queue<T>& container) {
    std::cout << str;
    while (!container.empty())
    {   
        std::cout << container.front() << " ";
        container.pop();
    }
    std::cout << std::endl;
    
};

int main(int argc, char const *argv[])
{
    //Constructor
    /**
    *
    * initialize (1)	explicit queue (const container_type& ctnr);
    * move-initialize (2)	explicit queue (container_type&& ctnr = container_type());
    * allocator (3)	template <class Alloc> explicit queue (const Alloc& alloc);
    * init + allocator (4)	template <class Alloc> queue (const container_type& ctnr, const Alloc& alloc);
    * move-init + allocator (5)	template <class Alloc> queue (container_type&& ctnr, const Alloc& alloc);
    * copy + allocator (6)	template <class Alloc> queue (const queue& x, const Alloc& alloc);
    * move + allocator (7)	template <class Alloc> queue (queue&& x, const Alloc& alloc);
    * 
*/

    std::queue<std::string> q;
    q.push("A"); q.push("B"); q.push("C"); q.push("D"); q.push("E"); q.push("F");
    q.push("G"); q.push("H"); q.push("I"); q.push("J"); q.push("K"); q.push("L");
    QPRINT<std::string>("\nPrint Q: ", q);

    std::list<int> myList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    std::queue<int, std::list<int>> listToQueue(myList);
    std::cout << "\nPrint listToQueue: SIZE: " << listToQueue.size() << "\n";
    while ((!listToQueue.empty())) {
        std::cout << listToQueue.front() << " ";
        listToQueue.pop();
    }
    std::cout << std::endl;

    std::deque<std::string> myDeq({"10",  "20",  "30",  "40",  "50" ,
                             "60",  "70",  "80",  "90",  "100" ,
                             "110", "120", "130", "140", "150" });
    std::queue<std::string, std::deque<std::string>> deqToQueue(myDeq);
    std::cout << "\nPrint deqToQueue: SIZE: " << deqToQueue.size() << "\n";
    while ((!deqToQueue.empty())) {
        std::cout << deqToQueue.front() << " ";
        deqToQueue.pop();
    }
    std::cout << std::endl;

    //Iterator access
        //not available
    
    //Element Access
        //front
        //back
    
    //capacity
        //empty
        //size
    
    //modifiers
        //push
        //pop

        //emplace
        std::cout << "\nPrint deqToQueue post emplace:  " << deqToQueue.size();
        deqToQueue.emplace("160");
        deqToQueue.emplace("170");
        deqToQueue.emplace("180");
        while ((!deqToQueue.empty())) {
            std::cout << deqToQueue.front() << " ";
            deqToQueue.pop();
        }
        std::cout << std::endl;
        //swap
        std::queue<std::string, std::deque<std::string>>().swap(deqToQueue);
        std::cout << "\nPrint deqToQueue post swap:  " << deqToQueue.size();
        while ((!deqToQueue.empty())) {
            std::cout << deqToQueue.front() << " ";
            deqToQueue.pop();
        }
        std::cout << std::endl;

    return 0;
}
