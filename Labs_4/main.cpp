
#include <iostream>
using namespace std;

#include "hashtable.h"

int main() {
    HashTable *hashTable = new HashTable(2500);


    cout << "\t\t\t\t\t\tDuplicate Key:" << endl;
    cout << "hash1('4XNSL4') = " << hashTable->hash1("4XNSL4") << endl;
    cout << "hash1('3ELKI5') = " << hashTable->hash1("3ELKI5") << endl;

    cout << endl;

    cout << "hash2('3ELKI5') = " << hashTable->hash2("3ELKI5") << endl;

    cout << endl;
    cout << "\n\t\t\t\t\t\tPrint hashTable:" << endl;
    hashTable->print();

    cout << "\n\n\t\t\t\t\t\tAdd duplicate keys items:" << endl;
    cout << hashTable->add("4XNSL4", "First") << endl;
    cout << hashTable->add("3ELKI5", "Second") << endl;

    cout << endl;
    cout << "\n\t\t\t\t\t\tPrint hashTable:\n" << endl;
    hashTable->print();

    cout << "\n" << endl;
    cout << "\n\t\t\t\t\t\tRemove key: 4XNSL4:\n" << endl;
    cout << hashTable->remove("4XNSL4") << endl;

    cout << endl;
    cout << "\n\t\t\t\t\t\tPrint hashTable:\n" << endl;
    hashTable->print();

    cout << "\n" << endl;
    cout << "\n\t\t\t\t\t\tGet removed key: 4XNSL4:\n" << endl;
    cout << hashTable->get("4XNSL4") << endl;

    cout << "\n" << endl;
    cout << "\n\t\t\t\t\t\tGet exists key: 3ELKI5:\n" << endl;
    cout << hashTable->get("3ELKI5") << endl;

    cout << "\n\n" << endl;


    string ans = "";

    cout << "Add new Item?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        string key, value;
        key = "";
        value = "";

        while (!hashTable->checkValidKey(key)) {
            cout << "\nInput key: ";
            cin >> key;
        }

        cout << "Input value: ";
        cin >> value;

        cout << "\n" << hashTable->add(key, value) << endl;

        cout << endl;
        cout << "\n\t\t\t\t\t\tPrint hashTable:\n" << endl;
        hashTable->print();
    }


    cout << "\n\nGet Item?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        string key;
        key = "";

        while (!hashTable->checkValidKey(key)) {
            cout << "\nInput key: ";
            cin >> key;
        }

        cout << "\n" << hashTable->get(key) << endl;

        cout << endl;
        cout << "\n\t\t\t\t\t\tPrint hashTable:\n" << endl;
        hashTable->print();
    }


    cout << "\n\nRemove Item?\ny/n: ";
    cin >> ans;

    if (ans == "y") {
        string key;
        key = "";

        while (!hashTable->checkValidKey(key)) {
            cout << "\nInput key: ";
            cin >> key;
        }

        cout << "\n" << hashTable->remove(key) << endl;

        cout << endl;
        cout << "\n\t\t\t\t\t\tPrint hashTable:\n" << endl;
        hashTable->print();
    }


    delete hashTable;

    return 0;
}
