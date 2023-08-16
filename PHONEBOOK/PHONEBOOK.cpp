#include <iostream>
#include <cstring> // Include the cstring header for strcmp

using namespace std;

#define MAX_CONT 100

struct Contact {
    char namefirst[100];
    char lastname[30]; /* Last Name */
    char number[100];
    char notes[100];
};

class PhoneBook {
    Contact contact;

public:
    bool Create() { return contact.namefirst[0] == '\0'; }
    void Edit();
    void Delete() { contact.namefirst[0] = '\0'; }
    void Print(bool showall);
    bool SearchContact(char searchThis[100]);
};

void PhoneBook::Edit() {
    cout << endl << "Enter First Name: ";
    cin >> contact.namefirst;
    cout << endl << "Enter Last Name: ";
    cin >> contact.lastname;
    cout << endl << "Enter Number: ";
    cin >> contact.number;
    cout << endl << "Enter Notes: ";
    cin >> contact.notes;
}

void PhoneBook::Print(bool showall) {
    cout << endl << "First Name: " << contact.namefirst << endl << "Last Name: " << contact.lastname;
    if (showall) {
        cout << endl << "Number: " << contact.number
             << endl << "Notes: " << contact.notes << endl;
    }
}

bool PhoneBook::SearchContact(char searchThis[100]) {
    if (!strcmp(contact.namefirst, searchThis)) {
        return true;
    } else if (!strcmp(contact.lastname, searchThis)) {
        return true;
    } else if (!strcmp(contact.number, searchThis)) {
        return true;
    } else if (!strcmp(contact.notes, searchThis)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    PhoneBook phonebk[MAX_CONT];
    char OPTION = '0';
    int i;
    char list[60];
    bool person;

    for (int h = 0; h < MAX_CONT; h++) {
        phonebk[h].Delete();
    }

    while (OPTION != 'q') {
        person = false;
        i = 0;

        cout << endl << "Please select an option:" << endl
             << "\"e\" to create an entry" << endl
             << "\"z\" to edit a contact" << endl
             << "\"d\" to delete an entry" << endl
             << "\"f\" to find a contact" << endl
             << "\"l\" to list all contacts" << endl
             << "\"q\" to terminate the program" << endl;

        cout << endl << "Enter your option: ";
        cin >> OPTION;

        switch (OPTION) {
            case 'e':
                do {
                    if (phonebk[i].Create()) {
                        phonebk[i].Edit();
                        person = true;
                    }
                    i++;
                } while (i < MAX_CONT && !person);
                break;
            case 'z':
                cout << "Enter name of contact you wish to edit: ";
                cin >> list;
                if (phonebk[i].SearchContact(list) && !phonebk[i].Create()) {
                    cout << endl << "Edit: ";
                    phonebk[i].Print(false);
                    phonebk[i].Edit();
                } else {
                    i++;
                }
                break;
            case 'd':
                cout << "Enter name of contact you wish to delete: ";
                cin >> list;
                if (phonebk[i].SearchContact(list) && !phonebk[i].Create()) {
                    cout << endl << "Delete: ";
                    phonebk[i].Print(true);
                    cout << endl << "Confirm deletion (y/n): ";
                    cin >> list[0];
                    if (list[0] == 'y') {
                        phonebk[i].Delete();
                    }
                } else {
                    i++;
                }
                break;
            case 'f':
                cout << "Enter name, last name, number, or notes to find: ";
                cin >> list;
                for (int j = 0; j < MAX_CONT; j++) {
                    if (phonebk[j].SearchContact(list)) {
                        phonebk[j].Print(true);
                    }
                }
                break;
            case 'l':
                cout << endl << "Listing all contacts: " << endl;
                for (int j = 0; j < MAX_CONT; j++) {
                    if (!phonebk[j].Create()) {
                        phonebk[j].Print(true);
                    }
                }
                break;
            case 'q':
                cout << "Terminating the program." << endl;
                break;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;
}

