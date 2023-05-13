#include <iostream>
#include <thread>

class DisplayThread
{
public:
    void operator()()
    {
        std::cout << "\nChild Thread ID: " << std::this_thread::get_id() << std::endl;
        for (int i = 0; i < 100; i++)
            std::cout << "Child Thread Executing: "<< i << std::endl;
    }
};

void thread_function()
{
    for (int i = 0; i < 100; i++)
        std::cout << "Child function Executing: " << i << std::endl;
        
}


int main()
{
    /*
    /* Function Object */
    std::thread threadObj((DisplayThread()));

    /* Function Pointer */
    // std::thread threadObj(thread_function);

    /* Lambda Function */
    //std::thread threadObj([]
    //                      {
    //        for(int i = 0; i < 10000; i++)
    //            std::cout<<"Display Thread Executing"<<std::endl; });

    std::cout << "\nMain Thread ID: " << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "Main Thread executing: " << i << std::endl;

    std::cout << "Waiting For Child Thread to complete" << std::endl;
    threadObj.join();

    std::thread myth;
    std::cout << "Default Constructed Thread ID: " << myth.get_id() << '\n';
    std::cout << "Exiting from Main Thread" << std::endl;

    return 0;
}