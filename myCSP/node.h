#ifndef NODE_H
#define NODE_H
#include "variable.h"
//Node of the search tree



class Node
{
public:
    Node();
    int NodeID;
    Node* prevNode;
    QList<Node*> children;
    Variable* V;
};

#endif // NODE_H
