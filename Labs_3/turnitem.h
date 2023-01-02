#ifndef TURNITEM_H
#define TURNITEM_H

#include "task.h"


class TurnItem {

public:
    explicit TurnItem(Task *task);
    virtual ~TurnItem();

    TurnItem * getNextItem();

    Task * getTask();

    void setNextItem(TurnItem *nextItem);

private:
    Task *_task;
    TurnItem *_nextItem;
};

#endif // TURNITEM_H
