#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

template<typename T>
class MessageQueue {
public:
    void Push(T message) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(std::move(message));
        lock.unlock();
        condition_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        T message = std::move(queue_.front());
        queue_.pop();
        return message;
    }

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
#if 0
int main() {
    MessageQueue<int> messageQueue;

    // Multiple producer threads
    std::vector<std::thread> producers;
    for (int i = 0; i < 2; ++i) {
        producers.emplace_back([&messageQueue, i]() {
            for (int j = 0; j < 5; ++j) {
                std::cout << "Producer " << i << " produced message: " << i + 10 + j << std::endl;
                messageQueue.Push(i + 10 + j);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulate work
                
                
            }
        });
    }

    // Multiple consumer threads
    std::vector<std::thread> consumers;
    for (int i = 0; i < 2; ++i) {
        consumers.emplace_back([&messageQueue, i]() {
            for (int j = 0; j < 5; ++j) {
                int message = messageQueue.Pop();
                 std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
                std::cout << "Consumer " << i << " received message: " << message << std::endl;
            }
        });
    }

    // Join all producer threads
    for (auto& producer : producers) {
        producer.join();
    }

    // Join all consumer threads
    for (auto& consumer : consumers) {
        consumer.join();
    }

    return 0;
}

#endif

#if 1
// Example usage
int main() {
    MessageQueue<int> messageQueue;

    // Producer thread
    std::thread producer([&messageQueue]() {
        for (int i = 0; i < 10; ++i) {
            messageQueue.Push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        }
    });

    // Consumer thread
    std::thread consumer([&messageQueue]() {
        for (int i = 0; i < 10; ++i) {
            int message = messageQueue.Pop();
            std::cout << "Received message: " << message << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
#endif