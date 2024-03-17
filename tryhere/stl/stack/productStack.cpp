#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

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

class ProductStack {
private:
    std::stack<Product, std::list<Product>> stack;

public:
    // Constructors
    ProductStack() = default;
    ProductStack(const ProductStack& other) = default;
    ProductStack(ProductStack&& other) noexcept = default;

    // Assignment operators
    ProductStack& operator=(const ProductStack& other) = default;
    ProductStack& operator=(ProductStack&& other) noexcept = default;

    // Equality operator
    bool operator==(const ProductStack& other) const {
        return stack == other.stack;
    }

    // Less than operator
    bool operator<(const ProductStack& other) const {
        return stack < other.stack;
    }

    // Push and pop methods
    void push(const Product& product) {
        stack.push(product);
    }

    void pop() {
        stack.pop();
    }

    // Top method
    const Product& top() const {
        return stack.top();
    }

    // Empty method
    bool empty() const {
        return stack.empty();
    }

    // Size method
    size_t size() const {
        return stack.size();
    }
};

int main() {
    ProductStack stack1;
    stack1.push(Product(1, "Product 1", 10.0, {2, 3}));
    stack1.push(Product(2, "Product 2", 20.0, {1, 3}));
    stack1.push(Product(3, "Product 3", 30.0, {1, 2}));

    ProductStack stack2(stack1);

    std::cout << "Stack 1 size: " << stack2.size() << std::endl;
    std::cout << "Stack 2 size: " << stack1.size() << std::endl;

    while (!stack2.empty())
    {
        std::cout << "\nProduct:" << stack2.top();
        stack2.pop();
    }

    return 0;
}
