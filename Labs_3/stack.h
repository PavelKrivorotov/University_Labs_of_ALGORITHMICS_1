#ifndef STACK_H
#define STACK_H

#include "stackitem.h"


class Stack {

public:
    Stack();
    virtual ~Stack();

    void append(Task *task);

    void show();

    Task * pop();

    int size();

    bool isEmpty();

private:
    StackItem *_firstItem;
    StackItem *_lastItem;
    int _size;
};

#endif // STACK_H
