#include <stack>
#include <string>
#include <list>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    //constructor
    /**
     * 
     * initialize (1)	explicit stack (const container_type& ctnr);
     * move-initialize (2)	explicit stack (container_type&& ctnr = container_type());
     * allocator (3)	template <class Alloc> explicit stack (const Alloc& alloc);
     * init + allocator (4)	template <class Alloc> stack (const container_type& ctnr, const Alloc& alloc);
     * move-init + allocator (5)	template <class Alloc> stack (container_type&& ctnr, const Alloc& alloc);
     * copy + allocator (6)	template <class Alloc> stack (const stack& x, const Alloc& alloc);
     * move + allocator (7)	template <class Alloc> stack (stack&& x, const Alloc& alloc);
    */

    std::list<int> myList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    std::vector<int> vect({10, 20, 30, 40, 50, 60, 70, 80, 90, 100});
    
    std::stack<int> stk;
    stk.push(1);
    stk.push(2); stk.push(3); stk.push(4); stk.push(5); stk.push(6);
    stk.push(7); stk.push(8); stk.push(9);

    std::stack<int, std::vector<int>> vectToStack;
    std::stack<int, std::list<int>> listToStack(myList);
    //Element access
        //top
    //Capacity
        //empty
        //size
        std::cout << "\nSIZE: " << stk.size(); 
        while(!stk.empty()) {
            std::cout << "\nprint stk:" << stk.top() << " ";
            stk.pop();
        }
        std::cout << std::endl;
        std::cout << "\nSIZE: " << stk.size(); 

    //modifier
        //push
        //pop
        //emplace
        listToStack.emplace(1000);
        while(!listToStack.empty()) {
            std::cout << "\n print listToStack" << listToStack.top() << " ";
            listToStack.pop();
        }
        std::cout << std::endl;
        //swap
        std::stack<int, std::list<int>>().swap(listToStack);
        std::cout << "\nSIZE post swap:  " << listToStack.size(); 




    return 0;
};
