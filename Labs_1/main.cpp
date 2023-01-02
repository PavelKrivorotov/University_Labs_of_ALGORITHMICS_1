
#include <iostream>
#include <random>

using namespace std;


void fillArray(int *array, int length) {
    const int minElement = -(length / 2 - 1);
    const int maxElement = (length / 2);

    default_random_engine generator;
    uniform_int_distribution<int> distribution(minElement, maxElement);

    for (int ind = 0; ind < length; ind++) {
        array[ind] = distribution(generator);
    }
}


void showArray(int *array, int length) {
    for (int ind = 0; ind < length; ind++) {
        cout << array[ind] << ", ";
    }
}


void reduceMultipleElements(int *array, int length) {
    for (int ind = 0; ind < length; ind++) {
        if (!(array[ind] % 10)) {
            array[ind] = array[ind] / 10;
        }
    }
}


int countEvenElements(int countElements){
    return countElements;
}


int main()
{
    int length;
    string ans;


    cout << "Please Enter a size of array: ";
    cin >> length;

    int *array = new int[length];
    fillArray(array, length);

    showArray(array, length);


    cout << "\n\nReduce multiple elements?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        reduceMultipleElements(array, length);
        showArray(array, length);
    }


    cout << "\n\nShow count even elements?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        int countElements = 0;
        for (int ind = 0; ind < length; ind++) {
            if (!(array[ind] % 2)) {
                countElements++;
            }
        }

        cout << "Count is " << countEvenElements(countElements) << endl;
    }


    cout << "\nPress Enter to quit programm...";


    delete [] array;
    return 0;
}

