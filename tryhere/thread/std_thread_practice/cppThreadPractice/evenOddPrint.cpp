#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isEvenTurn = true;

void printEven() {
    std::unique_lock<std::mutex> lock(mtx);
    for (int i = 0; i <= 10; i += 2) {
    
        while (!isEvenTurn) {
            cv.wait(lock);
        }
        std::cout << "Even: " << i << std::endl;
        isEvenTurn = false;
        cv.notify_one();
    }
}

void printOdd() {
    std::unique_lock<std::mutex> lock(mtx);
    for (int i = 1; i <= 10; i += 2) {
        while (isEvenTurn) {
            cv.wait(lock);
        }
        std::cout << "Odd: " << i << std::endl;
        isEvenTurn = true;
        cv.notify_one();
    }
}

int main() {
    std::thread t1(printEven);
    std::thread t2(printOdd);

    t1.join();
    t2.join();

    return 0;
}
