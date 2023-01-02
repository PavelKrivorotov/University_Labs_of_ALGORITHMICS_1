#ifndef TURN_H
#define TURN_H

#include "turnitem.h"


class Turn {

public:
    Turn();
    virtual ~Turn();

    void append(Task *task);

    void show();

    Task * get();

    int size();

    bool isEmpty();

private:
    TurnItem *_firstItem;
    TurnItem *_lastItem;
    int _size;
};

#endif // TURN_H
