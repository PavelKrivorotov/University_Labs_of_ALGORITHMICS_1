#include "hashtable.h"
#include "cmath"

using namespace std;

HashTable::HashTable(int size) {
    _size = size;
    _arrayOfItems = new Item[size];

    for (int index = 0; index < size; index++) {
        Item currentItem = Item();
        _arrayOfItems[index] = currentItem;;
    }
}


HashTable::~HashTable() {
    delete [] _arrayOfItems;
}


std::string HashTable::add(std::string key, std::string value) {
    int index;

    int countRepeat = 0;
    while (countRepeat < _size) {
        index = (hash1(key) + countRepeat * hash2(key)) % _size;

        Item &currentItem = _arrayOfItems[index];

        if (currentItem._isNull) { break; }

        if ((currentItem._key == key) && (currentItem._isDelete)) {
            currentItem._value = value;
            currentItem._isDelete = false;
            return "Add new Item! Key: " + key + ", value: " + value;
        }

        if (currentItem._key == key) { return "This key (" + key + ") already exists!"; }

        countRepeat++;
    }

    if (countRepeat == _size) { return "This hash table is full! Need size up this table."; }

    Item &currentItem = _arrayOfItems[index];
    currentItem._key = key;
    currentItem._value = value;
    currentItem._isDelete = false;
    currentItem._isNull = false;

    return "Add new Item! Key: " + key + ", value: " + value;
}


std::string HashTable::remove(std::string key) {
    int index;

    int countRepeat = 0;
    while (countRepeat < _size) {
        index = (hash1(key) + countRepeat * hash2(key)) % _size;

        Item &currentItem = _arrayOfItems[index];

        if (currentItem._isNull) {
             return "Key error: This key (" + key + ") doese not exists!";
        }

        if ((currentItem._key == key) && (currentItem._isDelete)) {
            return "Key error: This key (" + key + ") doese not exists!";
        }

        if (currentItem._key == key) { break; }

        countRepeat++;
    }

    Item &currentItem = _arrayOfItems[index];
    currentItem._isDelete = true;

    return "Remove key: " + key + ", value: " + currentItem._value;
}


std::string HashTable::get(std::string key) {
    int index;

    int countRepeat = 0;
    while (countRepeat < _size) {
        index = (hash1(key) + countRepeat * hash2(key)) % _size;

        Item &currentItem = _arrayOfItems[index];

        if (currentItem._isNull) {
             return "Key error: This key (" + key + ") doese not exists!";
        }

        if ((currentItem._key == key) && (currentItem._isDelete)) {
            return "Key error: This key (" + key + ") doese not exists!";
        }

        if (currentItem._key == key) { break; }

        countRepeat++;
    }

    return "Key: " + key + ", value: " + _arrayOfItems[index]._value;
}


void HashTable::print() {
    for (int index = 0; index < _size; index++) {
        Item currentItem = _arrayOfItems[index];

        if (!currentItem._isNull) {
            cout << "Index: " << index << ". Key: " << currentItem._key << ". Value: "
                 << currentItem._value << ". isDelete = " << currentItem._isDelete
                 << ". isNull: " << currentItem._isNull << endl;
        }
    }
}


int HashTable::hash1(std::string key) {
    int hashSum = 0;
    for (int index = 0; index < SIZE_KEY; index++) {
        hashSum += pow((int)key.at(index), 2);
    }

    return (hashSum - HASH1_CONSTANT) % _size;
}


int HashTable::hash2(std::string key) {
    int hashSum = 0;
    for (int index = 0; index < SIZE_KEY; index++) {
        hashSum += pow((int)key.at(index), 3);
    }

    return (hashSum - HASH2_CONSTANT) % _size;
}


bool HashTable::checkValidKey(std::string key) {
    if (key.length() != SIZE_KEY) { return false; }

    for (int index = 0; index < SIZE_KEY; index++) {
        if ((index == 0) || (index == 5)) {
            if (!(( (int)key.at(index) > 47 ) && ( (int)key.at(index) < 58 ))) { return false; }
        }

        else {
            if (!(( (int)key.at(index) > 64 ) && ( (int)key.at(index) < 91 ))) { return false; }
        }
    }

    return true;
}

