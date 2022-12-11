/*
Method definitions for the dictionary class. Since the binary search
tree we are using to store the entries already implements all the met-
hods we want to use, all we need to do is pass in the data in a way
that will make it work as a dictionary.

By Soleil Vivero
12/10/22
*/

#include "TreeDictionary.h"

// Returns true when entryTree is empty and false when it isn't.
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const
{
    return entryTree.isEmpty();
}

// Returns how many entries we have stored in the dictionary.
template<class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
    return entryTree.getNumberOfNodes();
}

// Adds a new entry object to the dictionary with the keys and values
// passed in from the user.
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue)
{
    return entryTree.add(Entry<KeyType, ValueType>(newKey, newValue));  // The tree's add method already returns a bool
}

// Removes an entry from the dictionary. The argument ValueType() is
// the template ValueType's constructor, which essentially tells the
// program that it doesn't care what the value of the entry is.
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& targetKey)
{
    return entryTree.remove(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

// Removes all the values from the dictionary.
template<class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear()
{
    entryTree.clear();
}

// Returns true if the item the user wants is in the dictionary; othe-
// rwise, it returns false.
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const
{
    return entryTree.contains(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

// Returns the entry the user wants.
template<class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const
{
    return entryTree.getEntry(Entry<KeyType, ValueType>(targetKey, ValueType())).getValue();
}