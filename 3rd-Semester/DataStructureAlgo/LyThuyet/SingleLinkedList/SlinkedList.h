#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

struct Node
{
    int key;
    Node *next;
};
typedef Node *ref_n;

ref_n getNode(int k);

void addHead(ref_n &head, ref_n &tail, int k);
void addTail(ref_n &head, ref_n &tail, int k);

void delHead(ref_n &head, ref_n &tail);
void delTail(ref_n &head, ref_n &tail);

void insertAfter(ref_n &head, ref_n &tail, ref_n q, int k);
void insertBefore(ref_n &head, ref_n &tail, ref_n q, int k);

void delNode(ref_n &head, ref_n &tail, ref_n &q);

// Them node van giu tang dan
void addNodeKeepOrder(ref_n &head, ref_n &tail, int k);

// Dao nguoc danh sach
void reverseList(ref_n &head, ref_n &tail);

void delList(ref_n &head, ref_n &tail);
void priList(ref_n head, ref_n tail);

#endif
