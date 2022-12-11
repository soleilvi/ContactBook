/*
Here are all the function definitions used in my driver.

By Soleil Vivero
12/11/22
*/

#include <iostream>
#include <string>
#include "TreeDictionary.h"

using namespace std;

// Made this into a function so that the driver would be tidier
void printInstructions()
{
    cout << "Choose an option by typing its corresponding number into the terminal:\n"
            "   1) Add a contact\n"
            "   2) Change a contact's phone number\n"
            "   3) Get a contact's phone number\n"
            "   4) Remove a contact\n"
            "   5) Display contacts\n"
            "   0) Exit the program\n\n";
}

// To lessen the hassle for the user when searching up or editing con-
// tacts, I made it so that any name the user inputs gets turned into
// lowercase 
void makeLowercase(string& str)
{
    int strSize = str.size();
    char currChar;

    for (int i = 0; i < strSize; i++)
    {  
        currChar = str.at(i);

        if (currChar <= 90 && currChar >= 65)  // Use ASCII values to compare characters
            str.at(i) = currChar + 32;         // Add 32 to get that letter in lowercase
    }
}

// Adds a contact to the contact book
void addContact(TreeDictionary<string, string>& dictionary, string keys[])
{
    string contactName;
    string contactPhone;
    int newKeyIndex = dictionary.getNumberOfEntries();

    cout << "\n--ADD A CONTACT--\n";
    cout << "Type the name of the contact you want to add: ";
    cin.ignore();                // Ignores the newline that comes after input by default (prevents skipping input)
    getline(cin, contactName);   // Also accepts spaces in case they want to add a last name
    makeLowercase(contactName);

    if (dictionary.contains(contactName))
    {
        cout << "That contact already exists! Please use the 2nd option to change their phone number.\n\n";
        return;
    }

    cout << "Type your contact's phone number: ";
    getline(cin, contactPhone);  // There could be a space if they format the number as something like (###) ###-####

    dictionary.add(contactName, contactPhone);
    keys[newKeyIndex] = contactName;

    cout << "Contact added!\n\n";
}

// Change the phone number of one of your contacts
void editContact(TreeDictionary<string, string>& dictionary)
{
    string contactName;
    string contactPhone;

    cout << "\n--EDIT A CONTACT--\n";

    cout << "Type the name of the contact you want to edit: ";
    cin.ignore();
    getline(cin, contactName);
    makeLowercase(contactName);

    if (!dictionary.contains(contactName))
    {
        cout << "The contact you tried to edit does not exist. Please try again.\n\n";
        return;
    }

    cout << "Type your contact's new phone number: ";
    cin.ignore();
    getline(cin, contactPhone);

    dictionary.remove(contactName);
    dictionary.add(contactName, contactPhone);

    cout << "Contact info successfully changed.\n\n";
}

// Get the phone number of one of your contacts
void displayPhoneNumber(TreeDictionary<string, string>& dictionary)
{
    string contactName;

    cout << "\n--GET A PHONE NUMBER--\n";

    cout << "Type the name of the contact whose number you want: ";
    cin.ignore();
    getline(cin, contactName);
    makeLowercase(contactName);

    if (!dictionary.contains(contactName))
    {
        cout << "The contact you tried to access does not exist. Please try again.\n\n";
        return;
    }

    cout << contactName << "'s phone number is: " << dictionary.getValue(contactName) << "\n\n";
}

// Removes a contact from your contact book (ouch)
void removeContact(TreeDictionary<string, string>& dictionary, string keys[])
{
    string contactName;
    int dictSize = dictionary.getNumberOfEntries();

    cout << "\n--REMOVE A CONTACT--\n";

    cout << "Type the name of the contact you want to remove: ";
    cin.ignore();
    getline(cin, contactName);
    makeLowercase(contactName);

    if (!dictionary.contains(contactName))
    {
        cout << "The contact you tried to remove does not exist. Please try again.\n\n";
        return;
    }

    // Remove the value from the keys array
    for (int i = 0; i < dictSize; i++)
    {
        if (keys[i] == contactName)
            keys[i] = keys[dictSize - 1];  // Override the contact you want to remove with the last one
    }

    dictionary.remove(contactName);
    cout << "Contact removed.\n\n";
}

// Prints your entire contact book to the terminal
void displayContacts(TreeDictionary<string, string>& dictionary, string keys[])
{
    int itemsInDictionary = dictionary.getNumberOfEntries();
    string key;
    string value;

    cout << "\n--CONTACT LIST--\n";

    for (int i = 0; i < itemsInDictionary; i++)
    {
        // Store the current key and value
        key = keys[i];
        value = dictionary.getValue(keys[i]);
        
        // Format it
        cout << "   - " << keys[i] << ": " << value << endl;
    }

    cout << endl;
}