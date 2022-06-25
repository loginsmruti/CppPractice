#include<thread>
#include<mutex>
#include <utility>
#include<iostream>

class ChildThread
{       
    public:
    void operator()() {
        std::mutex myLock;
        
        std::lock_guard<std::mutex> lockGuard(myLock);

        for (size_t i = 0; i < 10; i++) {
            std::cout << "Child thread executing: " << i << std::endl;
        }
    }

};

int main()
{
    std::thread th((ChildThread()));
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Main Thread started. " << std::endl;
    
    for (size_t i = 0; i < 10; i++) {
        std::cout << "Main thread executing: " << i << std::endl;
    }

    std::cout << "Waiting For Child Thread to complete" << std::endl;
    th.join();

    std::cout << "Exiting from Main Thread" << std::endl;
    return 0;
}