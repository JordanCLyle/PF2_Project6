// Jordan_Lyle_Project_6_Midpoint_PF2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Hash.h"



void insertion_sort(vector<Address>& person, int low, int high) // Implementation of insertion sort from Gauch code (with only slight modifications)
{
	// Insert each element of unsorted list into sorted list
	for (int unsorted = low + 1; unsorted <= high; unsorted++)
	{
		Address temp;
		// Select unsorted value to be inserted
		Address value = person[unsorted];
		int posn = unsorted;
		
		// Make room for new data value
		temp = person[posn];
		while ((posn > 0) && (person[posn - 1].getzipCode() > value.getzipCode()))
		{
			person[posn] = person[posn - 1];
			posn--;
		}

		// Put new value into array
		person[posn] = value;
	}
}

void read_address(vector<Address> &people)
{
	string filename = "address.txt";
	ifstream din;
	din.open(filename.c_str());
	if (din.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not open file" << endl;
	}
	else
	{
		while (!din.eof()) // This reads everything in from the file into the people vector located in main.
		{
			//cout << "Started reading";
			Address person;
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
			people.push_back(person);
		}
		insertion_sort(people, 0, people.size() - 1); // Sorts data before it becomes printed
	}
}


void write_address(const vector<Address> people)
{
	ofstream dout;
	dout.open("sort_address.txt");
	unsigned int i = 0;
	if (dout.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not create file" << endl;
	}
	else
	{ // Prints all of the information for every value in the vector of objects
		while (i < people.size())
		{
			dout << people[i].gethouseNumber() << endl << people[i].getstreetName() << endl << people[i].getcityName() << endl << people[i].getState() << endl << people[i].getzipCode();
			dout << endl << endl;
		    i++;
			// Very similar to read file except outputting the list in the correct format.
		}
	}
}





int main()
{
	HashTable goodTable; // Table object
	vector <Address> sortingVector; // Vector of address objects
	string Cityname; // String for the search method of table
	unsigned int i = 0; // Count
	sortingVector = goodTable.Read(); //Values that are read into the address vector in the table class get transfered to a vector in main
	insertion_sort(sortingVector, 0, sortingVector.size() - 1); // Insertion sort sorts the vector using the main function
	while (i < sortingVector.size())
	{
		goodTable.Insert(sortingVector[i].getcityName(), sortingVector[i]); // The vector in main is now inserted into the vector of arrays in the Table class with a hash
		i++;
	}
	goodTable.Write(); // The Table class vector of arrays of addresses is written to a file.
	cout << "What city name would like to search for?: "; // Prompts the user
	cin >> Cityname; // Takes the input
	goodTable.Search(Cityname); // Prints all addresses that have the matching city in the Table vector of arrays

	vector<Address> people;
	read_address(people); // Reads in data normally.
	write_address(people); // Writes out data normally.

	return 0;
}
