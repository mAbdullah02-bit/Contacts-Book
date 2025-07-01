#include "Address.h"

Address::Address() {
	house = "";
	street = "";
	city = "";
	country = "";
}

Address::Address(string house, string street, string city, string country) : house(house), street(street), city(city), country(country) {}

void Address::setHouse(const string& h1) {
	house = h1;
}

void Address::setStreet(const string& s1) {
	street = s1;
}

void Address::setCity(const string& c1) {
	city = c1;
}

void Address::setCountry(const string& c1) {
	country = c1;
}

string Address::getHouse() const {
	return house;
}

string Address::getStreet() const {
	return street;
}

string Address::getCity() const {
	return city;
}

string Address::getCountry() const {
	return country;
}

bool Address::equals(const Address& address) const {
	if (address.city == this->city && address.country == this->country && address.house == this->house && address.street == this->street) {
		return true;
	}
	else return false;
}

void Address::printAddress() const {
	cout << house << ", " << street << ", " << city << ", " << country << endl;
}

Address Address::copyAddress() const {
	return Address(house, street, city, country);
}

istream& operator>>(istream& i, Address& a1) {
	string house, street, city, country;

	cout << "Enter House: ";
	getline(i, house);
	cout << "Enter Street: ";
	getline(i, street);
	cout << "Enter City: ";
	getline(i, city);
	cout << "Enter Country: ";
	getline(i, country);

	a1.setHouse(house);
	a1.setStreet(street);
	a1.setCity(city);
	a1.setCountry(country);

	return i;
}

