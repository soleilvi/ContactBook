#include <iostream>
#include <string>

#include "functions.cpp"
#include "TreeDictionary.h"

#define ARR_CAPACITY 100

using namespace std;

int main() 
{
    TreeDictionary<string, string> contactBook;  // Int will turn into a phone class/struct
    string keys[ARR_CAPACITY - 1];
    bool run = true;
    int usrInput;

    cout << "Welcome to your contact book.\n\n";

    while(run)
    {
        printInstructions();
        cout << "Select your choice: ";
        cin >> usrInput;

        switch (usrInput)
        {
        case 0:
            run = false;
            break;

        case 1:
            addContact(contactBook, keys);
            break;
        
        case 2:
            editContact(contactBook);
            break;
        
        case 3:
            displayPhoneNumber(contactBook);
            break;

        case 4:
            removeContact(contactBook);
            break;

        case 5:
            displayContacts(contactBook, keys);
            break;
        
        default:
            cout << "Invalid input, please try again.\n";
            break;
        }
    }
}