#include "TreeDictionary.h"

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const
{
    return entryTree.isEmpty();
}

template<class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
    return entryTree.getNumberOfNodes();
}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue)
{
    return entryTree.add(Entry<KeyType, ValueType>(newKey, newValue));  // The tree's add method already returns a bool
}

// Call constructor of the template to get the entry value we want
template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& targetKey)
{
    return entryTree.remove(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

template<class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear()
{
    entryTree.clear();
}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const
{
    return entryTree.contains(Entry<KeyType, ValueType>(targetKey, ValueType()));
}

template<class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const
{
    return entryTree.getEntry(Entry<KeyType, ValueType>(targetKey, ValueType())).getValue();
}