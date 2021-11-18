#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>

/*
 * Generic implementation to erase elements by value
 * It iterates over all the elements and for every element it matches
 * the value with the passed value, if it matches then it will delete
 * that entry and move to next.
 */
template<typename K, typename V>
int erase_if(std::map<K, V> & mapOfElemen, V value)
{
	int totalDeletedElements = 0;
	auto it = mapOfElemen.begin();
	// Iterate through the map
	while (it != mapOfElemen.end())
	{
		// Check if value of this entry matches with given value
		if (it->second == value)
		{
			totalDeletedElements++;
			// Erase the current element, erase() will return the
			// next iterator. So, don't need to increment
			it = mapOfElemen.erase(it);
		}
		else
		{
			// Go to next entry in map
			it++;
		}
	}
	return totalDeletedElements;
}

int main() {

	// Map of string & int i.e. words as key & there
	// occurrence count as values
	std::map<std::string, int> wordMap = { { "is", 6 }, { "the", 5 },
			{ "hat", 9 }, { "at", 6 } };

	std::cout << "Map Entries Before Deletion" << std::endl;
	// Print the map elements
	for (auto elem : wordMap)
		std::cout << elem.first << " :: " << elem.second << std::endl;

	// Erase all the elements with value 6
	int deletedCount = erase_if(wordMap, 6);

	std::cout << "Total elements deleted = " << deletedCount << std::endl;

	std::cout << "Map Entries After Deletion" << std::endl;
	// Print the map elements
	for (auto elem : wordMap)
		std::cout << elem.first << " :: " << elem.second << std::endl;

	return 0;
}