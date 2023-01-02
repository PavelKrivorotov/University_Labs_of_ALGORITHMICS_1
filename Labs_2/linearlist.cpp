#include "linearlist.h"

#include <iostream>
using namespace std;

LinearList::LinearList() {
    _length = 0;
    _firstItem = nullptr;
    _lastItem = nullptr;
}


LinearList::~LinearList() {
    Item *currentItem = _firstItem;
    Item *delItem;

    while (currentItem != nullptr) {
        delItem = currentItem;
        currentItem = currentItem->getNextItem();
        delete delItem;
    }
}


void LinearList::append(int value) {
    Item *item = new Item(value);

    if (!_length) {
        _firstItem = item;
        _lastItem = item;
        _length = 1;
        return;
    }

    _lastItem->setNextItem(item);
    _lastItem = item;
    _length += 1;
}


void LinearList::pop() {
    if (!_length) { return; }
    if (_length == 1) {
        _firstItem = nullptr;
        delete _lastItem;
        _lastItem = nullptr;
        _length = 0;
        return;
    }

    Item *currentItem = _firstItem;
    while (currentItem->getNextItem() != _lastItem) {
        currentItem = currentItem->getNextItem();
    }

    delete _lastItem;

    _lastItem = currentItem;
    _lastItem->setNextItem(nullptr);
    _length -= 1;
}


void LinearList::show() {
    if (!_length) { return; }

    Item *startItem = _firstItem;
    while (startItem->getNextItem() != nullptr) {
        cout << startItem->getValue() << " -> ";
        startItem = startItem->getNextItem();
    }

    cout << startItem->getValue() << endl;
}


void LinearList::sort() {
    if (!_length) { return; }

    Item *currentItem = _firstItem;
    while (currentItem != _lastItem) {
        Item *nextItem = currentItem->getNextItem();

        while (nextItem != nullptr) {
            if (nextItem->getValue() < currentItem->getValue()) {
                int tmp = currentItem->getValue();
                currentItem->setValue(nextItem->getValue());
                nextItem->setValue(tmp);
            }

            nextItem = nextItem->getNextItem();
        }

        currentItem = currentItem->getNextItem();
    }
}


int LinearList::value(int index) {
    if ((index < 0) || (index > _length - 1)) { return -1; }

    int ind = 0;
    Item *currentItem = _firstItem;

    while (ind < index) {
        currentItem = currentItem->getNextItem();
        ind++;
    }

    return currentItem->getValue();
}


int LinearList::size() {
    return _length;
}


int LinearList::count(int value) {
    int count = 0;

    Item *currentItem = _firstItem;
    while (currentItem != nullptr) {
        if (currentItem->getValue() == value) { count++; }
        currentItem = currentItem->getNextItem();
    }

    return count;
}


bool LinearList::contains(int value) {
    Item *currentItem = _firstItem;
    while (currentItem != nullptr) {
        if (currentItem->getValue() == value) { return true; }
        currentItem = currentItem->getNextItem();
    }

    return false;
}

