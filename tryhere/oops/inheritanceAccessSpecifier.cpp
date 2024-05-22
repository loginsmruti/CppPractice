#include <iostream>
class Base
{
    public:
        int a {1};
    protected:
        int b {2};
    private:
        int c {3};
};
 
class D2 : private Base // note: private inheritance
{
    public:
        int d {4};
        void get()
        {
            std::cout << " D2::get - a"  << std::endl;
            std::cout << " D2::get - b"  << std::endl;
            std::cout << " D2::get - c not possible" << std::endl;
        }
    protected:
        int e {5};
    private:
        int f {6};
};
 
class D3 : public D2
{
    public:
        int g {7};
        void fetch()
        {
            std::cout << " D3::get- d" << std::endl;
            std::cout << " D3::get - e" << std::endl;
            std::cout << " D3::get - f not possible" << std::endl;
            e = g;
            get();
        }
    protected:
        int h {8};
    private:
        int i {9};
};
 
class D4: public D3 {
 
    public:
        int j{};
        int k{};
        void play() {
            h = j;
            std::cout << "Fetch start\n";
            std::cout << " D4::get - D2::d ->"<< d << std::endl;
            fetch();
        }
};
 
int main()
{
    Base base;
    std::cout << base.a << std::endl;
    std::cout << "base.b" << std::endl;
    std::cout << "base.c" << std::endl;
 
   
    D2 derive;
    std::cout << derive.d << std::endl;
    std::cout << "derive.e" << std::endl;
    std::cout << "derive.f "<< std::endl;
    derive.get();
   
    D3 derive3;
    std::cout << derive3.g << std::endl;
    std::cout << "derive.h" << std::endl;
    std::cout << "derive.i "<< std::endl;
    derive3.fetch();
 
    D4 d4;
    d4.j;
    d4.k;
    d4.g;
    d4.play();
 
   
    return 0;
}
 