#include "Circular.h"
#include <iostream>

using namespace std;

void initCList(CList &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

bool isEmpty(CList l)
{
	return l.pHead == NULL && l.pTail == NULL;
}

pCNode getCNode(int k)
{
	pCNode temp = new CNode;
	if (!temp) {
		cout << "Can't new node" << endl;
	}
	temp->key = k;
	temp->pNext = temp;
	return temp;
}

void addHead(CList &l, int k)
{
	pCNode temp = getCNode(k);
	if (isEmpty(l)) {
		l.pHead = temp;
		l.pTail = temp;
	} else {
		temp->pNext = l.pHead;
		l.pTail->pNext = temp;
		l.pHead = temp;
	}
}

void delHead(CList &l)
{
	if (isEmpty(l)) {
		return;
	}
	if (l.pHead == l.pTail) {
		delete l.pHead;
		initCList(l);
	} else {
		CNode *temp = l.pHead;
		l.pHead = l.pHead->pNext;
		l.pTail->pNext = l.pHead;
		delete temp;
	}
}

void addTail(CList &l, int k)
{
	pCNode temp = getCNode(k);
	if (isEmpty(l)) {
		l.pHead = temp;
		l.pTail = temp;
	} else {
		temp->pNext = l.pHead;
		l.pTail->pNext = temp;
		l.pTail = temp;
	}
}

void delTail(CList &l)
{
	if (isEmpty(l)) {
		return;
	}
	if (l.pHead == l.pTail) {
		delete l.pHead;
		initCList(l);
	} else {
		pCNode p = l.pHead;
		while (p->pNext != l.pTail) {
			p = p->pNext;
		}
		delete l.pTail;
		l.pTail = p;
		l.pTail->pNext = l.pHead;
	}
}

void removeAfter(CList &l, pCNode p)
{
	if (isEmpty(l) || !p) {
		return;
	}
	if (p == l.pTail) {
		delHead(l);
	} else if (p->pNext == l.pTail) {
		delTail(l);
	} else {
		CNode *temp = p->pNext;
		p->pNext = temp->pNext;
		delete temp;
	}
}

void delList(CList &l)
{
	while (l.pHead) {
		delHead(l);
	}
}

void printList(CList l)
{
	if (isEmpty(l)) {
		cout << "NULL" << endl;
	} else {
		CNode *temp = l.pHead;
		do {
			cout << temp->key << "->";
			temp = temp->pNext;
		} while (temp != l.pTail->pNext);
		if (temp == l.pHead) {
			cout << "HEAD" << endl;
		} else {
			cout << "CIRCLE_WHAT?" << endl;
		}
	}
}