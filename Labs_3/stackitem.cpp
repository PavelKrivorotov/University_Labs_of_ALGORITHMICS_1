#include "stackitem.h"

StackItem::StackItem(Task *task) {
    _task = task;
    _previousItem = nullptr;
}


StackItem::~StackItem() {
    delete _task;
}


StackItem * StackItem::getPreviousItem() {
    return _previousItem;
}


Task * StackItem::getTask() {
    return _task;
}


void StackItem::setPreviousItem(StackItem *previousItem) {
    _previousItem = previousItem;
}

