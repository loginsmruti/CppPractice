#include <iostream>
using namespace std;

class Toy 
{
protected:
	string name;
	float price;
public:
	virtual void prepareParts()  = 0;
	virtual void combineParts()  = 0;
	virtual void assembleParts() = 0;
	virtual void applyLabel()    = 0;
	virtual void showProduct()   = 0;
};

class Car : public Toy {
public:
	void prepareParts()  { cout << "Preparing Car Parts" << endl;}
	void combineParts()  { cout << "Combining Car Parts" << endl;}
	void assembleParts() { cout << "Assembling Car Parts" << endl;}
	void applyLabel()      { cout << "Applying Car Label" << endl;  name = "Car"; price = 10;}
	void showProduct () { cout << "Name: " << name << endl << "Price: " << price << endl;}
};

class Bike : public Toy {
public:
	void prepareParts()  { cout << "Preparing Bike Parts" << endl;}
	void combineParts()  { cout << "Combining Bike Parts" << endl;}
	void assembleParts() { cout << "Assembling Bike Parts" << endl;}
	void applyLabel()      { cout << "Applying Bike Label" << endl;  name = "Bike"; price = 20;}
	void showProduct () { cout << "Name: " << name << endl << "Price: " << price << endl;}
};

class Plane : public Toy {
public:
	void prepareParts()  { cout << "Preparing Plane Parts" << endl;}
	void combineParts()  { cout << "Combining Plane Parts" << endl;}
	void assembleParts() { cout << "Assembling Plane Parts" << endl;}
	void applyLabel()      { cout << "Applying Plane Label" << endl;  name = "Plane"; price = 30;}
	void showProduct () { cout << "Name: " << name << endl << "Price: " << price << endl;}
};

class ToyFactory
{
public:
	static Toy * createToy(int type) {
	
	Toy *toy = NULL;
	
	switch(type) {
		case 1:{
			toy = new Car;
			break;
		}
		case 2:{
			toy = new Bike;
			break;
		}
		case 3:{
			toy = new Plane;
			break;
		}
		default:{
			cout << "invalid toy type please re-enter type" << endl;
			return NULL;
		}
	}

	toy->prepareParts();
	toy->combineParts();
	toy->assembleParts();
	toy->applyLabel();
	
	return toy;
	}
	
};


int main() {
// client code starts
	int type = 1;

		Toy *v = ToyFactory::createToy(type);

		if(v){
			v->showProduct();
			delete v;
		}

	cout << "Exit.." << endl;
// client code ends
	return 0;
}