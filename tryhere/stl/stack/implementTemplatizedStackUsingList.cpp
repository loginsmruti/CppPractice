#include <iostream>
#include <list>
#include <iostream>
 
template <typename T>
class Stack {
 
    private:
        std::list<T> st;
 
    public:
        //constructor
        Stack() = default;
        //copy constructor
        Stack(const Stack<T>& other) :st(other.st){ }
 
        //move constructor
        Stack(Stack<T>&& other) noexcept:st(std::move(other.st)){ }
       
        //copy assignment
        Stack<T>& operator=(const Stack<T>& other) {
            if(this != other) {
                this-> st = other.st;
            }
            return *this;
        }
 
        //move assignment
        Stack<T>& operator=(Stack<T>&& other) noexcept {
            if(this != other) {
                st = std::move(other.st);
            }
            return *this;
        }
 
        //access
            //top()
            T& top() {
                if(!st.empty()) {
                    return st.back();
                } else {
                    std::cerr << "Stack is empty. No top element.\n";
                    // Return a reference to a temporary variable. It's not ideal, but it will prevent a crash.
                    return *new T;
                }
            }
 
        //capacity
            //empty
            bool empty() {
                return (st.empty());
            }
            //size
            size_t size() { return st.size(); }
 
        //modifier
            //push
            void push(const T& val) {
                st.push_back(val);
            }
            //pop
            void pop() {
                if(!st.empty()) {
                    st.pop_back();
                } else {
                    std::cerr << "Stack is empty. Can't pop.\n";
                }
            }
            //swap
            void swap(Stack<T>& other) {
                st.swap(other.st);
            }
 
        //operators
            //operator==
            bool operator==(const Stack<T>& other) const {
                return st == other.st;
            }
            //ostream<<
            friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
                for(auto && val : stack.st)
                    os << val << " ";
 
                std::cout << std::endl;
                return os;
            }
       
 
}; int main() {
 
    Stack<int> stack;
 
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.push(11);
    stack.push(12);
 
    // Print the contents of the stack using the overloaded << operator
    std::cout << "Stack contents: " << stack << std::endl;
 
    stack.pop();
    // Print the contents of the stack using the overloaded << operator
    std::cout << "Stack pop: " << stack << std::endl;
 
    std::cout << "Stack top(): " << stack.top() << " ,  Stack size: " << stack.size() << std::endl;
 
    Stack<int> stack2;
 
    stack.swap(stack2);
 
    std::cout << "Stack2 swap(): " << stack2 << std::endl;
 
    if(stack == stack2)
        std::cout << "Both stacks are equal" << std::endl;
    else
        std::cout << "Both stacks are NOT equal" << std::endl;
 
    return 0;
}
 