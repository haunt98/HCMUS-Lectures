#ifndef CIRCULAR_H
#define CIRCULAR_H

// Circular linked list
// tail->next=head

typedef struct CNode *pCNode;

struct CNode {
	int key;
	pCNode pNext;
};

struct CList {
	pCNode pHead;
	pCNode pTail;
};

void initCList(CList &l);
bool isEmpty(CList l);
pCNode getCNode(int k);

void addHead(CList &l, int k);
void delHead(CList &l);

void addTail(CList &l, int k);
void delTail(CList &l);

void removeAfter(CList &l, pCNode p);

void delList(CList &l);

void printList(CList l);

#endif