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
 
int main()
{
    auto &&ref = new Resource{};
	std::unique_ptr<Resource> res{ ref };
 
    std::unique_ptr<Resource> res2;
    res2 = std::move(res);
    
	if (res2) // use implicit cast to bool to ensure res contains a Resource
		std::cout << *res << '\n'; // print the Resource that res is owning
 
	return 0;
}