#ifndef ENTRY_H
#define ENTRY_H

template<class KeyType, class ValueType>
class Entry
{
private: 
    KeyType key;
    ValueType value;
public:
    Entry() {}
    Entry(const KeyType& newKey, const ValueType& newValue);

    ValueType getValue() const;
    KeyType getKey() const;
    void setValue(const ValueType& newValue);
    void setKey(const KeyType& searchKey);
    bool operator==(const Entry<KeyType, ValueType>& rhs) const;
    bool operator>(const Entry<KeyType, ValueType>& rhs) const;
    bool operator<(const Entry<KeyType, ValueType>& rhs) const;
};

#include "Entry.cpp"

#endif