#include "xuly.h"

Node *getNode(PhanSo k)
{
	Node *p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		exit(EXIT_FAILURE);
	}
	p->key = k;
	p->next = NULL;
	return p;
}

void addFirst(Node *&head, Node *&tail, PhanSo k)
{
	Node *p = getNode(k);

	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}
void addLast(Node *&head, Node *&tail, PhanSo k)
{
	Node *p = getNode(k);
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

void insertAfter(Node *Base, PhanSo k)
{
	if (Base == NULL)
	{
		exit(EXIT_FAILURE);
	}
	// Base-->afterBase
	Node *afterBase = getNode(k);
	afterBase->next = Base->next;
	Base->next = afterBase;
}
void insertBefore(Node *Base, PhanSo k)
{
	if (Base == NULL)
	{
		exit(EXIT_FAILURE);
	}
	PhanSo temp = Base->key;
	Base->key = k;
	insertAfter(Base, temp);
}

void deleteFirst(Node *&head, Node *&tail)
{
	if (head == NULL) // 0 Node
	{
		return;
	}
	else if (head == tail) // 1 Node
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		Node *p = head;
		head = head->next;
		delete p;
	}
}
void deleteLast(Node *&head, Node *&tail)
{
	if (head == NULL || head == tail)
	{
		deleteFirst(head, tail);
	}
	else
	{
		Node *p = head;
		while (p)
		{
			if (p->next == tail)
				break;
			p = p->next;
		}
		p->next = NULL;
		delete tail;
		tail = p;
	}
}
void deleteMiddle(Node *head, Node *tail, Node *Base)
{
	// delete Base->next
	if (Base == NULL)
		return;
	if (Base->next == NULL)
		return;
	Node *temp = Base->next;
	Base->next = temp->next;
	delete temp;
}

void createList(Node *&head, Node *&tail)
{
	head = tail = NULL;
	while (true)
	{
		cout << "Nhap phan so (Nhap mau so = 0 de thoat): ";
		PhanSo k;
		cin >> k.TuSo >> k.MauSo;
		if (k.MauSo == 0)
			break;
		//addFirst(head, tail, k);
		addLast(head, tail, k);
	}
}
void printList(Node *head)
{
	if (head == NULL)
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << head->key.TuSo << "/" << head->key.MauSo << "-->";
		printList(head->next);
	}
}
void destroyList(Node *&head, Node *&tail)
{
	Node *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete p;
	}
	tail = NULL;
}

int lenList(Node *head)
{
	int temp = 0;
	while (head)
	{
		head = head->next;
		temp++;
	}
	return temp;
}
void insertPos(Node *&head, Node *&tail, int pos, PhanSo k)
{
	int n = lenList(head);
	if (pos < 0 || pos > n)
	{
		cout << "Sai vi tri" << endl;
		return;
	}
	if (pos == 0)
		addFirst(head, tail, k);
	else if (pos == n)
		addLast(head, tail, k);
	else
	{
		int index = 0;
		Node *temp = head;
		for (; temp; temp = temp->next, index++)
		{
			if (index == pos)
				break;
		}
		insertBefore(temp, k);
	}
}
void deletePos(Node *&head, Node *&tail, int pos)
{
	int n = lenList(head);
	if (pos < 0 || pos >= n)
	{
		cout << "Sai vi tri" << endl;
		return;
	}
	else if (pos == 0)
		deleteFirst(head, tail);
	else if (pos == n - 1)
		deleteLast(head, tail);
	else
	{
		int index = 0;
		Node *temp = head;
		for (; temp; temp = temp->next, index++)
		{
			if (index == pos - 1)
				break;
		}
		deleteMiddle(head, tail, temp);
	}
}