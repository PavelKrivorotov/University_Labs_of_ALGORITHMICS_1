#include "dynamicarray.h"

#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size) {
    _array = new int[size];

    _size = size;
    _countComparisons = 0;
    _countComparisons = 0;
}


DynamicArray::~DynamicArray() {
    delete [] _array;
}


void DynamicArray::insert(int index, int value) {
    if ((index < 0) || (index > _size - 1)) { return; }

    int *_newArray = new int[_size + 1];

    int indOld = 0;
    int indNew = 0;

    while (indNew < _size + 1) {
        if (indNew == index) { _newArray[indNew] = value; indOld -= 1; }
        else { _newArray[indNew] = _array[indOld]; }

        indOld++;
        indNew++;
    }

    delete [] _array;

    _array = _newArray;
    _size += 1;
}


void DynamicArray::remove(int index) {
    if ((index < 0) || (index > _size - 1)) { return; }

    int *_newArray = new int[_size - 1];

    int indOld = 0;
    int indNew = 0;

    while (indOld < _size) {
        if (indOld == index) { indNew -= 1; }
        else { _newArray[indNew] = _array[indOld]; }

        indOld++;
        indNew++;
    }

    delete [] _array;

    _array = _newArray;
    _size -= 1;
}


void DynamicArray::sort() {
    _countComparisons = 0;
    _countPermutations = 0;

    int index = _size;
    while (index > 1) {
        int indexMaxElement = max(0, index);

        // Another variant:
//        if (indexMaxElement == index - 1) { _countComparisons += 1; index -= 1; continue; }

        int tmpLastElement = _array[index - 1];
        int maxElement = _array[indexMaxElement];

        _array[indexMaxElement] = tmpLastElement;
        _array[index - 1] = maxElement;

        _countPermutations += 1;
        index -= 1;
    }
}


void DynamicArray::print() {
    cout << "\t";

    for (int index = 0; index < _size - 1; index++) {
        cout << _array[index] << ", ";
    }

    cout << _array[_size - 1] << endl;
}


void DynamicArray::fill1() {
    _array[0] = -14;
    _array[1] = -9;
    _array[2] = -1;
    _array[3] = 0;
    _array[4] = 4;
    _array[5] = 9;
    _array[6] = 18;
    _array[7] = 98;
}


void DynamicArray::fill2() {
    _array[7] = -14;
    _array[6] = -9;
    _array[5] = -1;
    _array[4] = 0;
    _array[3] = 4;
    _array[2] = 9;
    _array[1] = 18;
    _array[0] = 98;
}


void DynamicArray::fill3() {
    _array[0] = 0;
    _array[1] = -9;
    _array[2] = -1;
    _array[3] = 98;
    _array[4] = 18;
    _array[5] = -14;
    _array[6] = 4;
    _array[7] = 9;
}


void DynamicArray::fillRandom() {
    for (int index = 0; index < _size; index++) {
        _array[index] = rand();
    }
}


int DynamicArray::size() {
    return _size;
}


int DynamicArray::value(int index) {
    if ((index < 0) || (index > _size - 1)) { return -1; }

    return _array[index];
}


int DynamicArray::getCountComparisons() {
    return _countComparisons;
}


int DynamicArray::getCountPermutations() {
    return _countPermutations;
}


int DynamicArray::max(int startIndex, int stopIndex) {
    int indexMaxElement = startIndex;
    for (int index = startIndex; index < stopIndex; index++) {
        if (_array[index] > _array[indexMaxElement]) { indexMaxElement = index; }

        _countComparisons += 1;
    }

    return indexMaxElement;
}

