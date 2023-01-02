#include "turnitem.h"

TurnItem::TurnItem(Task *task) {
    _task = task;
    _nextItem = nullptr;
}


TurnItem::~TurnItem() {
    delete _task;
}


TurnItem * TurnItem::getNextItem() {
    return _nextItem;
}


Task * TurnItem::getTask() {
    return _task;
}


void TurnItem::setNextItem(TurnItem *nextItem) {
    _nextItem = nextItem;
}

