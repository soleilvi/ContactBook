#include "TreeDictionary.h"

// Functional
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const
{
    return entryTree.isEmpty();
}

// Functional
template<class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
    return entryTree.getNumberOfNodes();
}

// Functional
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue)
{
    Entry<KeyType, ValueType> newEntry(newKey, newValue);
    return entryTree.add(newEntry);  // The tree's add method already returns a bool
}

// Functional (most likely)
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& targetKey)
{
    // Call constructor of the template to get the entry value we want
    return entryTree.remove(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

// Functional
template<class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear()
{
    entryTree.clear();
}

// Functional
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const
{
    return entryTree.contains(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

// Functional
template<class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const
{
    return entryTree.getEntry(Entry<KeyType, ValueType>(targetKey, ValueType())).getValue();
}