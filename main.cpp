#include <iostream>
#include <string>
#include "TreeDictionary.h"

using namespace std;

int main() 
{
    TreeDictionary<int, string> d;
    int keyWeWant = 125678;

    cout << (d.isEmpty() ? "Dictionary is empty" : "Dictionary is not empty") << endl;
    cout << "The number of entries in the dictionary is " << d.getNumberOfEntries() << ".\n";

    d.add(701283, "foo");
    d.add(125678, "bar");
    d.add(829474, "idk");

    cout << (d.isEmpty() ? "Dictionary is empty" : "Dictionary is not empty") << endl;
    cout << "The number of entries in the dictionary is " << d.getNumberOfEntries() << ".\n";

    // REMOVING ENTRIES
    d.remove(701283);
    d.remove(829474);
    cout << "The number of entries in the dictionary is " << d.getNumberOfEntries() << ".\n";

    // KEY WE WANT
    cout << (d.contains(keyWeWant) ? "Contains value." : "Does not contain value.") << endl;
    cout << "Entry: " << d.getValue(keyWeWant) << endl;

    // CLEARING THE DICTIONARY
    d.clear();
    cout << (d.isEmpty() ? "Dictionary is empty" : "Dictionary is not empty") << endl;
    cout << "The number of entries in the dictionary is " << d.getNumberOfEntries() << ".\n";

}