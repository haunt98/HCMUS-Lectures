#ifndef LLIST_INCLUDED
#define LLIST_INCLUDED

typedef struct Node *pNode;

struct Node {
	int x;
	pNode next;
};

pNode newNode(int x);
void printList(pNode head);
void freeList(pNode *head);

void addHead(pNode *head, int x);

// practice make perfect
void removeDup(pNode *head);
pNode findLast(pNode head, int i); // ith from tail
void removeMid(pNode *head);
pNode findBeginCir(pNode head); // find beginning loop in circular ll

#endif
