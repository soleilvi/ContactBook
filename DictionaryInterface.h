/*
Dictionary interface provided to us by the professor.
*/

#ifndef DICTIONARY_INTERFACE
#define DICTIONARY_INTERFACE

template<class KeyType, class ValueType>
class DictionaryInterface
{
public:
    virtual bool isEmpty() const = 0; 
    virtual int getNumberOfEntries() const = 0;
    virtual bool add(const KeyType& newKey, const ValueType& newValue) = 0; 
    virtual bool remove(const KeyType& targetKey) = 0; 
    virtual void clear() = 0; 
    virtual bool contains(const KeyType& targetKey) const = 0;
    virtual ValueType getValue(const KeyType& targetKey) const = 0;
    virtual ~DictionaryInterface() { }
};

#endif