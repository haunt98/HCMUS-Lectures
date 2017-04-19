#include "xuly.h"

void Initialzie(DNode *&head)
{
	if (head != NULL)
		return;
}

bool isEmpty(DNode *head)
{
	if (head == NULL)
		return true;
	return false;
}

int countDNode(DNode *head)
{
	int temp = 0;
	DNode *p = head;
	while (p != NULL)
	{
		p = p->next;
		++temp;
	}
	return temp;
}
// find
DNode *findMid(DNode *head, int pos)
{
	int temp = 0;
	DNode *p = head;
	while (p != NULL && temp != pos)
	{
		p = p->next;
		temp++;
	}
	return p;
}

DNode *findValue(DNode *head, int x)
{
	DNode *p = head;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}

DNode *findTail(DNode *head)
{
	DNode *p = head;
	for (; p != NULL; p = p->next)
		if (p->next == NULL)
			break;
	return p;
}

// add
void addHead(DNode *&head, int x)
{
	if (head == NULL)
	{
		head = new DNode;
		head->data = x;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		DNode *p = new DNode;
		p->data = x;
		p->next = head;
		p->prev = NULL;
		head->prev = p;
		head = p;
	}
}

void addMid(DNode *&head, int pos, int x)
{
	if (head == NULL)
	{
		if (pos == 0)
			addHead(head, x);
	}
	else if (pos < 0 || pos >= countDNode(head))
		return;
	else
	{
		DNode *p = findMid(head, pos);
		DNode *mid = new DNode;
		mid->data = x;
		mid->next = p->next;
		mid->prev = p;
		p->next = mid;
	}
}

void addTail(DNode *&head, int x)
{
	if (head == NULL)
		addHead(head, x);
	else
	{
		DNode *p = findTail(head);
		DNode *tail = new DNode;
		tail->data = x;
		tail->next = NULL;
		tail->prev = p;
		p->next = tail;
	}
}

// delete
void deleteHead(DNode *&head)
{
	if (head == NULL) // 0 phan tu
		return;
	if (head->next == NULL) // 1 phan tu
	{
		delete head;
		head = NULL;
		return;
	}
	DNode *p = head;
	head = head->next;
	head->prev = NULL;
	delete p;
}

void deleteMid(DNode *&head, int pos)
{
	if (pos < 0 || pos >= countDNode(head))
		return;
	if (head == NULL)
		return;
	if (head->next == NULL || pos == 0)
	{
		deleteHead(head);
	}
	else if (pos == countDNode(head) - 1)
	{
		deleteTail(head);
	}
	else
	{
		DNode *mid = findMid(head, pos);
		DNode *p = mid->prev;
		p->next = mid->next;
		mid->next->prev = p;
		delete mid;
	}
}

void deleteTail(DNode *&head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		deleteHead(head);
		return;
	}
	DNode *p = findTail(head);
	DNode *tail = p->prev;
	tail->next = NULL;
	delete p;
}

void deleteAll(DNode *&head)
{
	while (head != NULL)
		deleteTail(head);
}

// test
void printDNode(DNode *head)
{
	if (head == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << head->data << "->";
		printDNode(head->next);
	}
}

void createDNode(DNode *&head)
{
	Initialzie(head);
	for (int i = 0; i < 10; ++i)
		addTail(head, i*i);
}