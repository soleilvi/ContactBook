#ifndef TREE_DICTIONARY
#define TREE_DICTIONARY

#include "DictionaryInterface.h"
#include "LinkedBSearchTree.h"
#include "Entry.h"

template<class KeyType, class ValueType>
class TreeDictionary : public DictionaryInterface<KeyType, ValueType>
{
private:
    LinkedBSearchTree<Entry<KeyType, ValueType> > entryTree;

public:
    TreeDictionary() {}
    bool isEmpty() const;
    int getNumberOfEntries() const;
    bool add(const KeyType& newKey, const ValueType& newValue);
    bool remove(const KeyType& targetKey);
    void clear();
    bool contains(const KeyType& targetKey) const;
    ValueType getValue(const KeyType& targetKey) const;

    ~TreeDictionary() {}
};

#include "TreeDictionary.cpp"
#endif