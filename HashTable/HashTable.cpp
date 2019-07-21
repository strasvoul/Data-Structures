#include "HashTable.h"


HashTable::HashTable() {
    table = new HashEntry *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
    sizeOfHashTable = 0;
}

int HashTable::searchElement(int key) {
    int hash = (key % TABLE_SIZE);
    while (table[hash] != nullptr && table[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] == nullptr)
        return -1;
    else
        return table[hash]->getValue();
}

void HashTable::insertElement(int key, int value) {
    if (key < 0) {
        return;
    }
    int hash = (key % TABLE_SIZE);
    while (table[hash] != nullptr && table[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] != nullptr) // It means that we want to insert new value of a key that is already exist in our hashTable
        delete table[hash];
//    if (sizeOfHashTable == TABLE_SIZE-1) {
//        cout<< "I am in"<< endl;
//        enlarge(table, TABLE_SIZE);
//    }
    table[hash] = new HashEntry(key, value);
    sizeOfHashTable++;
}

//void HashTable::enlarge(HashEntry **& array, int size) {
//    HashEntry **dbl = new HashEntry*[size*2];
//    for (int i = 0; i < size; i++) {
//        dbl[i] = array[i];
//    }
//    delete[] array;
//    array = dbl;
//}