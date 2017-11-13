#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Typdef before use is OK
// because forward declaration
typedef struct Node *pNode;

struct Node
{
    int key;
    pNode pNext;
};

struct List
{
    pNode pHead;
    pNode pTail;
};

void initList(List &);
bool isEmptyList(List);
pNode getNode(int k);

#endif
