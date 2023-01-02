#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#define SIZE_KEY 6
#define HASH1_CONSTANT 16900
#define HASH2_CONSTANT 1098500

struct Item {
    std::string _key = "";
    std::string _value = "";
    bool _isDelete = false;
    bool _isNull = true;
};


class HashTable {

public:
    HashTable(int size = 2500);
    virtual ~HashTable();

    std::string add(std::string key, std::string value);

    std::string remove(std::string key);

    std::string get(std::string key);

    void print();

    int hash1(std::string key);

    int hash2(std::string key);

    bool checkValidKey(std::string key);

private:


private:
    int _size;
    Item *_arrayOfItems;
};

#endif // HASHTABLE_H
