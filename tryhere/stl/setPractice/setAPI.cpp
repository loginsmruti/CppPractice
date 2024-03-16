#include<iostream>
#include<set>
#include<iterator>
#include <string>
#include <vector>
#include <functional>

template <typename T>
auto print = [] (std::string str, const std::set<T>& container) {
    std::cout << str;
    for(const auto & val : container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
};

template <typename T, typename S>
void erase_if(S& container , T first, T last, std::function<bool (T)> checker) {
    while (first != last)
    {
        if(checker(first)) {
            first = container.erase(first);
        } else {
            first++; 
        }
    }
}

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

int testProduct() {
    // Test the Product class
    std::vector<int> relatedIds = {101, 102, 103};
    Product prod1(1, "Product 1", 10.99, relatedIds);
    std::cout << "Product ID: " << prod1.getId() << ", Name: " << prod1.getName() << ", Price: $" << prod1.getPrice() << std::endl;
    std::cout << "Related IDs: ";
    for (int id : prod1.getRelatedIds()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Copy constructor
    Product prod2 = prod1;
    std::cout << "Product ID: " << prod2.getId() << ", Name: " << prod2.getName() << ", Price: $" << prod2.getPrice() << std::endl;
    std::cout << "Related IDs: ";
    for (int id : prod2.getRelatedIds()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Move constructor
    Product prod3 = std::move(prod1);
    std::cout << "Product ID: " << prod3.getId() << ", Name: " << prod3.getName() << ", Price: $" << prod3.getPrice() << std::endl;
    std::cout << "Related IDs: ";
    for (int id : prod3.getRelatedIds()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Copy assignment operator
    Product prod4;
    prod4 = prod2;
    std::cout << "Product ID: " << prod4.getId() << ", Name: " << prod4.getName() << ", Price: $" << prod4.getPrice() << std::endl;
    std::cout << "Related IDs: ";
    for (int id : prod4.getRelatedIds()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Move assignment operator
    Product prod5;
    prod5 = std::move(prod3);
    std::cout << "Product ID: " << prod5.getId() << ", Name: " << prod5.getName() << ", Price: $" << prod5.getPrice() << std::endl;
    std::cout << "Related IDs: ";
    for (int id : prod5.getRelatedIds()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    return 0;
}

int main(int argc, char const *argv[])
{
//Constructor
    std::vector<int> relatedIds = {101, 102, 103};
    Product prod1(1, "Product 1", 10.99, relatedIds);
    Product prod2(2, "Product 2", 11.99, relatedIds);
    Product prod3(3, "Product 3", 12.99, relatedIds);
    Product prod4(4, "Product 4", 13.99, relatedIds);
    Product prod5(5, "Product 5", 14.99, relatedIds);
    //empty
        std::set<std::string> demoSet;
        Product prodArr[] = {prod1, prod2, prod3, prod4, prod5};
    //range
        std::set<Product> prodSet(prodArr, prodArr + sizeof(prodArr) / sizeof(Product));
        std::set<Product> prodSet2(prodSet.begin(), prodSet.end());
    //copy
        std::set<Product> prodSet3(prodSet2);
    //move
        std::set<Product> prodSet4(std::move(prodSet3));
    //initializer list
        std::set<Product> prodSet5({Product(3, "Product C", 30.0, {301, 302}),
                                    Product(1, "Product A", 10.0, {101, 102}),
                                    Product(2, "Product B", 20.0, {201, 202}),
                                    Product(4, "Product D", 40.0, {401, 402}),
                                    Product(5, "Product E", 40.0, {501, 502}),
                                    Product(6, "Product F", 60.0, {601, 602})
                                    });

//Destructor
    //~set

//Iterator
    //begin
    //end
    //cbegin
    //cend
    //rbegin
    //rend
    //crbegin
    //crend
    //print<Product>("\nAll Products: ", prodSet4);

//Element Access
    //Not Applicable

//Capacity
    //empty
    //size
    //max_size
    std::cout << "SIZE: " << prodSet4.size() << std::endl;
    std::cout << "max_size: " << prodSet4.max_size() << std::endl;
    if(!prodSet4.empty()) {
        print<Product>("\nAll Products: ", prodSet4);
    }

//Modifiers
    //clear
    //insert
    std::pair<std::set<Product>::iterator, bool> ret;
    ret = prodSet4.insert(Product(6, "Product E", 60.0, {601, 602}));
    if(ret.second == true) {
        std::cout << "ret.first: " << *(ret.first) << "\n" ;
    }
    //erase
    /*
    	(1) iterator  erase (const_iterator position);
        (2)	size_type erase (const value_type& val);
        (3)	iterator  erase (const_iterator first, const_iterator last);
    */
   std::set<Product> prodSet6({Product(3, "Product C", 30.0, {301, 302}),
                                    Product(1, "Product A", 10.0, {101, 102}),
                                    Product(2, "Product B", 20.0, {201, 202}),
                                    Product(4, "Product D", 40.0, {401, 402}),
                                    Product(5, "Product E", 50.0, {501, 502}),
                                    Product(6, "Product F", 60.0, {601, 602})
                                    });
    for(auto& product : prodSet6) {
        if(product.getId() == 6) {
            prodSet6.erase(product);
        }
    }
    print<Product>("Post Erase by value: ", prodSet6);

    std::set<Product> prodSet7( {Product(3, "Product C", 30.0, {301, 302}),
                                Product(1, "Product A", 10.0, {101, 102}),
                                Product(2, "Product B", 20.0, {201, 202}),
                                Product(4, "Product D", 40.0, {401, 402}),
                                Product(5, "Product E", 50.0, {501, 502}),
                                Product(6, "Product F", 60.0, {601, 602}),
                                Product(7, "Product G", 70.0, {701, 702}) });
    std::set<Product>::iterator itr;
    itr = prodSet7.begin();
    while(itr != prodSet7.end()) {
        if (itr->getId() % 3 == 0) {
            itr = prodSet7.erase(itr);
        } else {
            itr++;
        }
    }
    print<Product>("Post Erase while iterating: ", prodSet7);

    std::set<Product> prodSet8( {Product(3, "Product C", 30.0, {301, 302}),
                                Product(1, "Product A", 10.0, {101, 102}),
                                Product(2, "Product B", 20.0, {201, 202}),
                                Product(4, "Product D", 40.0, {401, 402}),
                                Product(5, "Product E", 50.0, {501, 502}),
                                Product(6, "Product F", 60.0, {601, 602}),
                                Product(7, "Product G", 70.0, {701, 702}),
                                Product(8, "Product H", 80.0, {801, 802})
                                 });

    typedef std::set<Product>::iterator SetItr;
    std::function<bool (SetItr)> checker = [](SetItr itr) -> bool {
        return (itr->getId() % 2 == 0);
    };
    erase_if<>(prodSet8, prodSet8.begin(), prodSet8.end(), checker);
    print<Product>("Post Erase_if: ", prodSet8);


    prodSet8.erase(++prodSet8.begin(), --prodSet8.end());
    print<Product>("Post Erase by range: ", prodSet8);

    //swap
    prodSet6.swap(prodSet8);
    std::set<Product>().swap(prodSet4);

/*      //emplace
    
    std::set<Product> productsSet;

    // Emplace elements into the set
    productsSet.emplace(3, "Product C", 30.0, {301, 302});
    //emplace_hint
    productsSet.emplace_hint(prodSet4.begin() , 10, "Product J", 30.0, {301, 302});
    print<Product>("Post Emplace & emplace_hint: " , prodSet4); */
 

//List Operations

//Lookup
    //count
    std::set<int> mySet;
    // set some initial values:
    for (int i=1; i<10; ++i) 
        mySet.insert(i*3);    // set:  3 6 9 12 15 18 21 24 27 
    print<int>("myset: ", mySet);

    //find
    auto it = mySet.find(18);
    if(it != mySet.end())
        mySet.erase(it);
    print<int>("myset find: ", mySet);
    
    //lower_bound
    auto lower_bound = mySet.lower_bound(9);
    //upper_bound
    auto upper_bound = mySet.upper_bound(21);
    auto iter = mySet.erase(lower_bound, upper_bound);
    print<int>("erase by lower_upper_bound: ", mySet);

    //equal_range
    typedef std::set<int>::const_iterator ConstIterator;
    std::pair<ConstIterator, ConstIterator> result = mySet.equal_range(24);
    std::cout << "result.first: " << *result.first << "\n";
    std::cout << "result.second: " << *result.second << "\n";

//Observers
    //key_comp
    //value_comp


//Allocators
    //get_allocator
  std::set<Product, Product::CompareByID, CustomAllocator<Product>> productsSet;

    // Insert elements into the set
    productsSet.insert({Product(3, "Product C", 30.0, {301, 302}),
                       Product(1, "Product A", 10.0, {101, 102}),
                       Product(2, "Product B", 20.0, {201, 202}) } );


    return 0;
}
