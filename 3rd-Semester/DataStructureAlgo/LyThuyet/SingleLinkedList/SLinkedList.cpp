#include "SlinkedList.h"
#include <iostream>
using namespace std;

ref getNode(int k)
{
    ref p = new Node;
    if (!p)
        cout << "New NULL node ERROR\n";
    p->key = k;
    p->next = NULL;
    return p;
}

void addHead(ref &head, ref &tail, int k)
{
    ref p = getNode(k);
    if (!head) // empty list
        head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

void addTail(ref &head, ref &tail, int k)
{
    ref p = getNode(k);
    if (!head) // empty list
        addHead(head, tail, k);
    else
    {
        tail->next = p;
        tail = p;
    }
}

void delHead(ref &head, ref &tail)
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
            ref p = head;
            head = head->next;
            delete p;
        }
    }
}

void delTail(ref &head, ref &tail)
{
    if (head) // not empty
    {
        if (!head->next) // 1 element
        {
            delHead(head, tail);
        }
        else
        {
            ref p = head;
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

void insertAfter(ref &head, ref &tail, ref q, int k)
{
    // -> q -> tro thanh -> q -> p ->
    if (q == tail)
        addTail(head, tail, k);
    else
    {
        ref p = getNode(k);
        p->next = q->next;
        q->next = p;
        if (!p->next)
            tail = p;
    }
}

void insertBefore(ref &head, ref &tail, ref q, int k)
{
    // -> q -> tro thanh -> p -> q ->
    if (q == head)
        addHead(head, tail, k);
    else
    {
        ref p = getNode(k);
        *p = *q;
        q->next = p;
        q->key = k;
    }
}

void delNode(ref &head, ref &tail, ref &q)
{
    if (q == head)
        delHead(head, tail);
    else if (q == tail)
        delTail(head, tail);
    else
    {
        // q -> p -> tro thanh q ->
        ref p = q->next;
        *q = *p;
        delete p;
        if (!q->next) // new tail
            tail = q;
    }
}

void delList(ref &head, ref &tail)
{
    while (head)
    {
        delHead(head, tail);
    }
}

void priList(ref head)
{
    ref p = head;
    while (p)
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}
