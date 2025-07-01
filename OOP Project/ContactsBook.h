#pragma once
#include "Contact.h"

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
	using namespace std;
#endif

class ContactsBook {
private:
	Contact *contacts_list; 
	int size_of_contacts;   
	int contacts_count;    
public:
	void addContact(const Contact& contact);
	int totalContacts() const;

	Contact* searchContact(string first_name, string last_name) const;
	Contact* searchContact(string phone) const;
	Contact* searchContact(const Address& address) const;
	
	Contact* copyArray() const;
	ContactsBook(int);
	ContactsBook() {}
	~ContactsBook();
	ContactsBook(const ContactsBook& other);
	ContactsBook& operator=(const ContactsBook& other);

	void printContacts() const;
	void printContactsSorted(string choice);
	void mergeDuplicates(); 

	void loadFromFile(string file_name);
	void saveToFile(string file_name);

	bool full() const;
	void resizeList();
	void sortContactsList(Contact *contacts_list, string choice) const;
};
