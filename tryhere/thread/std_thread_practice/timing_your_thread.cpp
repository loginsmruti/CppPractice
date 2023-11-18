#include <iostream>
#include <chrono>
#include <cstdint>

int main()
{
    std::time_t timestamp = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());
    std::cout << "Time Now: " << std::ctime(&timestamp) << std::endl;

    //time since epoch in milisec
    uint64_t epocInMiliSec =  std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "Time Since epoch in milisec:: " << epocInMiliSec << std::endl;

    return 0;
}