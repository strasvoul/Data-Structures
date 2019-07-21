#ifndef DATA_STRUCTURES_HASHENTRY_H
#define DATA_STRUCTURES_HASHENTRY_H


class HashEntry {

private:
    int key;
    int value;
public:
    HashEntry(int key, int value);
    int getKey() {return key;}
    int getValue() {return value;}
};


#endif //DATA_STRUCTURES_HASHENTRY_H
