#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H

#include "HashEntry.h"

using namespace std;

const int TABLE_SIZE = 1000;

class HashTable {

private:
    HashEntry **table;
    int sizeOfHashTable;
   // void enlarge(HashEntry **& array, int size);

public:
    HashTable();
    int searchElement(int key);
    void insertElement(int key, int value);
    int getSizeOhHashTable(){ return sizeOfHashTable;}

};


#endif //DATA_STRUCTURES_HASHTABLE_H
