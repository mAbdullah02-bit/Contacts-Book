#pragma once
#include "Address.h"

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
	using namespace std;
#endif

class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address* address;
public:
	friend istream& operator>>(istream&, Contact&);
	bool equals(const Contact) const;
	Contact* copyContact() const;
	
	void setFirstName(const string&);
	void setLastName(const string&);
	void setMobileNumber(const string&);
	void setEmailAddress(const string&);
	void setAddress(Address*);
	
	string getFirstName() const;
	string getLastName() const;
	string getMobileNumber() const;
	string getEmailAddress() const;
	Address* getAddress() const;
	
	void printContact() const;

	Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address);
	Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	~Contact();
};