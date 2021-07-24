#include <memory>
#include <utility>
#include<iostream>

struct Widget{
    
    std::string name;
    int id;

    Widget(std::string _name, int _id)
    :name(_name),id(_id)
    {}
    

    friend std::ostream& operator<<(std::ostream& out, const Widget &w1)
	{
		out << w1.name << "/" << w1.id;
		return out;
	}
};

void sink(std::unique_ptr<Widget> uniqPtr){
    // do something with uniqPtr
    //std::cout << uniqPtr.get() << std::endl;
}

int main(){
    auto uniqPtr = std::make_unique<Widget>("Smruti",12);
    
    sink(std::move(uniqPtr));      // (1)
    //sink(uniqPtr);                 // (2) ERROR
}