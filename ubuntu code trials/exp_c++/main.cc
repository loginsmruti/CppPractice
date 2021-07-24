//main.cpp
#include <iostream>
#include "Dog.h"

using namespace std;

int main()
{

	Dog myDogs[5];

	for (int i = 0; i <= 4; i++)
		myDogs[i].setAge( i * 2);

	for (int i = 0; i <= 4; i++)
		cout << "Dog number " << i << " is " << myDogs[i].getAge() << " years old!\n";

//	delete [] myDogs;




	return 0;
}
