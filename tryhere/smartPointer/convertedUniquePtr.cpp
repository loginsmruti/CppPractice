#include <iostream>
#include<memory>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
        std::cout << "Constructor called.";
	}
 
    ~Fraction() {
       std::cout << "Destructor called.";
    }

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};
 
void printFraction(std::unique_ptr<Fraction> ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
}
 
int main()
{
    std::unique_ptr<Fraction> ptr{new Fraction{ 3, 5 }};

	printFraction(std::move(ptr));
 
	return 0;
}