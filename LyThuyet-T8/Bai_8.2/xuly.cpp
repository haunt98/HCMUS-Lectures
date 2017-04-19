#include "xuly.h"

int countSNode(SNode *head)
{
	int temp = 0;
	SNode *p = head;
	while (p != NULL)
	{
		p = p->next;
		++temp;
	}
	return temp;
}

void reverseSNode(SNode *&head)
{
	// dao chieu mui ten
	// A->B->C thanh A<-B<-C
	SNode *prev = NULL;
	SNode *cur = head;
	while (cur != NULL)
	{
		SNode *temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	head = prev;
}

void insert_into_ordered_list(SNode *&head, int x)
{
	SNode *prev = NULL;
	SNode *cur = head;
	while (cur != NULL && cur->data <= x)
	{
		prev = cur;
		cur = cur->next;
	}

	SNode *temp = new SNode;
	temp->data = x;
	temp->next = cur;

	if (prev == NULL) // 1 phan tu
	{
		head = temp;
	}
	else
	{
		prev->next = temp;
	}
}

// test
void Initialize(SNode *&head)
{
	head = NULL;
}

void addTail(SNode *&head, int x)
{
	if (head == NULL)
	{
		head = new SNode;
		head->data = x;
		head->next = NULL;
		return;
	}
	SNode *p = head;
	for (; p != NULL; p = p->next)
		if (p->next == NULL)
			break;
	SNode *tail = new SNode;
	tail->data = x;
	tail->next = NULL;
	p->next = tail;
}

void createSNode(SNode *&head)
{
	Initialize(head);
	if (head != NULL)
		return;
	for (int i = 0; i < 10; ++i)
		addTail(head, i*i);
}

void printSNode(SNode *head)
{
	if (head == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << head->data << "->";
		printSNode(head->next);
	}
}