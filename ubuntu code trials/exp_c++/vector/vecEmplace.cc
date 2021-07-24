// vector::emplace_back
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> myvector = {10,20,30};

    std::cout << "myvector Capacity:" << myvector.capacity() << std::endl;
    myvector.emplace_back (100);
    std::cout << "myvector Capacity:" << myvector.capacity() << std::endl;
    myvector.emplace_back (200);

    std::cout << "myvector Capacity:" << myvector.capacity() << std::endl;
    std::cout << "myvector contains:";
    for (auto& x: myvector)
        std::cout << ' ' << x;
    std::cout << '\n';

    return 0;
}
