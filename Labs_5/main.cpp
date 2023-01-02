#include <iostream>
using namespace std;

#include "dynamicarray.h"

int main() {
    DynamicArray *dynamicArray = new DynamicArray();

    cout << "Fill array (length = 8), using method fill1(): \n" << endl;

    dynamicArray->fill1();
    dynamicArray->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray->sort();
    dynamicArray->print();

    cout << "\nThe countComparisons = " << dynamicArray->getCountComparisons()
         << ", countPermutations = " << dynamicArray->getCountPermutations() << endl;

    cout << "\n\n\nFill array (length = 8), using method fill2(): \n" << endl;

    dynamicArray->fill2();
    dynamicArray->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray->sort();
    dynamicArray->print();

    cout << "\nThe countComparisons = " << dynamicArray->getCountComparisons()
         << ", countPermutations = " << dynamicArray->getCountPermutations() << endl;

    cout << "\n\n\nFill array (length = 8), using method fill3(): \n" << endl;

    dynamicArray->fill3();
    dynamicArray->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray->sort();
    dynamicArray->print();

    cout << "\nThe countComparisons = " << dynamicArray->getCountComparisons()
         << ", countPermutations = " << dynamicArray->getCountPermutations() << endl;

    cout << "\n\n\nFill array, using method fillRandom():\nInptu length: ";

    int length;
    cin >> length;

    cout << endl;

    DynamicArray *dynamicArray2 = new DynamicArray(length);

    dynamicArray2->fillRandom();
    dynamicArray2->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray2->sort();
    dynamicArray2->print();

    cout << "\nThe countComparisons = " << dynamicArray2->getCountComparisons()
         << ", countPermutations = " << dynamicArray2->getCountPermutations() << endl;

    int index, value;

    cout << "\n\n\nInsert value into array index:" << endl;

    cout << "index = ";
    cin >> index;

    cout << "value = ";
    cin >> value;

    cout << "\n\nNew array: \n" << endl;

    dynamicArray2->insert(index, value);
    dynamicArray2->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray2->sort();
    dynamicArray2->print();

    cout << "\nThe countComparisons = " << dynamicArray2->getCountComparisons()
         << ", countPermutations = " << dynamicArray2->getCountPermutations() << endl;

    cout << "\n\n\nRemove value from array index:" << endl;

    cout << "index = ";
    cin >> index;

    cout << "\n\nNew array: \n" << endl;

    dynamicArray2->remove(index);
    dynamicArray2->print();

    cout << "\n\nSort array: \n" << endl;

    dynamicArray2->sort();
    dynamicArray2->print();

    cout << "\nThe countComparisons = " << dynamicArray2->getCountComparisons()
         << ", countPermutations = " << dynamicArray2->getCountPermutations() << endl;

    cout << "\n\n\nGet value at index:" << endl;

    cout << "index = ";
    cin >> index;

    cout << "The value in index = " << index << ". Is " << dynamicArray2->value(index) << endl;


    delete dynamicArray;
    delete dynamicArray2;

    return 0;
}

