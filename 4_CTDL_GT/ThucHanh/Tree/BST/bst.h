#ifndef _BST_H
#define _BST_H

typedef struct Node *pNode;
struct Node
{
    int key;
    pNode left;
    pNode right;
    pNode parent;
};

void printPreOrder(pNode root, int indent);
void delPostOder(pNode &root);
pNode getNode(int k);

// walk O(n)
void InOrder(pNode root);
void PreOrder(pNode root);
void PostOrder(pNode root);

// search O(h) h is height
pNode searchRecursive(pNode root, int k);
pNode searchIterative(pNode root, int k);

// min and max O(h)
pNode minimum(pNode root);
pNode maximum(pNode root);

// successor and predecessor
pNode successor(pNode x);
pNode predecessor(pNode x);

// insertion O(h) and deletion
void insertionIterative(pNode &root, int k);
void deletionSuc(pNode &root, int k); // use successor
void transplant(pNode &root, pNode &u, pNode &v);
void insertionRecursive(pNode &root, pNode parent, int k);
void deletionPre(pNode &root, int k); // use predecessor

#endif
