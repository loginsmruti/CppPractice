#include<iostream>
#include<set>
#include<iterator>
#include <string>
#include <vector>

class Product
{
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
    class CompareByID {
        public:
        bool operator()(const Product& a, const Product& b) const {
            return a.id < b.id;
        }
    };

};

template<typename T>
class CustomAllocator {
public:
    using value_type = T;

    CustomAllocator() noexcept = default;

    template<typename U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p);
    }
};

int main() {

    std::set<Product, Product::CompareByID, CustomAllocator<Product>> productsSet;

    // Insert elements into the set
    productsSet.insert({Product(3, "Product C", 30.0, {301, 302}),
                       Product(1, "Product A", 10.0, {101, 102}),
                       Product(2, "Product B", 20.0, {201, 202}) } );


    return 0;
}
