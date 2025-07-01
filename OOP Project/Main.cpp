#include "ContactsBook.h"

int main()
{
    int choice = 0;
    ContactsBook* contactsbook = nullptr;
    while (choice != 10) {
        cout << "1. Create Contacts List\n2. Add New Contact\n3. Merge Duplicates\n4. Store To File\n5. Load From File\n"
            "6. Print Contacts Sorted\n7. Print Contacts\n8. Search Contacts\n9. Display Count of Contacts\n10. Exit\n";
        cin >> choice; cin.ignore();
        switch (choice) {
        case(1): {
            int size;
            cout << "Input Size of Contacts List: ";
            cin >> size; cin.ignore();
            contactsbook = new ContactsBook(size);
            break;
        }
        case(2): {
            if (contactsbook != nullptr) {
                Contact contact;
                cin >> contact;
                contactsbook->addContact(contact);
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(3): {
            if (contactsbook != nullptr) {
                contactsbook->mergeDuplicates();
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(4): {
            if (contactsbook != nullptr) {
                string file_name;
                cout << "Enter Filename to Store Contacts: ";
                getline(cin, file_name);
                contactsbook->saveToFile(file_name);
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(5): {
            string file_name;
            cout << "Enter Filename to Load Contacts: ";
            cin >> file_name; cin.ignore();
            if (contactsbook != nullptr) {
                contactsbook->loadFromFile(file_name);
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(6): {
            string sortChoice;
            cout << "Sort by 'first_name' or 'last_name': ";
            getline(cin, sortChoice);
            if (contactsbook != nullptr) {
                contactsbook->printContactsSorted(sortChoice);
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(7): {
            if (contactsbook != nullptr) {
                contactsbook->printContacts();
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case(8): {
            if (contactsbook != nullptr) {
                int searchChoice;
                cout << "Search by:\n1. First Name and Last Name\n2. Mobile Number\n3. Address\n";
                cin >> searchChoice; cin.ignore();
                switch (searchChoice) {
                case(1): {
                    string first_name, last_name;
                    cout << "Enter First Name: ";
                    cin >> first_name; cin.ignore();
                    cout << "Enter Last Name: ";
                    cin >> last_name; cin.ignore();
                    Contact* foundContact = contactsbook->searchContact(first_name, last_name);
                    if (foundContact != nullptr) {
                        foundContact->printContact();
                        delete foundContact;
                    }
                    else {
                        cout << "Contact Not Found." << endl;
                    }
                    break;
                }
                case(2): {
                    string number;
                    cout << "Enter Mobile Number: ";
                    cin >> number; cin.ignore();
                    Contact* foundContact = contactsbook->searchContact(number);
                    if (foundContact != nullptr) {
                        foundContact->printContact();
                        delete foundContact;
                    }
                    else {
                        cout << "Contact Not Found." << endl;
                    }
                    break;
                }
                case(3): {
                    Address address;
                    cin >> address;
                    Contact* foundContact = contactsbook->searchContact(address);
                    if (foundContact != nullptr) {
                        foundContact->printContact();
                        delete foundContact;
                    }
                    else {
                        cout << "Contact Not Found." << endl;
                    }
                    break;
                }
                default:
                    cout << "Invalid Choice! Try Again." << endl;
                    break;
                }
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case 9: {
            if (contactsbook != nullptr) {
                cout << "Total Contacts: " << contactsbook->totalContacts() << endl;
            }
            else {
                cout << "Create a Contacts List First." << endl;
            }
            break;
        }
        case 10: {
            if (contactsbook != nullptr) {
                delete contactsbook;
                contactsbook = nullptr;
            }
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Invalid Choice! Try Again." << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
