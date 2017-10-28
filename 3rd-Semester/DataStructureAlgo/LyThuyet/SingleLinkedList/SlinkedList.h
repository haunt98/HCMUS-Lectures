#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

struct Node
{
    int key;
    Node *next;
};
typedef Node *ref;

ref getNode(int k);

void addHead(ref &head, ref &tail, int k);
void addTail(ref &head, ref &tail, int k);

void delHead(ref &head, ref &tail);
void delTail(ref &head, ref &tail);

void insertAfter(ref &head, ref &tail, ref q, int k);
void insertBefore(ref &head, ref &tail, ref q, int k);

void delNode(ref &head, ref &tail, ref &q);

// Them node van giu tang dan
void addNodeKeepOrder(ref &head, ref &tail, int k);

// Dao nguoc danh sach
void reverseList(ref &head, ref &tail);

void delList(ref &head, ref &tail);
void priList(ref head);

#endif
