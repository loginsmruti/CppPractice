#include <iostream>
#include <thread>
#include <queue>
#include <utility>
#include <chrono>
#include <condition_variable>

template <typename T>
class MessageQueue {
  
  public:
    void Push(T message) {
        std::unique_lock<std::mutex> lock(mtx_);
        queue_.push(std::move(message));
        lock.unlock();
        condVar_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        condVar_.wait(lock, [this] () { return !queue_.empty(); } );
        T message = std::move(queue_.front());
        queue_.pop();
        return message;
    }
    
    private:
        std::queue<T> queue_;
        std::condition_variable condVar_;
        std::mutex mtx_;
};


int main() {
    
    MessageQueue<int> messageQueue;
    
    std::thread producer([&messageQueue] () {
        for (int i = 0; i < 20; i++) {
            messageQueue.Push(i);
            std::cout << "\nProducer : " << i ;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });
    
    std::thread consumer([&messageQueue] () {
        for (int i = 0; i < 20; i++) {
            int message = messageQueue.Pop();
            std::cout << "\nConsumer : " << message;
        }
    });
    
    if(producer.joinable())  producer.join();
    if(consumer.joinable())  consumer.join();
    
    
    return 0;
}