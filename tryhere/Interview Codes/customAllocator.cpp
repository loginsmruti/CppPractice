#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class CustomAllocator {

    public:
        using value_type = T;

        CustomAllocator() = default;

        template <typename U>
        CustomAllocator(const CustomAllocator<U>&) noexcept {}

        T* allocate(std::size_t n) {
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p , std::size_t n) noexcept {
            ::operator delete(p);
        }
};

int main() {
    
    std::vector<std::string, CustomAllocator<std::string>> vect({"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}/*{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}*/, CustomAllocator<std::string>{});

    for (const auto& elem : vect) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;


    return 0;
}