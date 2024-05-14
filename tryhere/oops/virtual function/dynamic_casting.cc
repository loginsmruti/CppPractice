#include <iostream>
#include <string>
 
// Class identifier
enum ClassID
{
	BASE,
	DERIVED
	// Others can be added here later
};
 
class Base
{
protected:
	int m_value;
 
public:
	Base(int value)
		: m_value(value)
	{
	}
 
	virtual ~Base() {}
	virtual ClassID getClassID() { return BASE; }
};
 
class Derived : public Base
{
protected:
	std::string m_name;
 
public:
	Derived(int value, std::string name)
		: Base(value), m_name(name)
	{
	}
 
	std::string& getName() const { return m_name; }
	virtual ClassID getClassID() override { return DERIVED; }
 
};
 
Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived(1, "Apple");
	else
		return new Base(2);
}
 
int main()
{
	Base *b = getObject(true);
 
	if (b->getClassID() == DERIVED)
	{
		// We already proved b is pointing to a Derived object, so this should always succeed
		Derived *d = dynamic_cast<Derived*>(b);
		std::cout << "The name of the Derived is: " << d->getName() << '\n';
	}
 
	delete b;
 
	return 0;
}
