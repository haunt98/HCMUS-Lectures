#include "SlinkedList.h"
#include <iostream>
using namespace std;

ref_n getNode(int k)
{
    ref_n p = new Node;
    if (!p)
        cout << "New NULL node ERROR\n";
    p->key = k;
    p->next = NULL;
    return p;
}

void addHead(ref_n &head, ref_n &tail, int k)
{
    ref_n p = getNode(k);
    if (!head) // empty list
        head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

void addTail(ref_n &head, ref_n &tail, int k)
{
    ref_n p = getNode(k);
    if (!head) // empty list
        addHead(head, tail, k);
    else
    {
        tail->next = p;
        tail = p;
    }
}

void delHead(ref_n &head, ref_n &tail)
{
    if (head) // not empty
    {
        if (!head->next) // 1 element
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            ref_n p = head;
            head = head->next;
            delete p;
        }
    }
}

void delTail(ref_n &head, ref_n &tail)
{
    if (head) // not empty
    {
        if (!head->next) // 1 element
        {
            delHead(head, tail);
        }
        else
        {
            ref_n p = head;
            while (p->next != tail)
            {
                p = p->next;
            }
            p->next = NULL;
            delete tail;
            tail = p;
        }
    }
}

void insertAfter(ref_n &head, ref_n &tail, ref_n q, int k)
{
    // -> q -> tro thanh -> q -> p ->
    if (q == tail)
        addTail(head, tail, k);
    else
    {
        ref_n p = getNode(k);
        p->next = q->next;
        q->next = p;
        if (!p->next)
            tail = p;
    }
}

void insertBefore(ref_n &head, ref_n &tail, ref_n q, int k)
{
    // -> q -> tro thanh -> p -> q ->
    if (q == head)
        addHead(head, tail, k);
    else
    {
        ref_n p = getNode(k);
        *p = *q;
        q->next = p;
        q->key = k;
    }
}

void delNode(ref_n &head, ref_n &tail, ref_n &q)
{
    if (q == head)
        delHead(head, tail);
    else if (q == tail)
        delTail(head, tail);
    else
    {
        // q -> p -> tro thanh q ->
        ref_n p = q->next;
        *q = *p;
        delete p;
        if (!q->next) // new tail
            tail = q;
    }
}

void addNodeKeepOrder(ref_n &head, ref_n &tail, int k)
{
    if (!head) // empty
    {
        head = getNode(k);
        tail = head;
        return;
    }

    ref_n temp = getNode(-1); // -1 only temp, no meaning
    temp->next = head;

    ref_n sentinel = getNode(k); // linh canh
    tail->next = sentinel;

    ref_n prev = temp;
    ref_n cur = prev->next;
    while (cur->key < k) // dont need to check cur != NULL
    {
        prev = cur;
        cur = cur->next;
    }
    ref_n p = getNode(k);
    prev->next = p;
    p->next = cur;

    if (p->next == head)
        head = p;
    if (p->next == sentinel)
        tail = p;

    delete temp;
    tail->next = NULL;
    delete sentinel;
}

void reverseList(ref_n &head, ref_n &tail)
{
    if (head && head->next) // >= 2 elements
    {
        ref_n prev = head;
        ref_n cur = head->next;

        tail = head;

        ref_n temp = NULL;
        while (cur)
        {
            // temp..prev->cur tro thanh temp<-prev..cur
            prev->next = temp;
            temp = prev;
            prev = cur;
            cur = cur->next;
        }
        prev->next = temp;
        head = prev;
    }
}

void delList(ref_n &head, ref_n &tail)
{
    while (head)
    {
        delHead(head, tail);
    }
}

void priList(ref_n head, ref_n tail)
{
    ref_n p = head;
    while (p != tail->next)
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}
