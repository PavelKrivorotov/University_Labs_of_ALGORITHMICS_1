#ifndef NODE_H
#define NODE_H


class Node {

public:
    Node(Node *parent, int value, int height);
    virtual ~Node();

    void setParent(Node *newParent);

    void setLeftChild(Node *newLeftChild);

    void setRightChild(Node *newRightChild);

    void setHeight(int newHeight);

    Node * getParent();

    Node * getLeftChild();

    Node * getRightChild();

    int getValue();

    int getHeight();

private:
    int _value;
    int _height;

    Node *_parent;
    Node *_leftChild;
    Node *_rightChild;
};

#endif // NODE_H
