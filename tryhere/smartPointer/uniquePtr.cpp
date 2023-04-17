#include <iostream>
#include <memory> // for std::unique_ptr
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};
 
void exp_1() 
{
	auto &&ref = new Resource{};
	std::unique_ptr<Resource> res{ ref };
 
    std::unique_ptr<Resource> res2;
    res2 = std::move(res);
    
	if (res2) // use implicit cast to bool to ensure res contains a Resource
		std::cout << *res << '\n'; // print the Resource that res is owning
}

// stored deleter - callable object
auto deleter = [](int* p) {
	std::cout << "[deleter called]" << std::endl;
	delete p;
	p = nullptr;
};

int main()
{
	std::default_delete<int> d; //default deleter

	//Constructor style
	//+++++++++++++++++++++++
    std::unique_ptr<int> u1; // empty constructor
	std::unique_ptr<Resource> u2 = nullptr; //construct from nullptr
	std::unique_ptr<int> u3 (new int, d); //construct from pointer + lvalue deleter
	std::unique_ptr<int> u4 (new int, std::default_delete<int>()); //construct from pointer + rvalue deleter
	std::unique_ptr<int, decltype(deleter)> u5(new int, deleter);  // construct from custom deleter
	std::unique_ptr<int, decltype(deleter)> u6(std::move(u5)); //move constructor
	std::unique_ptr<int> u7 ( std::move(u4)); //move constructor

	std::cout << "u1 :" << (u1 ? "Not Null" : "Null") << '\n';
	std::cout << "u2 :" << (u2 ? "Not Null" : "Null") << '\n';
	std::cout << "u3 :" << (u3 ? "Not Null" : "Null") << '\n';
	std::cout << "u4 :" << (u4 ? "Not Null" : "Null") << '\n';
	std::cout << "u5 :" << (u5 ? "Not Null" : "Null") << '\n';
	std::cout << "u6 :" << (u6 ? "Not Null" : "Null") << '\n';
	std::cout << "u7 :" << (u7 ? "Not Null" : "Null") << '\n';

	std::unique_ptr<int> ptr1{ new int{10} };

	//std::unique_ptr::get()
	//++++++++++++++++++++++
	int* ptr = ptr1.get();
	std::cout << "ptr1.get(): " << *ptr << std::endl;
	*ptr = 20;
	std::cout << "*ptr = 20: " << *ptr << std::endl;

	//std::unique_ptr::release()
	//+++++++++++++++++++
	//Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
	//This call does not destroy the managed object, but the unique_ptr object is released from the responsibility of deleting the object.
	//Some other entity must take responsibility for deleting the object at some point.

	ptr = ptr1.release();
	std::cout << "ptr1.release(): " << *ptr << std::endl;
	delete ptr;

	std::unique_ptr<int> foo(new int(10));
	std::unique_ptr<int> bar(std::move(foo));

	if(bar)
		std::cout << (*bar ? "(*bar): Not Null" : "(*bar): Null") << std::endl;

	//std::unique_ptr::reset()
	//+++++++++++++++++++
	//Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p.
	//To release the ownership of the stored pointer without destroying it, use member function release instead.

	foo.reset(new int(30));
	bar.reset(new int(10));

	if(foo)
		std::cout << "foo: " << *foo << std::endl;
	if(bar)
		std::cout << "bar: " << *bar << std::endl;

	//std::unique_ptr::swap()
	//++++++++++++++++++++++
	foo.swap(bar);

	std::swap(foo, bar);

	if(foo)
		std::cout << "foo: " << *foo << std::endl;
	if(bar)
		std::cout << "bar: " << *bar << std::endl;

	auto &&ref { std::make_unique<Resource>() };
	std::cout << *ref <<std::endl;

	return 0;
}