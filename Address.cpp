//----------------------------------------------
// Purpose: Demonstrate address ADT
// Author:  John Gauch
//----------------------------------------------

#include "Address.h"

//----------------------------------------------
Address::Address()
{
    houseNumber = 0;
    streetName = "";
    cityName = "";
    State = "";
    zipCode = 0;
}

//----------------------------------------------
Address::Address(int housenumber, string streetname, string city, string state, int zipcode)
{
    houseNumber = housenumber;
    streetName = streetname;
    cityName = city;
    State = state;
    zipCode = zipcode;
}

//----------------------------------------------
Address::Address(const Address& address)
{
    houseNumber = address.houseNumber;
    streetName = address.streetName;
    cityName = address.cityName;
    State = address.State;
    zipCode = address.zipCode;
}

//----------------------------------------------
Address::~Address()
{
}

//----------------------------------------------
int Address::gethouseNumber() const
{
    return houseNumber;
}

//----------------------------------------------
string Address::getstreetName() const
{
    return streetName;
}

//----------------------------------------------
string Address::getcityName() const
{
    return cityName;
}

//----------------------------------------------
string Address::getState() const
{
    return State;
}

//----------------------------------------------
int Address::getzipCode() const
{
    return zipCode;
}

//----------------------------------------------
void Address::sethouseNumber(int housenumber)
{
    houseNumber = housenumber;
}

//----------------------------------------------
void Address::setstreetName(string streetname)
{
    streetName = streetname;
}

//----------------------------------------------
void Address::setcityName(string city)
{
    cityName = city;
}

//----------------------------------------------
void Address::setState(string state)
{
    State = state;
}

//----------------------------------------------
void Address::setzipCode(int zipcode)
{
    zipCode = zipcode;
}

//----------------------------------------------
void Address::print() const
{
    cout << "House Number: " << houseNumber << "\n"
        << "Street Name: " << streetName << "\n" << "City Name: " << cityName << "\n"
        << "State: " << State << "\n" << "Zip Code: " << zipCode << "\n" << endl;
}
