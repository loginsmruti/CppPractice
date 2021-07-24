#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>

/*
 * Generic implementation to search if a given value exists in a map or not.
 * Adds all the keys with given value in the vector
 */
template<typename K, typename V>
bool findByValue(std::vector<K> & vec, std::map<K, V> mapOfElemen, V value)
{
	bool bResult = false;
	auto it = mapOfElemen.begin();
	// Iterate through the map
	while(it != mapOfElemen.end())
	{
		// Check if value of this entry matches with given value
		if(it->second == value)
		{
			// Yes found
			bResult = true;
			// Push the key in given map
			vec.push_back(it->first);
		}
		// Go to next entry in map
		it++;
	}
	return bResult;
}

int main() {

	// Map of string & int i.e. words as key & there
	// occurrence count as values
	std::map<std::string, int> wordMap = {
				{ "is", 6 },
				{ "the", 5 },
				{ "hat", 9 },
				{ "at", 6 }
			};

	// Create a vector of string
	std::vector<std::string> vec;

	int value = 6;

	// Find all the keys with value 6
	bool result = findByValue(vec, wordMap, value);

	if(result)
	{
		std::cout<<"Keys with value "<< value<< " are,"<<std::endl;
		for(auto elem : vec)
		{
			std::cout<<elem<<std::endl;
		}
	}
	else
	{
		std::cout<<"No Key is found with the given value"<<std::endl;
	}

	return 0;
}