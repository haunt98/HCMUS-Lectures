#ifndef _avl_h
#define _avl_h

typedef struct Node *pNode;
struct Node
{
    int key;
    pNode left;
    pNode right;
    pNode parent;
    int height;
};

pNode getNode(int k);
void printPreOrder(pNode root, int indent);
void delPostOrder(pNode &root);
pNode search(pNode root, int k);

// height check
int height(pNode p);
void update_height(pNode p);

// min and max
pNode minimum(pNode root);
pNode maximum(pNode root);
int max(int a, int b);

// rotate
void leftRotate(pNode &root, pNode x);
void rightRotate(pNode &root, pNode x);

// insert and delete
void avlInsert(pNode &root, int k);
void avlRebalance(pNode &root, pNode x);
void avlDelete(pNode &root, int k);
void transplant(pNode &root, pNode u, pNode v);

#endif