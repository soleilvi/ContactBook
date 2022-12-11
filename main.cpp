/*
This program was meant as practice for working with dictionaries. I
implemented a dictionary using a binary search tree and used it to
make a small program for storing contacts. It has no GUI; it runs in
the terminal. Type "make" and "./hw8" into the terminal to run it.

By Soleil Vivero
12/10/22
*/

#include <iostream>
#include <string>

#include "functions.cpp"
#include "TreeDictionary.h"

#define ARR_CAPACITY 100

using namespace std;

int main() 
{
    TreeDictionary<string, string> contactBook;
    string keys[ARR_CAPACITY - 1];  // Stores the names of the people the user passes in
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
            removeContact(contactBook, keys);
            break;

        case 5:
            displayContacts(contactBook, keys);
            break;
        
        default:
            cout << "Invalid input, please try again.\n\n";
            break;
        }
    }
}