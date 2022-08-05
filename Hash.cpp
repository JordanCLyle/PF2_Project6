#include "Hash.h"

HashTable::HashTable()
{
}


HashTable::~HashTable()
{
}


void HashTable::Insert(string city, Address addr)
{
	// Find hash index
	int index = Hash(addr.getcityName()); // Index is a hash made from a city name
	AddressVector[index].push_back(addr); // Address value gets stored at the hash
}

//(search)

void HashTable::Search(string city)
{
  int index = Hash(city); // Creates the index from the given city
  for (unsigned int pos = 0; pos < AddressVector[index].size(); pos++) // Prints all cities with that index
  {
	  if (AddressVector[index][pos].getcityName() == city)
	  {
		  AddressVector[index][pos].print();
	  }
  }
}

vector<Address> HashTable::Read()
{
	// Reads in data into the personPeople vector of Addresses
	string filename = "address.txt";
	ifstream din;
	Address person;
	vector<Address> personPeople;
	din.open(filename.c_str());
	if (din.fail())
	{
		cout << "Error: could not open file" << endl;
		return personPeople;
	}
	else
	{
		while (!din.eof())
		{
			//cout << "Started reading";
			string Street, CityName, StateofResidence;
			int HouseNumber, ZIPcode;
			din >> HouseNumber;
			//cout << endl << HouseNumber;
			din.ignore();
			getline(din, Street);
			//cout << endl << Street;
			getline(din, CityName);
			//cout << endl << CityName;
			getline(din, StateofResidence);
			//cout << endl << StateofResidence;
			din >> ZIPcode;
			//cout << endl << ZIPcode;
			person.sethouseNumber(HouseNumber);
			//cout << "done reading2";
			person.setstreetName(Street);
			person.setcityName(CityName);
			person.setState(StateofResidence);
			person.setzipCode(ZIPcode);
			personPeople.push_back(person);
		}
		return personPeople;
	}
}

void HashTable::Write()
{
	// Cycles through all arrays in the vector and all addresses in the arrays and prints them.
	ofstream dout;
	dout.open("hash_address.txt");
	unsigned int i = 0;
	unsigned int j = 0;
	if (dout.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not create file" << endl;
	}
	else
	{
		while (j < 300)
		{
			while (i < AddressVector[j].size())
			{
				dout << AddressVector[j][i].gethouseNumber() << endl << AddressVector[j][i].getstreetName() << endl << AddressVector[j][i].getcityName() << endl << AddressVector[j][i].getState() << endl << AddressVector[j][i].getzipCode();
				dout << endl << endl;
				i++;
			}
			i = 0;
			j++;
		}
	}
}

