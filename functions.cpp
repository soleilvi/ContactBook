#include <iostream>
#include <string>
#include "TreeDictionary.h"

using namespace std;

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

void makeLowercase(string& str)
{
    int strSize = str.size();
    char currChar;

    for (int i = 0; i < strSize; i++)
    {  
        currChar = str.at(i);

        if (currChar <= 90 && currChar >= 65)  // Use ASCII values to compare characters
            str.at(i) = currChar + 32;         // Add 32 to get that letter in uppercase
    }
}

void addContact(TreeDictionary<string, string>& dictionary, string keys[])
{
    string contactName;
    string contactPhone;
    int newKeyIndex = dictionary.getNumberOfEntries();

    cout << "\n--ADD A CONTACT--\n";
    cout << "Type the name of the contact you want to add: ";
    cin >> contactName;
    makeLowercase(contactName);

    cout << "Type your contact's phone number: ";
    cin >> contactPhone;

    dictionary.add(contactName, contactPhone);
    keys[newKeyIndex] = contactName;

    cout << "Contact added!\n\n";
}

void editContact(TreeDictionary<string, string>& dictionary)
{
    string contactName;
    string contactPhone;

    cout << "\n--EDIT A CONTACT--\n";

    cout << "Type the name of the contact you want to edit: ";
    cin >> contactName;
    makeLowercase(contactName);

    if (!dictionary.contains(contactName))
    {
        cout << "Error: The contact you tried to edit does not exist. Please try again.\n\n";
        return;
    }

    cout << "Type your contact's new phone number: ";
    cin >> contactPhone;

    dictionary.remove(contactName);
    dictionary.add(contactName, contactPhone);

    cout << "Contact info successfully changed.\n\n";
}

void displayPhoneNumber(TreeDictionary<string, string>& dictionary)
{
    string contactName;
    string contactPhone;

    cout << "\n--GET A PHONE NUMBER--\n";

    cout << "Type the name of the contact whose number you want: ";
    cin >> contactName;
    makeLowercase(contactName);

    if (!dictionary.contains(contactName))
    {
        cout << "Error: The contact you tried to access does not exist. Please try again.\n\n";
        return;
    }

    cout << contactName << "'s phone number is: " << dictionary.getValue(contactName) << "\n\n";
}

void removeContact(TreeDictionary<string, string>& dictionary)
{
    string contactName;

    cout << "\n--REMOVE A CONTACT--\n";

    cout << "Type the name of the contact you want to remove:\n";
    cin >> contactName;
    makeLowercase(contactName);

    dictionary.remove(contactName);
}

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