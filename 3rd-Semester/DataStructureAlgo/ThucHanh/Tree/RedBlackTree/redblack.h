#ifndef _RED_BLACK_H
#define _RED_BLACK_H

enum Colors
{
    Black,
    Red
};

typedef struct Node *pNode;
struct Node
{
    int key;
    pNode left;
    pNode right;
    pNode parent;
    Colors color;
};

struct Tree
{
    pNode root;
    pNode NIL;
    Tree();
};

pNode getNode(int k, Colors color, pNode NIL);
void printPreOrder(pNode root, pNode NIL, int indent);
void delPostOrder(pNode &root, pNode NIL);
pNode search(Tree T, int k);

// rotate
void leftRotate(Tree &T, pNode x);
void rightRotate(Tree &T, pNode x);

// insert
void rbInsert(Tree &T, int k);
void rbInsertFixUp(Tree &T, pNode z);

// min and max
pNode minimum(pNode root, pNode NIL);
pNode maximum(pNode root, pNode NIL);

// delete
void rbTransplant(Tree &T, pNode u, pNode v);
void rbDelete(Tree &T, int k);
void rbDeleteFixUp(Tree &T, pNode x);

#endif
