#include <iostream>
#include <cstring>

#define __STDC_WANT_LIB_EXT1__ 1
 
template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size];
 
public:
	T* getArray() { return m_array; }
 
	T& operator[](int index)
	{
		return m_array[index];
	}
};
 
template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count] << ' ';
}
 
// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(StaticArray<char, 14> &array)
{
	for (int count = 0; count < 14; ++count)
		std::cout << array[count];
}
 
int main()
{
    // declare an char array
    StaticArray<char, 14> char14;
 
    //strcpy_s(char14.getArray(), 14, "Hello, world!");
    strcpy(char14.getArray() , "Hello, world!");
 
    // Print the array
    print(char14);
 
    return 0;
}
