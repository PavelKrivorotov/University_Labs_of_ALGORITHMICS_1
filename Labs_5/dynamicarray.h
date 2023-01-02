#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray {

public:
    DynamicArray(int size = 8);
    virtual ~ DynamicArray();

    void insert(int index, int value);

    void remove(int index);

    void sort();

    void print();

    void fill1();

    void fill2();

    void fill3();

    void fillRandom();

    int size();

    int value(int index);

    int getCountComparisons();

    int getCountPermutations();

private:
    int max(int startIndex, int stopIndex);

private:
    int *_array;
    int _size;

    int _countComparisons;
    int _countPermutations;
};

#endif // DYNAMICARRAY_H
