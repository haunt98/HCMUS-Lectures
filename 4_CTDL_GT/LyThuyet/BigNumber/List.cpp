#include "List.h"
#include <iostream>

using namespace std;

// Node
pNode getNode(int d)
{
	pNode temp = new Node;
	temp->d = d;
	temp->pNext = NULL;
	temp->pPrev = NULL;
	return temp;
}

// List
List::List()
{
	pHead = NULL;
	pTail = NULL;
	count = 0;
}

List::~List()
{
	del();
}

void List::addHead(int d)
{
	pNode temp = getNode(d);
	if (!pHead) {
		pHead = temp;
		pTail = temp;
	} else {
		pHead->pPrev = temp;
		temp->pNext = pHead;
		pHead = temp;
	}
	++count;
}

void List::addTail(int d)
{
	pNode temp = getNode(d);
	if (!pHead) {
		pHead = temp;
		pTail = temp;
	} else {
		pTail->pNext = temp;
		temp->pPrev = pTail;
		pTail = temp;
	}
	++count;
}

void List::print()
{
	pNode temp = pHead;
	while (temp) {
		cout << temp->d;
		temp = temp->pNext;
	}
	cout << " ";
}

bool List::isEmpty()
{
	return pHead == NULL && pTail == NULL && count == 0;
}

void List::del()
{
	while (pHead) {
		pNode temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
	pHead = NULL;
	pTail = NULL;
	count = 0;
}

void List::delHead()
{
	if (pHead) {
		// Chi co mot phan tu
		if (!pHead->pNext) {
			delete pHead;
			pHead = NULL;
			pTail = NULL;
			count = 0;
		} else {
			pNode temp = pHead;
			pHead = pHead->pNext;
			pHead->pPrev = NULL;
			delete temp;
		}
	}
}

// So sanh
bool List::operator==(const List &l)
{
	if (count != l.count) {
		return false;
	}
	pNode p = pHead;
	pNode q = l.pHead;
	while (p && q) {
		if (p->d != q->d) {
			return false;
		}
		p = p->pNext;
		q = q->pNext;
	}
	return true;
}

bool List::operator<(const List &l)
{
	if (count < l.count) {
		return true;
	}
	if (count > l.count) {
		return false;
	}
	pNode p = pHead;
	pNode q = l.pHead;
	while (p) {
		if (p->d < q->d) {
			return true;
		} else if (p->d > q->d) {
			return false;
		}
		p = p->pNext;
		q = q->pNext;
	}
	return false;
}

// Gan
List &List::operator=(const List &l)
{
	if (this != &l) {
		// dealloc self
		del();
		// copy from l
		pNode p = l.pHead;
		while (p) {
			addTail(p->d);
			p = p->pNext;
		}
	}
	return *this;
}

List &List::operator+=(const List &l)
{
	pNode p = pTail;
	pNode q = l.pTail;
	int soDu = 0;
	while (p && q) {
		int temp = p->d + q->d + soDu;
		p->d = temp % 10;
		soDu = temp / 10;
		p = p->pPrev;
		q = q->pPrev;
	}
	// this longer than l
	while (p && !q) {
		if (soDu == 0) {
			break;
		}
		int temp = p->d + soDu;
		p->d = temp % 10;
		soDu = temp / 10;
		p = p->pPrev;
	}
	// l longer than this
	while (!p && q) {
		int temp = q->d + soDu;
		addHead(temp % 10);
		soDu = temp / 10;
		q = q->pPrev;
	}
	// l and this end but soDu still remain
	while (!p && !q) {
		if (soDu == 0) {
			break;
		}
		addHead(soDu);
		p = pHead;
	}
	return *this;
}

// Luon lay so lon tru so be
List &List::operator-=(const List &l)
{
	List small, big;
	if (*this < l) {
		small = *this;
		big = l;
	} else {
		small = l;
		big = *this;
	}

	// big -= small
	pNode p = big.pTail;
	pNode q = small.pTail;
	int soDu = 0;
	while (p && q) {
		int temp = p->d - q->d - soDu;
		soDu = 0;
		while (temp < 0) {
			temp += 10;
			++soDu;
		}
		p->d = temp;
		p = p->pPrev;
		q = q->pPrev;
	}
	// big longer than small
	while (p && !q) {
		if (soDu == 0) {
			break;
		}
		int temp = p->d - soDu;
		soDu = 0;
		while (temp < 0) {
			temp += 10;
			++soDu;
		}
		p->d = temp;
		p = p->pPrev;
	}
	while (big.pHead && big.pHead->pNext && big.pHead->d == 0) {
		big.delHead();
	}

	*this = big;
	return *this;
}