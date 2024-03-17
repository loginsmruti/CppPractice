#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
#include <memory>

template<typename T>
auto print = [](std::string str, const std::unordered_set<T>& container) {
    std::cout << str;
    for(const auto & val : container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
};

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

//Custom hasher
template<>
struct std::hash<Product> {
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

struct ProductHasher {
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

struct ProductComparator {
    bool operator()(const Product& lhs, const Product& rhs) const {
        
        return (lhs.getId() == rhs.getId());
    }
};

//Custom Allocator
template <typename T>
class CustomAllocator {
    public:
        using value_type = T; 
        
        CustomAllocator() noexcept = default;
        
        template <typename U>
        CustomAllocator(const CustomAllocator<U>&) noexcept {}

        T* allocate(std::size_t n) {
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t) noexcept {
            ::operator delete(p);
        }
};

int main(int argc, char const *argv[])
{
//Constructor
    //initializer_list
    std::unordered_set<Product> prodSet({Product(3, "Product C", 30.0, {301, 302}),
                                    Product(1, "Product A", 10.0, {101, 102}),
                                    Product(2, "Product B", 20.0, {201, 202}),
                                    Product(4, "Product D", 40.0, {401, 402}),
                                    Product(5, "Product E", 50.0, {501, 502}),
                                    Product(6, "Product F", 60.0, {601, 602}),
                                    Product(7, "Product G", 70.0, {701, 702}),
                                    Product(8, "Product H", 80.0, {801, 802})
                                    });
    //empty
    std::unordered_set<Product> prodSetEmpty;
    //range
    std::unordered_set<Product> prodSetRange(++prodSet.begin(), prodSet.end());
    //copy
    std::unordered_set<Product> prodSetCopy(prodSet);
    //move
    std::unordered_set<Product> prodSetMove(std::move(prodSet));
    

//Destructor
    //~unordered_set

//Iterator
    //begin
    //cbegin
    //rbegin
    //crbegin
    //end
    //cend
    //rend
    //crend

//Element Access
    //std::unordered_set<Product>::iterator it;
    
    for(Product prod: prodSetMove) {
        std::cout << prod <<std::endl;
    }
    
//Capacity
    //empty
    if(!prodSetMove.empty()) {
        print<Product>("\nAll Products: ", prodSetMove);
    }
    //size
    std::cout << "SIZE: " << prodSetMove.size() << std::endl;
    //max_size
    std::cout << "max_size: " << prodSetMove.max_size() << std::endl;
    
    //reserve
    prodSetMove.reserve(15);

//Modifiers
    //clear
    //insert
        /*
        (1)	pair<iterator,bool> insert ( const value_type& val );
        (2)	pair<iterator,bool> insert ( value_type&& val );
        (3)	iterator insert ( const_iterator hint, const value_type& val );
        (4)	iterator insert ( const_iterator hint, value_type&& val );
        (5)	template <class InputIterator>    void insert ( InputIterator first, InputIterator last );
        (6)	void insert ( initializer_list<value_type> il );
        */
        std::pair<std::unordered_set<Product>::iterator, bool> result;
        result = prodSetMove.insert(Product(9, "Product I", 90.0, {901, 902}));
        if(result.second) {
            std::cout << "unordered set insertion successful.\n";
        }
        //insert by iterator position
    //erase
       /*      
           by position (1)	iterator erase ( const_iterator position );
           by key (2) size_type erase ( const key_type& k );
           range (3) iterator erase ( const_iterator first, const_iterator last ); 
       */
       size_t val = prodSetMove.erase(Product(9, "Product I", 90.0, {901, 902}));
       if(val) {
            std::cout << "unordered set erase successful.\n";
       }
    //swap
/*
    //emplace
        std::pair<std::unordered_set<Product>::iterator, bool> resultItr;
        resultItr = prodSetMove.emplace(9, "Product I", 90.0, {901, 902});
        if(result.second) {
            std::cout << "unordered set insertion successful.\n";
        }
*/
    //emplace_hint

//List Operations

//Lookup
    //count
    size_t numOfItems = prodSetMove.count(Product(9, "Product I", 90.0, {901, 902}));
    std::cout << "\nnumOfItems: " << numOfItems << std::endl;
    //find
    auto it = prodSetMove.find(Product(9, "Product I", 90.0, {901, 902}));
    if(it != prodSetMove.end()) {
        prodSetMove.erase(it);
    }
    print<Product>("Final unordered_set print: ", prodSetMove);
    //equal_range
    typedef std::unordered_set<Product>::const_iterator ConstIterator;
    std::pair<ConstIterator, ConstIterator> resultIt = prodSetMove.equal_range(Product(8, "Product H", 80.0, {801, 802}));
    std::cout << "result.first: " << *resultIt.first << "\n";
    std::cout << "result.second: " << *resultIt.second << "\n";
//Observers
    //hash_func
    std::unordered_set<Product>::hasher fn = prodSetMove.hash_function();
    std::cout << "Hasher val: " << fn(Product(8, "Product H", 80.0, {801, 802}));

    //key_eq
    bool out = prodSetMove.key_eq()(Product(9, "Product I", 90.0, {901, 902}) , Product(8, "Product H", 80.0, {801, 802}));
    std::cout << "\nprodSetMove.key_eq() is ";
    std::cout << ( out ? "EQUAL" : "NOT EQUAL" );
    std::cout << std::endl;

//Allocator
    //get_allocator

    //Experimenting comparator/haser
    std::unordered_set<Product, ProductHasher, ProductComparator> prodSetCustomDefined;
    prodSetCustomDefined.insert(Product(1, "Product A", 10.0, {101, 102}));
    prodSetCustomDefined.insert(Product(2, "Product B", 20.0, {201, 202}));
    prodSetCustomDefined.insert(Product(3, "Product C", 30.0, {301, 302}));
    prodSetCustomDefined.insert(Product(4, "Product D", 40.0, {401, 402}));
    prodSetCustomDefined.insert(Product(5, "Product E", 50.0, {501, 502}));
    prodSetCustomDefined.insert(Product(6, "Product F", 60.0, {601, 602}));

    std::cout << "\nProdSetCustomDefined hasher/comparator: " ;
    for(const Product& pro: prodSetCustomDefined) {
        std::cout << pro;
    }
    std::cout << std::endl;

    std::unordered_set<std::string, std::hash<std::string> , std::equal_to<std::string>> setOfStrs({"VICKY", "SUBHA", "BABA", "MAMA", "ROCKY", "SHRIVIKA"});
    std::cout << "\ndefault hasher/comparator: " ;
    for(const std::string& str: setOfStrs) {
        std::cout << " " <<str;
    }
    std::cout << std::endl;

    //bucket_count
    size_t nbuckets = setOfStrs.bucket_count();
    std::cout << "\nsetOfStrs.bucket_count(): " << nbuckets;
    std::cout << "setOfStrs has " << nbuckets << " buckets:\n";

    //bucket_size
    for (unsigned i = 0 ; i < nbuckets; ++i) {
        std::cout << "bucket #" << i << " has " << setOfStrs.bucket_size(i) << " elements.\n";
    }
    
    //size_type bucket ( const key_type& k ) const; Returns the bucket number where the element with value k is located.


    std::unordered_set<std::string> myset =
    {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

    unsigned n = myset.bucket_count();

    std::cout << "myset has " << n << " buckets.\n";

    for (unsigned i=0; i<n; ++i) {
        std::cout << "bucket #" << i << " contains:";
        for (auto it = myset.begin(i); it!=myset.end(i); ++it)
        std::cout << " " << *it;
        std::cout << "\n";
    }


    return 0;
}
