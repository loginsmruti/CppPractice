#include <thread>
#include <mutex>
#include <utility>
#include <iostream>
#include <vector>

class Wallet
{
    int mMoney;
    std::mutex myLock;

public:
    Wallet() : mMoney(0) {}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
        std::lock_guard<std::mutex> lockGuard(myLock);
        std::cout << "Child thread executing: " << std::endl;
        for (int i = 0; i < money; ++i) {
            mMoney++;
        }
    }
};

int main()
{
    Wallet walletObj;

    std::vector<std::thread> threads;

    for (size_t i = 0; i < 5; i++) {
        threads.push_back(std::thread(&Wallet::addMoney, &walletObj, 1000));
    }
    
    //std::thread th(&Wallet::addMoney, walletObj, 1000);
    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Main Thread started. " << std::endl;

    std::cout << "Waiting For Child Thread to complete" << std::endl;

    

    for (auto &&mythr : threads) {
        if(mythr.joinable()) {
            mythr.join();
        }
    }
    std::cout << "Total wallet money:::" << walletObj.getMoney();
    std::cout << "Exiting from Main Thread" << std::endl;
    return 0;
}