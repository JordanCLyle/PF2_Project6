#ifndef ADDRESS_H
#define ADDRESS_H

//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Address
{
public:
	// Constructors 
	Address();
	Address(int housenumber, string streetname, string city, string state, int zipcode);
	Address(const Address& address);
	~Address();

	// Normal Methods
	int gethouseNumber() const;
	string getstreetName() const;
	string getcityName() const;
	string getState() const;
	int getzipCode() const;
	void sethouseNumber(int houseNumber);
	void setstreetName(string streetname);
	void setcityName(string city);
	void setState(string state);
	void setzipCode(int zipcode);
	void print() const;

private:
	// Normal constructors
	int houseNumber;
	string streetName;
	string cityName;
	string State;
	int zipCode;
};

#endif
