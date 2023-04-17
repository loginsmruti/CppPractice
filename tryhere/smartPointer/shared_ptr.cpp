#include<memory>
#include<iostream>

auto deleter = [] (int* p) {
    delete p;
    p = nullptr;
};

struct C {int* data;};

struct A {int value;};

//Constructor style
//+++++++++++++++++++++++
void sharedPtrConstructor()
{
    std::shared_ptr<int> res1;  //Empty Constructor
    std::shared_ptr<int> res2 { new int}; // Construction from pointer
    std::shared_ptr<int> res3 (new int, deleter); // Construction from pointer + deleter
    std::shared_ptr<int> res4 ( new int, std::default_delete<int>(), std::allocator<int>() ); //Construction from deleter + allocator
    std::shared_ptr<int> res5 ( std::move(res4) );  //move Constructor
    std::shared_ptr<int> res6 ( std::unique_ptr<int>(new int(10)) ); //Construction from unique_ptr
    std::shared_ptr<C> obj (new C); //move from other types of managed pointers (9)
    std::shared_ptr<int> p9 (obj, obj->data);   //aliasing constructor (10)

    std::cout << "use_count:\n";
    std::cout << "res1: " << res1.use_count() << '\n';
    std::cout << "res2: " << res2.use_count() << '\n';
    std::cout << "res3: " << res3.use_count() << '\n';
    std::cout << "res4: " << res4.use_count() << '\n';
    std::cout << "res5: " << res5.use_count() << '\n';
    std::cout << "res6: " << res6.use_count() << '\n';
}

int main() 
{
    sharedPtrConstructor();

    std::shared_ptr<int> res1 { new int(100)};
    std::shared_ptr<int> res2(res1);    //copy initialization

    int* p = new int(2000);
    std::shared_ptr<int> res3(p);

    //std::shared_ptr::get
    //++++++++++++++++++++++
    if (res3.get() == p) {
        std::cout << "res2 and p points to the same address " << res3 << std::endl;
    }
    std::cout << *res3 << ":::" << *( res3.get() ) << ":::" << *p << std::endl;
    
    if( res3 ) { //std::shared_ptr::operator bool
        std::cout << *res3 << '\n'; //std::shared_ptr::operator*
         *res3 = *res3 * 2;
    }

    //std::shared_ptr::operator->
    //++++++++++++++++++++++
    std::shared_ptr<A> bar (new A);
    if ( bar ) {
        (bar->value) = 1000; 
        std::cout << (bar->value) << '\n';
    }

    //std::shared_ptr::reset
    //++++++++++++++++++++++
    res3.reset(new int);
    *res3 = 20;
    std::cout << *res3 << '\n';

    //std::shared_ptr::swap
    //++++++++++++++++++++++
    res3.swap(res1);

    //std::shared_ptr::unique
    //++++++++++++++++++++++
    std::cout << std::boolalpha << "res1 is Unique: " << res1.unique() << '\n';
    std::cout << std::boolalpha << "res3 is Unique: " << res3.unique() << '\n';
    std::cout << std::boolalpha << "bar is Unique: " << bar.unique() << '\n';

    return 0;
}