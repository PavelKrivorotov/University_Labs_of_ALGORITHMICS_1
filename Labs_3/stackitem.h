#ifndef STACKITEM_H
#define STACKITEM_H

#include "task.h"


class StackItem {

public:
    explicit StackItem(Task *task);
    virtual ~StackItem();

    StackItem * getPreviousItem();

    Task * getTask();

    void setPreviousItem(StackItem *nextItem);

private:
    Task *_task;
    StackItem *_previousItem;
};

#endif // STACKITEM_H
