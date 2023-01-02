#include "node.h"

Node::Node(Node *parent, int value, int height) {
    _parent = parent;
    _value = value;
    _height = height;

    _leftChild = nullptr;
    _rightChild = nullptr;
}


Node::~Node() {

}


void Node::setParent(Node *newParent) {
    _parent = newParent;
}


void Node::setLeftChild(Node *newLeftChild) {
    _leftChild = newLeftChild;
}


void Node::setRightChild(Node *newRightChild) {
    _rightChild = newRightChild;
}


void Node::setHeight(int newHeight) {
    _height = newHeight;
}


Node * Node::getParent() {
    return _parent;
}


Node * Node::getLeftChild() {
    return _leftChild;
}


Node * Node::getRightChild() {
    return _rightChild;
}


int Node::getValue() {
    return _value;
}


int Node::getHeight() {
    return _height;
}

