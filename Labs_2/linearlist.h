#ifndef LINEARLIST_H
#define LINEARLIST_H

#include "item.h"

class LinearList {

public:
    LinearList();
    virtual ~LinearList();

    void append(int value);

    void pop();

    void show();

    void sort();

    int value(int index);

    int size();

    int count(int value);

    bool contains(int value);

private:
    int _length;
    Item *_firstItem;
    Item *_lastItem;
};

#endif // LINEARLIST_H
