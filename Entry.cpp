/*
Method definitions for the Entry class.

By Soleil Vivero
12/10/22
*/

#include "Entry.h"

template<class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry(const KeyType& newKey, const ValueType& newValue) 
{
    key = newKey;
    value = newValue;
}

template<class KeyType, class ValueType>
ValueType Entry<KeyType, ValueType>::getValue() const 
{
    return value;
}

template<class KeyType, class ValueType>
KeyType Entry<KeyType, ValueType>::getKey() const 
{
    return key;
}

template<class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setValue(const ValueType& newValue) 
{
    value = newValue;
}

template<class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setKey(const KeyType& searchKey) 
{
    key = searchKey;
}

template<class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType, ValueType>& rhs) const
{
    return key == rhs.getKey();
}

template<class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType, ValueType>& rhs) const
{
    return key > rhs.getKey();
}

template<class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator<(const Entry<KeyType, ValueType>& rhs) const
{
    return key < rhs.getKey();
}