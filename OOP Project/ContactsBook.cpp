#include "ContactsBook.h"
#include<fstream>

void ContactsBook::addContact(const Contact& c1) {
	if (this->full() == true) {
		this->resizeList();
	}
	contacts_list[contacts_count] = c1;
	contacts_count++;
}

int ContactsBook::totalContacts() const {
	return contacts_count;
}

bool ContactsBook::full() const {
	if (size_of_contacts == contacts_count) {
		return true;
	}
	else return false;
}

void ContactsBook::resizeList() {
	int new_size = 2 * size_of_contacts;
	Contact* temp = new Contact[new_size];
	for (int i = 0; i < size_of_contacts; i++) {
		temp[i] = *contacts_list[i].copyContact();
	}
	delete[] contacts_list;
	contacts_list = temp;
	size_of_contacts = new_size;
}

Contact* ContactsBook::searchContact(string first_name, string last_name) const {
	for (int i = 0; i < contacts_count; i++) {
		if (contacts_list[i].getFirstName() == first_name && contacts_list[i].getLastName() == last_name) {
			return contacts_list[i].copyContact();
		}
	}
	return nullptr;
}

Contact* ContactsBook::searchContact(string mobile) const {
	for (int i = 0; i < contacts_count; i++) {
		if (contacts_list[i].getMobileNumber() == mobile) {
			return contacts_list[i].copyContact();
		}
	}
	return nullptr;
}

Contact* ContactsBook::searchContact(const Address& address) const {
	for (int i = 0; i < contacts_count; i++) {
		if (contacts_list[i].getAddress()->equals(address) == true) {
			return contacts_list[i].copyContact();
		}
	}
	return nullptr;
}

ContactsBook::ContactsBook(int size_of_list = 0) : size_of_contacts(size_of_list), contacts_count(0) {
	contacts_list = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++) {
		contacts_list[i] = Contact();
	}
}

ContactsBook::ContactsBook(const ContactsBook& other) {
	size_of_contacts = other.size_of_contacts;
	contacts_count = other.contacts_count;
	contacts_list = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		Contact* copiedContact = other.contacts_list[i].copyContact();
		if (copiedContact != nullptr) {
			this->contacts_list[i] = *copiedContact;
			delete copiedContact;
		}
	}
}

ContactsBook& ContactsBook::operator=(const ContactsBook& other) {
	if (this != &other) {
		delete[] contacts_list;
		size_of_contacts = other.size_of_contacts;
		contacts_count = other.contacts_count;
		contacts_list = new Contact[size_of_contacts];
		for (int i = 0; i < contacts_count; i++) {
			Contact* copiedContact = other.contacts_list[i].copyContact();
			if (copiedContact != nullptr) {
				this->contacts_list[i] = *copiedContact;
				delete copiedContact;
			}
		}
	}
	return *this;
}

void ContactsBook::printContactsSorted(string choice) {
	Contact* copy = this->copyArray();
	sortContactsList(copy, choice);
	for (int i = 0; i < contacts_count; i++) {
		cout << "[" << copy[i].getFirstName() << "] [" << copy[i].getLastName() << "] [" << copy[i].getMobileNumber() << "] [" << copy[i].getEmailAddress() << "]" << endl;
		copy[i].getAddress()->printAddress();
	}
	delete[] copy;
}

void ContactsBook::sortContactsList(Contact *contacts_list, string choice) const {
		for (int i = 0; i < size_of_contacts - 1; i++) {
			for (int j = 0; j < size_of_contacts - i - 1; j++) {
				if ((choice == "first_name" && contacts_list[j].getFirstName() > contacts_list[j + 1].getFirstName() && contacts_list[j + 1].getFirstName() != "") ||
					(choice == "last_name" && contacts_list[j].getLastName() > contacts_list[j + 1].getLastName() && contacts_list[j + 1].getLastName() != "")) {
					swap(contacts_list[j], contacts_list[j + 1]);
				}
			}
		}
}

void ContactsBook::mergeDuplicates() {
	int count = 0;
	for (int i = 0; i < contacts_count; i++) {
		for (int j = i + 1; j < contacts_count; j++) {
			if (contacts_list[i].equals(contacts_list[j])) {
				contacts_list[i] = contacts_list[contacts_count - 1];
				contacts_list[contacts_count - 1] = Contact();
				contacts_count--;
				count++; 
				j--;
			}
		}
	}
	cout << "Merged Contacts: " << count << endl;
}

void ContactsBook::loadFromFile(string file_name) {
	int contacts_count;
	string first_name, last_name, mobile_number, email_address, house, street, city, country;
	ifstream input_file(file_name);
	if (!input_file.is_open()) {
		cout << "Error Opening File!" << endl;
		return;
	}
	input_file >> contacts_count;
	if (contacts_count > size_of_contacts) {
		resizeList();
	}
	for (int i = 0; i < contacts_count; i++) {
		input_file >> first_name >> last_name >> mobile_number >> email_address >> house >> street >> city >> country;
		Address address(house, street, city, country);
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		this->addContact(contact);
	}
	input_file.close();
}

void ContactsBook::saveToFile(string file_name) {
	ofstream output_file(file_name);
	if (!output_file.is_open()) {
		cout << "Error Opening File!" << endl;
		return;
	}
	output_file << contacts_count << endl;
	for (int i = 0; i < contacts_count; i++) {
		output_file << contacts_list[i].getFirstName() << ", " << contacts_list[i].getLastName() << ", " << contacts_list[i].getMobileNumber() << ", " <<
			contacts_list[i].getEmailAddress() << endl;
		output_file << contacts_list[i].getAddress()->getHouse() << ", " << contacts_list[i].getAddress()->getStreet() << ", " <<
			contacts_list[i].getAddress()->getCity() << ", " << contacts_list[i].getAddress()->getCountry() << endl;
	}
	output_file.close();
}

Contact* ContactsBook::copyArray() const {
	Contact* temp = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++) {
		temp[i] = *contacts_list[i].copyContact();
	}
	return temp;
}

void ContactsBook::printContacts() const {
	for (int i = 0; i < contacts_count; i++) {
		cout << "[" << contacts_list[i].getFirstName() << "] [" << contacts_list[i].getLastName() << "] [" << contacts_list[i].getMobileNumber() << "] [" << contacts_list[i].getEmailAddress() << "]" << endl;
		contacts_list[i].getAddress()->printAddress();
	}
}

ContactsBook::~ContactsBook() {
	delete[] contacts_list;
}
