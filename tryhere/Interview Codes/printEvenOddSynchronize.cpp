#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

bool ready = true;
std::mutex mutex_t;
std::condition_variable condVar;

void printEven() {
    
    std::unique_lock<std::mutex> lock(mutex_t);
    for (int i = 0; i <=10; i = i + 2) {
        
        while(!ready)
            condVar.wait(lock );
        
        //lock.unlock();
        std::cout << i << std::endl;
        
        ready = false;
        condVar.notify_one();
    }
    
}

void printOdd() {
    std::unique_lock<std::mutex> lock(mutex_t);
    for (int i = 1; i <=10; i = i +2) {
        
        while(ready)
            condVar.wait(lock);
            
        //lock.unlock();
        std::cout << i << std::endl;
        ready = true;
        condVar.notify_one();
    }
}


int main()
{
    
    std::thread th1(printEven);
    
    std::thread th2(printOdd);
    
    
    if(th1.joinable()) th1.join();
    
    if(th2.joinable()) th2.join();
    
    return 0;
}