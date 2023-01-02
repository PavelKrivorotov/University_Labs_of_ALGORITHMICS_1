#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

#include <vector>

struct GraphicValue;


class BinaryTree {

public:
    BinaryTree();
    virtual ~BinaryTree();

    Node * getRoot();

    Node * get(int value);

    void add(int value);

    void remove(int value);

    void taskByVariant();

    void print();

private:
    int maximalHeight(Node *rootNode);

    void recursiveBalanceHeight(Node *currentNode, Node *rootNode);

    void setBalanceAdd(Node *newNode);

    void setBalanceRemove(Node * parentReplaceNode);

    Node * makeRotation(Node *rootNode);

    Node * leftRotation(Node *currentNode);

    Node * rightRotation(Node *currentNode);

    Node * bigLeftRotation(Node *currentNode);

    Node * bigRightRotation(Node *currentNode);

    Node * parentNode(int value);

    Node * minimalNode(Node *rootNode);

    Node * maximalNode(Node *rootNode);

    void recursiveBuildStringList(Node *currentNode, int index, std::vector<GraphicValue> &list, int countEscape);

    void showInformation(Node *rootNode);

    void deleteBinaryTree(Node *rootNode);

private:
    Node *_root;
};

#endif // BINARYTREE_H
