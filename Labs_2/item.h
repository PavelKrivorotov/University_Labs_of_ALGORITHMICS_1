#ifndef ITEM_H
#define ITEM_H

class Item {

public:
    Item(int value);
    virtual ~Item();

    Item * getNextItem();

    int getValue();

    void setNextItem(Item *nextItem);

    void setValue(int value);

private:
    int _value;
    Item *_nextItem;
};

#endif // ITEM_H
