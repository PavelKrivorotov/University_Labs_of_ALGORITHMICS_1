#include <iostream>
using namespace std;

#include "binarytree.h"

int main() {
    BinaryTree *binaryTree = new BinaryTree();

//    binaryTree->add(9);
//    binaryTree->add(-2);
//    binaryTree->add(19);
//    binaryTree->add(11);


    string ans;
    int value;

    while (true) {
        cout << "\nInput operation: add/remove: ";
        cin >> ans;

        if (ans == "add") {
            cout << "Input value from add: ";
            cin >> value;
            cout << endl;

            binaryTree->add(value);
        }

        else if (ans == "remove") {
            cout << "Input value to remove: " ;
            cin >> value;
            cout << endl;

            binaryTree->remove(value);
        }

        else { break; }
    }

    binaryTree->taskByVariant();


    delete binaryTree;

    return 0;
}
