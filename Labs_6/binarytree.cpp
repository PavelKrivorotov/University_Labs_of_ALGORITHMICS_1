#include "binarytree.h"

#include <iostream>
#include "math.h"

#include <vector>

using namespace std;

struct GraphicValue {
    int _index;
    int _lengthString;
    string _string;
};


BinaryTree::BinaryTree() {
    _root = nullptr;
}


BinaryTree::~BinaryTree() {
    deleteBinaryTree(_root);
}


Node * BinaryTree::getRoot() {
    return _root;
}


Node * BinaryTree::get(int value) {
    if (! _root) { return nullptr; }

    Node *currentNode = _root;
    while (currentNode) {
        int currentValue = currentNode->getValue();

        if (value < currentValue) { currentNode = currentNode->getLeftChild(); }
        else if (value > currentValue) { currentNode = currentNode->getRightChild(); }
        else { return currentNode; }
    }

    return nullptr;
}


void BinaryTree::add(int value) {
    if (get(value)) { return; }

    Node *parent = parentNode(value);
    Node *newNode = new Node(parent, value, 0);

    if (!parent) { _root = newNode; }
    else if (value < parent->getValue()) { parent->setLeftChild(newNode); }
    else { parent->setRightChild(newNode); }

    setBalanceAdd(newNode);

    print();
    showInformation(_root);
}


void BinaryTree::remove(int value) {
    Node *removeNode = get(value);
    if (!removeNode) { return; }

    Node *parentRemoveNode = parentNode(value);

    int state;
    if (!parentRemoveNode) { state = 0; }
    else if (removeNode == parentRemoveNode->getLeftChild()) { state = -1; }
    else { state = 1; }

    Node *replaceNodeLeft, *replaceNodeRight, *replaceNode;
    replaceNodeLeft = maximalNode(removeNode->getLeftChild());
    replaceNodeRight = removeNode->getRightChild();

    if (!replaceNodeLeft) { replaceNode = replaceNodeRight; }
    else { replaceNode = replaceNodeLeft; }

    if (!parentRemoveNode && !replaceNode) {
//        cout << "Delete ONLY Root!" << endl;

        _root = nullptr;
    }

    else if (!replaceNode) {
//        cout << "Delete least" << endl;

        int height = parentRemoveNode->getHeight();

        if (state == -1) {
            parentRemoveNode->setLeftChild(nullptr);
            parentRemoveNode->setHeight(height + 1);
        }

        else {
            parentRemoveNode->setRightChild(nullptr);
            parentRemoveNode->setHeight(height - 1);
        }

        setBalanceRemove(parentRemoveNode);
    }

    else {
//        cout << "Delete NO least!" << endl;

        Node *parentReplaceNode = replaceNode->getParent();

        int newState;
        if (replaceNode == parentReplaceNode->getLeftChild()) { newState = -1; }
        else if (replaceNode == parentReplaceNode->getRightChild()) { newState = 1; }
        else { newState = 0; }


        replaceNode->setParent(parentRemoveNode);
        replaceNode->setHeight(removeNode->getHeight());

        if (parentReplaceNode == removeNode) {
//            cout << "WORK FIRST!" << endl;

            int height = replaceNode->getHeight();

            if (newState == -1) {
                replaceNode->setHeight(height + 1);

                Node *parentRightChild = parentReplaceNode->getRightChild();
                replaceNode->setRightChild(parentRightChild);

                if (parentRightChild) { parentRightChild->setParent(replaceNode); }
            }

            else if (newState == 1) {
                replaceNode->setHeight(height - 1);

                Node *parentLeftChild = parentReplaceNode->getLeftChild();
                replaceNode->setLeftChild(parentLeftChild);

                if (parentLeftChild) { parentLeftChild->setParent(replaceNode); }
            }

            parentReplaceNode = replaceNode;
        }

        else {
//            cout << "WORK STANDARD BLOK!" << endl;

            Node *removeLeftChild = removeNode->getLeftChild();
            Node *removeRightChild = removeNode->getRightChild();

            replaceNode->setLeftChild(removeLeftChild);
            replaceNode->setRightChild(removeRightChild);

            if (removeLeftChild) { removeLeftChild->setParent(replaceNode); }
            if (removeRightChild) { removeRightChild->setParent(replaceNode); }

            int height = parentReplaceNode->getHeight();

            if (newState == -1) {
                parentReplaceNode->setHeight(height + 1);
                parentReplaceNode->setLeftChild(nullptr);
            }

            else if (newState == 1) {
                parentReplaceNode->setHeight(height - 1);
                parentReplaceNode->setRightChild(nullptr);
            }
        }


        if (!state) { _root = replaceNode; }
        else if (state == -1) { parentRemoveNode->setLeftChild(replaceNode); }
        else if (state == 1) { parentRemoveNode->setRightChild(replaceNode); }

        setBalanceRemove(parentReplaceNode);
    }

    delete  removeNode;

    print();
    showInformation(_root);
}


void BinaryTree::setBalanceAdd(Node * newNode) {
    Node *currentNode = newNode;

    while (currentNode) {
        Node *parent = currentNode->getParent();

        if (abs(currentNode->getHeight()) == 2) {
//            cout << "Make rotation by: " << currentNode->getValue() << " node." << endl;

            currentNode = makeRotation(currentNode);
        }

        if (!currentNode->getHeight()) {
            if (currentNode->getLeftChild() || currentNode->getRightChild()) { break; }
        }

        if (parent) {
            int heightParent = parent->getHeight();

            if (currentNode == parent->getLeftChild()) { parent->setHeight(heightParent - 1); }
            else { parent->setHeight(heightParent + 1); }
        }

        currentNode = parent;
    }
}


void BinaryTree::setBalanceRemove(Node *parentReplaceNode) {
    if (!parentReplaceNode) { return; }

    Node *currentNode = parentReplaceNode;

    while (currentNode) {
        Node *parentNode = currentNode->getParent();
        int height = currentNode->getHeight();

        if (abs(height) == 2) { currentNode = makeRotation(currentNode); }

        if (abs(currentNode->getHeight()) == 1) { break; }

        if (parentNode) {
            int parentHeight = parentNode->getHeight();

            if (currentNode == parentNode->getLeftChild()) { parentHeight = parentHeight + 1; }
            else { parentHeight = parentHeight - 1; }

            parentNode->setHeight(parentHeight);
        }

        currentNode = parentNode;
    }
}


Node * BinaryTree::makeRotation(Node *rootNode) {
    if (!rootNode) { return nullptr; }

    Node *aRoot, *bLeft, *bRight;
    Node *cLeft = nullptr, *cRight = nullptr;

    aRoot = rootNode;

    bLeft = aRoot->getLeftChild();
    bRight = aRoot->getRightChild();

    if (bRight) { cLeft = bRight->getLeftChild(); }
    if (bLeft) { cRight = bLeft->getRightChild(); }


    if (cLeft && bRight) {
        if ((aRoot->getHeight() == 2) && (bRight->getHeight() == -1)) {
            if ((cLeft->getHeight() == 0) || (cLeft->getHeight() == -1) || (cLeft->getHeight() == 1)) {
                Node *newRoot = bigLeftRotation(rootNode);
                return newRoot;
            }
        }
    }

    if (cRight && bLeft) {
        if ((aRoot->getHeight() == -2) && (bLeft->getHeight() == 1)) {
            if ((cRight->getHeight() == 0) || (cRight->getHeight() == -1) || (cRight->getHeight() == 1)) {
                Node *newRoot = bigRightRotation(rootNode);
                return newRoot;
            }
        }
    }

    if (bRight) {
        if (aRoot->getHeight() == 2) {
            if ((bRight->getHeight() == 0) || (bRight->getHeight() == 1)) {
                Node *newRoot = leftRotation(rootNode);
                return newRoot;
            }
        }
    }

    if (bLeft) {
        if (aRoot->getHeight() == -2) {
            if ((bLeft->getHeight() == 0) || (bLeft->getHeight() == -1)) {
                Node *newRoot = rightRotation(rootNode);
                return newRoot;
            }
        }
    }

    return nullptr;
}


Node * BinaryTree::leftRotation(Node *currentNode) {
    if (!currentNode) { return nullptr; }

    Node *parent = currentNode->getParent();

    int state;

    if (!parent) { state = 0; }
    else if (currentNode == parent->getLeftChild()) { state = -1; }
    else { state = 1; }

    if (!currentNode->getRightChild()) { return nullptr; }

    Node *newRoot, *newRootLeft;
    newRoot = currentNode->getRightChild();
    newRootLeft = newRoot->getLeftChild();

    currentNode->setRightChild(newRootLeft);
    if (newRootLeft) { newRootLeft->setParent(currentNode); }

    newRoot->setLeftChild(currentNode);
    currentNode->setParent(newRoot);

    newRoot->setParent(parent);


    if (!state) { _root = newRoot; }
    else if (state == -1) { parent->setLeftChild(newRoot); }
    else { parent->setRightChild(newRoot); }

    recursiveBalanceHeight(newRoot, newRoot);

    return newRoot;
}


Node * BinaryTree::rightRotation(Node *currentNode) {
    if (!currentNode) { return nullptr; }

    Node *parent = currentNode->getParent();

    int state;

    if (!parent) { state = 0; }
    else if (currentNode == parent->getLeftChild()) { state = -1; }
    else { state = 1; }

    if (!currentNode->getLeftChild()) { return nullptr; }

    Node *newRoot, *newRootRight;
    newRoot = currentNode->getLeftChild();
    newRootRight = newRoot->getRightChild();

    currentNode->setLeftChild(newRootRight);
    if (newRootRight) { newRootRight->setParent(currentNode); }

    newRoot->setRightChild(currentNode);
    currentNode->setParent(newRoot);

    newRoot->setParent(parent);

    if (!state) { _root = newRoot; }
    else if (state == -1) { parent->setLeftChild(newRoot); }
    else { parent->setRightChild(newRoot); }

    recursiveBalanceHeight(newRoot, newRoot);

    return newRoot;
}


Node * BinaryTree::bigLeftRotation(Node *currentNode) {
    rightRotation(currentNode->getRightChild());
    Node *newRoot = leftRotation(currentNode);

    return newRoot;
}


Node * BinaryTree::bigRightRotation(Node *currentNode) {
    leftRotation(currentNode->getLeftChild());
    Node *newRoot = rightRotation(currentNode);

    return newRoot;
}



void BinaryTree::showInformation(Node *rootNode){
    if (!rootNode) { return; }

    cout << "Value: " << rootNode->getValue();

    if (rootNode->getParent()) { cout << ". Parent: " << rootNode->getParent()->getValue(); }
    else { cout << ". Parent: " << "NULL"; }

    if (rootNode->getLeftChild()) { cout << ". LeftChild: " << rootNode->getLeftChild()->getValue(); }
    else { cout << ". LeftChild: " << "NULL";}

    if (rootNode->getRightChild()) { cout << ". RightChild: " << rootNode->getRightChild()->getValue(); }
    else { cout << ". RightChild: " << "NULL"; }

    cout << endl;

    showInformation(rootNode->getLeftChild());
    showInformation(rootNode->getRightChild());
}



Node * BinaryTree::parentNode(int value) {
    Node *parent = nullptr;
    Node *child = _root;

    while (child) {
        int currentValue = child->getValue();

        if (currentValue == value) { break; }

        parent = child;

        if (value < currentValue) { child = child->getLeftChild(); }
        else { child = child->getRightChild(); }
    }

    return parent;
}


Node * BinaryTree::minimalNode(Node *rootNode) {
    if (!rootNode) { return nullptr; }

    Node *parent = rootNode->getParent();
    Node *child = rootNode;

    while (child) {
        parent = child;
        child = child->getLeftChild();
    }

    return parent;
}


Node * BinaryTree::maximalNode(Node *rootNode) {
    if (!rootNode) { return nullptr; }

    Node *parent = rootNode->getParent();
    Node *child = rootNode;

    while (child) {
        parent = child;
        child = child->getRightChild();
    }

    return parent;
}


int BinaryTree::maximalHeight(Node *rootNode) {
    if (!rootNode) { return -1; }

    int maximalHeightLeft = maximalHeight(rootNode->getLeftChild()) + 1;
    int maximalHeightRight = maximalHeight(rootNode->getRightChild()) + 1;

    if (maximalHeightLeft > maximalHeightRight) { return maximalHeightLeft; }
    else { return maximalHeightRight; }
}


void BinaryTree::recursiveBalanceHeight(Node *currentNode, Node *rootNode) {
    if (!currentNode) { return; }

    int heightLeft = maximalHeight(currentNode->getLeftChild());
    int heightRight = maximalHeight(currentNode->getRightChild());

    currentNode->setHeight(heightRight - heightLeft);

    recursiveBalanceHeight(currentNode->getLeftChild(), rootNode);
    recursiveBalanceHeight(currentNode->getRightChild(), rootNode);
}


void BinaryTree::taskByVariant() {
    vector<Node*> unique1, unique2;
    bool state = false;

    if (!_root) { return; }

    unique1.push_back(_root);

    cout << "\n\n" << endl;

    while (unique1.size() || unique2.size()) {
        if (!state) {
            for (int index = 0; index < unique1.size(); index++) {
                Node *currentNode = unique1.at(index);

                string str = "";
                str.append("Root node: ");
                str.append(to_string(currentNode->getValue()));
                str.append(". Left child: ");

                if (currentNode->getLeftChild()) {
                    unique2.push_back(currentNode->getLeftChild());
                    str.append(to_string(currentNode->getLeftChild()->getValue()));
                }

                else {
                    str.append("NULL");
                }

                str.append(". Right child: ");

                if (currentNode->getRightChild()) {
                    unique2.push_back(currentNode->getRightChild());
                    str.append(to_string(currentNode->getRightChild()->getValue()));
                }

                else {
                    str.append("NULL");
                }

                cout << str << endl;
            }

            unique1.clear();
        }

        else {
            for (int index = 0; index < unique2.size(); index++) {
                Node *currentNode = unique2.at(index);

                string str = "";
                str.append("Root node: ");
                str.append(to_string(currentNode->getValue()));
                str.append(". Left child: ");

                if (currentNode->getLeftChild()) {
                    unique1.push_back(currentNode->getLeftChild());
                    str.append(to_string(currentNode->getLeftChild()->getValue()));
                }

                else {
                    str.append("NULL");
                }

                str.append(". Right child: ");

                if (currentNode->getRightChild()) {
                    unique1.push_back(currentNode->getRightChild());
                    str.append(to_string(currentNode->getRightChild()->getValue()));
                }

                else {
                    str.append("NULL");
                }

                cout << str << endl;
            }

            unique2.clear();
        }

        state = !state;
    }
}


void BinaryTree::print() {
    vector<GraphicValue> listValues;
    recursiveBuildStringList(_root, 0, listValues, 100);

    cout << string(95, ' ') + "New Tree:\n" << endl;

    int maximalIndex = 0;
    for (int index = 0; index < listValues.size(); index++) {
        GraphicValue value = listValues.at(index);

        if (value._index > maximalIndex) { maximalIndex = value._index; }
    }


    int index1 = 0;
    while (index1 < maximalIndex + 1) {
        string outString = string(150, ' ');

        for (int index2 = 0; index2 < listValues.size(); index2++) {
            GraphicValue value = listValues.at(index2);

            if (value._index == index1) { outString.replace(0, value._lengthString, value._string); }
        }

        cout << outString << string(maximalIndex - index1, '\n') << endl;

        index1 += 1;
    }

    cout << "\n\n\n\n\n" << endl;
}


void BinaryTree::recursiveBuildStringList(Node *currentNode, int index, std::vector<GraphicValue> &list, int countEscape) {
    if (!currentNode) { return; }

//    string strValue = to_string(currentNode->getValue());
    string strValue = to_string(currentNode->getValue()) + " (" + to_string(currentNode->getHeight()) + ")";

    int strValLength = strValue.size() / 2;

    GraphicValue val;
    val._index = index;
    val._lengthString = countEscape - strValLength + strValue.size();
    val._string = string(countEscape - strValLength, ' ') + strValue;

    list.push_back(val);


    int deltaEscape = 40 / pow(2, index);

    recursiveBuildStringList(currentNode->getRightChild(), index + 1, list, countEscape + deltaEscape);
    recursiveBuildStringList(currentNode->getLeftChild(), index + 1, list, countEscape - deltaEscape);
}


void BinaryTree::deleteBinaryTree(Node *rootNode) {
    if (! rootNode) { return; }

    deleteBinaryTree(rootNode->getLeftChild());
    deleteBinaryTree(rootNode->getRightChild());

    delete rootNode;
}

