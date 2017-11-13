#include "LinkedList.h"
#include <iostream>

using namespace std;

void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

bool isEmptyList(List l)
{
    return l.pHead == NULL && l.pTail == NULL;
}

pNode getNode(int k)
{
    pNode temp = new Node;
    temp->key = k;
    temp->pNext = NULL;
    return temp;
}
