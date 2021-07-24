#include <iostream>
 
template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		std::cout << "Auto_ptr3 constructor called" << std::endl;
	}
 
	~Auto_ptr3()
	{
		std::cout << "Auto_ptr3 destructor called" << std::endl;
		delete m_ptr;
	}
 
	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{

		std::cout << "Auto_ptr3 copy constructor called" << std::endl;
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}
 
	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{

		std::cout << "Auto_ptr3 assignment operator called" << std::endl;
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
 
Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}
 
int main()
{
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment
 
	return 0;
}