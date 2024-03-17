#include <iostream>
#include <list>
#include <stack>
#include <utility>
#include <vector>
#include <string>
#include <functional>
#include <memory>

class Product {
private:
    int id;
    std::string name;
    double price;
    std::vector<int> relatedIds;

public:
    // Default constructor
    Product() : id(0), name(""), price(0.0) {}

    // Parameterized constructor
    Product(int id, const std::string& name, double price, const std::vector<int>& relatedIds)
        : id(id), name(name), price(price), relatedIds(relatedIds) {}

    // Copy constructor
    Product(const Product& other)
        : id(other.id), name(other.name), price(other.price), relatedIds(other.relatedIds) {}

    // Move constructor
    Product(Product&& other) noexcept
        : id(std::move(other.id)), name(std::move(other.name)), price(std::move(other.price)), relatedIds(std::move(other.relatedIds)) {}

    // Destructor (not explicitly needed here)

    // Copy assignment operator
    Product& operator=(const Product& other) {
        if (this != &other) {
            id = other.id;
            name = other.name;
            price = other.price;
            relatedIds = other.relatedIds;
        }
        return *this;
    }

    // Move assignment operator
    Product& operator=(Product&& other) noexcept {
        if (this != &other) {
            id = std::move(other.id);
            name = std::move(other.name);
            price = std::move(other.price);
            relatedIds = std::move(other.relatedIds);
        }
        return *this;
    }

    bool operator<(const Product& other) const {
        return id < other.id;
    }

    bool operator==(const Product& other) const {
        return (id == other.id);
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        os << "\nID: " << product.id << ", Name: " << product.name << ", Price: $" << product.price << ", Related IDs: ";
        for (int id : product.relatedIds) {
            os << id << " ";
        }
        os << "\n";
        return os;
    }

    // Accessor methods
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    const std::vector<int>& getRelatedIds() const { return relatedIds; }

    // Mutator methods
    void setId(int id) { this->id = id; }
    void setName(const std::string& name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
    void setRelatedIds(const std::vector<int>& relatedIds) { this->relatedIds = relatedIds; }


    // Comparator for sorting products by ID
    struct CompareByID {
        bool operator()(const Product& a, const Product& b) const {
            return a.getId() < b.getId();
        }
    };
    
};

// Custom hasher
namespace std {
    template<>
    struct hash<Product> {
        std::size_t operator()(const Product& p) const {
            // Combine hashes of individual members
            std::size_t hashValue = 0;
            hashValue ^= std::hash<int>()(p.getId());
            hashValue ^= std::hash<std::string>()(p.getName());
            hashValue ^= std::hash<double>()(p.getPrice());
            for (int relatedId : p.getRelatedIds()) {
                hashValue ^= std::hash<int>()(relatedId);
            }
            return hashValue;
        }
    };
}

// Custom comparator
struct ProductComparator {
    bool operator()(const Product& lhs, const Product& rhs) const {
        return (lhs.getId() == rhs.getId());
    }
};


template <typename T>
class CustomAllocator {
public:
    using value_type = T;

    CustomAllocator() noexcept = default;
    template <typename U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(std::allocator<T>{}.allocate(n));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        std::allocator<T>{}.deallocate(p, n);
    }
};

int main() {
    std::stack<Product, std::list<Product, CustomAllocator<Product>>> productStack;

    // Pushing products into the stack
    productStack.push(Product(1, "Product 1", 10.0, {2, 3}));
    productStack.push(Product(2, "Product 2", 20.0, {1, 3}));
    productStack.push(Product(3, "Product 3", 30.0, {1, 2}));

    // Copy the stack to another stack
    std::stack<Product, std::list<Product, CustomAllocator<Product>>> copiedStack(productStack);

    // Move the stack to another stack
    std::stack<Product, std::list<Product, CustomAllocator<Product>>> movedStack(std::move(copiedStack));


    std::cout << "copiedStack 1 size: " << copiedStack.size() << std::endl;
    std::cout << "movedStack 2 size: " << movedStack.size() << std::endl;

    while (!movedStack.empty())
    {
        std::cout << "\nProduct:" << movedStack.top();
        movedStack.pop();
    }

    return 0;
}
