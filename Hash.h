
#include "Address.h"

const int SIZE = 300;

class HashTable
{
public:
	HashTable();
	~HashTable();

	void Insert(string city, Address addr);
	void Search(string city);
	vector<Address> Read();
	void Write();

private:
	// Private methods
	int Hash(string city)
	{
		int hash = 0;
		for (unsigned int i = 0; i < city.length(); i++) // While the count is less than the characters in the name of the city.
		{
			hash = hash + city[i]; // Makes the hash
		}
		return hash % 300; // Keeps the hash within 300 (max size of the array)
	}
	// Private data
	Address person;
	vector<Address> AddressVector[SIZE];
};
