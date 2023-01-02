#include "stack.h"

using namespace std;

Stack::Stack() {
    _firstItem = nullptr;
    _lastItem = nullptr;
    _size = 0;
}


Stack::~Stack() {
    StackItem *currentItem = _lastItem;
    while(_lastItem) {
        StackItem *delItem = currentItem;
        currentItem = currentItem->getPreviousItem();

        delete delItem;
    }
}


void Stack::append(Task *task) {
    if (!_firstItem) {
        StackItem *currentItem = new StackItem(task);

        _firstItem = currentItem;
        _lastItem = currentItem;
        _size = 1;

        return;
    }

    StackItem *currentItem = new StackItem(task);

    currentItem->setPreviousItem(_lastItem);
    _lastItem = currentItem;
    _size += 1;
}


void Stack::show() {
    cout << "\t+---------------------------------------------------------------------------------------+" << endl;
    cout << "\t|\tid\t|\tpriority\t|\tcurrent time\t|\tcomplete time\t|" << endl;
    cout << "\t+---------------------------------------------------------------------------------------+" << endl;

    StackItem *currentItem = _lastItem;
    while (currentItem) {
        cout << "\t|\t " << currentItem->getTask()->getId() << "\t|\t  " << currentItem->getTask()->getPriority()
             << "\t\t|\t" << currentItem->getTask()->getCurrentTime() << "\t\t|\t" <<
             currentItem->getTask()->getCompleteTime() << "\t\t|"<< endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
        currentItem = currentItem->getPreviousItem();
    }
}


Task * Stack::pop() {
    if (!_firstItem) { return nullptr; }
    if (_firstItem == _lastItem) { _firstItem = nullptr; }

    Task *task = _lastItem->getTask();
    StackItem *previousItem = _lastItem->getPreviousItem();

    _lastItem = previousItem;
    _size -= 1;
    return task;
}


int Stack::size() {
    return _size;
}


bool Stack::isEmpty() {
    if (!_lastItem) { return true; }
    return false;
}

