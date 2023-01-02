#include "item.h"

Item::Item(int value) {
    _value = value;
    _nextItem = nullptr;
}


Item::~Item() {

}


Item * Item::getNextItem() {
    return _nextItem;
}


int Item::getValue() {
    return _value;
}


void Item::setNextItem(Item *nextItem) {
    _nextItem = nextItem;
}


void Item::setValue(int value) {
    _value = value;
}
