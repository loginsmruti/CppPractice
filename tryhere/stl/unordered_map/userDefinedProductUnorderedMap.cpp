#include <iostream>
#include <unordered_map>
#include <string>

// Product class definition
class Product {
public:
    std::string name;
    int id;
    double price;

    Product(std::string n, int i, double p) : name(n), id(i), price(p) {}

    bool operator==(const Product& other) const {
        return id == other.id && name == other.name && price == other.price;
    }
};

// Custom hasher for Product
struct ProductHasher {
    std::size_t operator()(const Product& p) const {
        std::size_t h1 = std::hash<std::string>{}(p.name);
        std::size_t h2 = std::hash<int>{}(p.id);
        std::size_t h3 = std::hash<double>{}(p.price);
        return h1 ^ (h2 << 1) ^ (h3 << 2); // Combine the hash values
    }
};

// External comparator for Product
struct ProductComparator {
    bool operator()(const Product& p1, const Product& p2) const {
        return p1 == p2;
    }
};

int main() {
    // Define the unordered_map with custom hasher and comparator
    std::unordered_map<Product, std::string, ProductHasher, ProductComparator> productMap;

    // Create Product objects
    Product p1("Laptop", 1, 999.99);
    Product p2("Smartphone", 2, 499.99);
    Product p3("Tablet", 3, 299.99);

    // Insert Products into the unordered_map
    productMap[p1] = "Electronics";
    productMap[p2] = "Gadgets";
    productMap[p3] = "Devices";

    // Access and print the values in the unordered_map
    for (const auto& entry : productMap) {
        std::cout << "Product: " << entry.first.name
                  << ", Category: " << entry.second << std::endl;
    }

    return 0;
}
