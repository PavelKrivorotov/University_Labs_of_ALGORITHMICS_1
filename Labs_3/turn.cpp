#include "turn.h"

using namespace std;

Turn::Turn() {
    _firstItem = nullptr;
    _lastItem = nullptr;
    _size = 0;
}


Turn::~Turn() {
    TurnItem *currentItem = _firstItem;
    while (currentItem) {
        TurnItem *delItem = currentItem;
        currentItem = currentItem->getNextItem();

        delete delItem;
    }
}


void Turn::append(Task *task) {
    if (!_firstItem) {
        TurnItem *currentItem = new TurnItem(task);

        _firstItem = currentItem;
        _lastItem = currentItem;
        _size = 1;

        return;
    }

    TurnItem *currentItem = new TurnItem(task);

    _lastItem->setNextItem(currentItem);
    _lastItem = currentItem;
    _size += 1;
}


void Turn::show() {
    cout << "\t+---------------------------------------------------------------------------------------+" << endl;
    cout << "\t|\tid\t|\tpriority\t|\tcurrent time\t|\tcomplete time\t|" << endl;
    cout << "\t+---------------------------------------------------------------------------------------+" << endl;

    TurnItem *currentItem = _firstItem;
    while (currentItem) {
        cout << "\t|\t " << currentItem->getTask()->getId() << "\t|\t  " << currentItem->getTask()->getPriority()
             << "\t\t|\t" << currentItem->getTask()->getCurrentTime() << "\t\t|\t" <<
             currentItem->getTask()->getCompleteTime() << "\t\t|"<< endl;
        cout << "\t+---------------------------------------------------------------------------------------+" << endl;
        currentItem = currentItem->getNextItem();
    }
}


Task * Turn::get() {
    if (!_firstItem) { return nullptr; }
    if (_firstItem == _lastItem) { _lastItem = nullptr; }

    Task *currentTask = _firstItem->getTask();
    TurnItem *nextItem = _firstItem->getNextItem();

    _firstItem = nextItem;
    _size -= 1;
    return currentTask;
}


int Turn::size() {
    return _size;
}


bool Turn::isEmpty() {
    if (!_firstItem) { return true; }
    return false;
}

