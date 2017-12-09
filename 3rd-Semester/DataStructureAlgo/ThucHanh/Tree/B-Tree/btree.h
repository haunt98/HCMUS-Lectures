#ifndef _BTREE_H
#define _BTREE_H

extern const int T_MIN_DEGREE;

typedef struct Node *pNode;
struct Node
{
    bool leaf;
    int n;
    int *key;
    pNode *children;
};

void B_Tree_Print(pNode root, int indent);

// Create empty B-Tree
void B_Tree_Create(pNode &root);
void B_Tree_DeAllocate(pNode &root);
pNode B_Tree_Search(pNode root, int k, int &index);

// Insert
void B_Tree_Split_Child(pNode &father, int i);
void B_Tree_Insert(pNode &root, int k);
void B_Tree_Insert_NonFull(pNode &x, int k);

#endif