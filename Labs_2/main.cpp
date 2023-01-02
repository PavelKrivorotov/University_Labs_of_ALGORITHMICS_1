#include "linearlist.h"
#include "item.h"

#include <iostream>
using namespace std;


LinearList * generateInputSec() {
    LinearList *inputSec = new LinearList();

    inputSec->append(12);
    inputSec->append(9);
    inputSec->append(-190);
    inputSec->append(9);
    inputSec->append(0);
    inputSec->append(-12);
    inputSec->append(-12);
    inputSec->append(-12);
    inputSec->append(0);
    inputSec->append(1789);
    inputSec->append(-999);
    inputSec->append(7);
    inputSec->append(-190);
    inputSec->append(-12);
    inputSec->append(0);
    inputSec->append(-12);

    return inputSec;
}


LinearList * createNewSec(LinearList *inputSec) {
    LinearList *uniqueSec = new LinearList();
    LinearList *outSec = new LinearList();

    for (int index = 0; index < inputSec->size(); index++) {
        int value = inputSec->value(index);

        if (!uniqueSec->contains(value)) { uniqueSec->append(value); }
    }

    for (int index = 0; index < uniqueSec->size(); index++) {
        int value = uniqueSec->value(index);
        int count = inputSec->count(value);

        if (count > 1) { outSec->append(count); }
    }

    outSec->sort();

    delete uniqueSec;
    return outSec;
}


int main() {
    LinearList *inputSec = generateInputSec();
    LinearList *outSec = createNewSec(inputSec);

    cout << "Input Sec:\n\t";
    inputSec->show();

    cout << "\nSec sorted:\n\t";
    inputSec->sort();
    inputSec->show();

    cout << "\n\nNew Sec:\n\t";
    outSec->show();

    string ans = "";
    cout << "\n\nDelete last Item in Input Sec?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        inputSec->pop();
        cout << "\nInput Sec:\n\t";
        inputSec->show();
    }

    cout << "\n\nAppend last Item in Input Sec?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        int value;

        cout << "\nEnter a value: ";
        cin >> value;
        inputSec->append(value);

        cout << "\nInput Sec:\n\t";
        inputSec->show();
    }

    cout << "\nPress Enter to exit...";

    delete inputSec;
    delete outSec;
    return 0;
}

