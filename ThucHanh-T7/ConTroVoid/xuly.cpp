#include "xuly.h"

Node *getNode(Data *DT)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("Khong du bo nho\n");
		exit(0);
	}
	p->key = malloc(DT->dSize);
	if (p->key == NULL)
	{
		free(p);
		return NULL;
	}
	// replace memcpy
	for (int i = 0; i < DT->dSize; i++)
	{
		*((char *)p->key + i) = *((char *)DT->key + i);
	}
	p->next = NULL;

}
List *initList()
{
	List *LL = (List *)malloc(sizeof(List));
	LL->head = NULL;
	LL->tail = NULL;
	LL->size = 0;
	return LL;
}
int count(List *LL)
{
	return LL->size;
}

void addHead(List *LL, Data *DT)
{
	if (DT->key == NULL)
		return;
	Node *p = getNode(DT);
	if (p != NULL)
	{
		if (LL->head == NULL)
			LL->tail = p;
		p->next = LL->head;
		LL->head = p;
		LL->size++;
	}
}
void addTail(List *LL, Data *DT)
{
	if (DT->key == NULL)
		return;
	Node *p = getNode(DT);
	if (p != NULL)
	{
		if (LL->head == NULL)
			LL->head = p;
		LL->tail->next = p;
		LL->tail = p;
		LL->size++;
	}
}
void addMid(List *LL, Data *DT, int pos)
{
	if (pos < 0 || pos > LL->size || DT->key == NULL)
		return;
	if (pos == 0)
		addHead(LL, DT);
	else if (pos == LL->size)
		addTail(LL, DT);
	else
	{
		Node *p = getNode(DT);
		Node *temp = LL->head;
		for (int i = 0; i < pos - 1; i++, temp = temp->next)
			;
		p->next = temp->next;
		temp->next = p;
		LL->size++;
	}

}
Node *addAfter(List *LL, Data *X, Data *Add, bool(*cmp)(void *, void *, int dSize))
{
	Node *p = findList(LL, X, cmp);
	if (p != NULL)
	{
		Node *temp = getNode(Add);
		temp->next = p->next;
		p->next = temp;
		if (temp->next == NULL)
			LL->tail = temp;
		LL->size++;
		return temp;
	}
	return NULL;
}

void removeHead(List *LL)
{
	if (LL->head != NULL)
	{
		Node *temp = LL->head;
		if (temp == LL->tail)
			LL->head = LL->tail = NULL;
		else
			LL->head = temp->next;

		if (temp->key != NULL)
			free(temp->key);
		free(temp);
		LL->size--;
	}
}
void removeTail(List *LL)
{
	if (LL->head != NULL)
	{
		if (LL->head == LL->tail)
			removeHead(LL);
		else
		{
			Node *p = LL->head;
			while (p->next != LL->tail)
				p = p->next;
			p->next = NULL;
			Node *temp = LL->tail;
			LL->tail = p;
			if (temp->key != NULL)
				free(temp->key);
			free(temp);
			LL->size--;
		}
	}
}
void removeMid(List *LL, int pos)
{
	if (pos < 0 || pos >= LL->size)
		return;
	if (pos == 0)
		removeHead(LL);
	else if (pos == LL->size)
		removeTail(LL);
	else
	{
		Node *p = LL->head;
		for (int i = 0; i < pos - 1; i++, p = p->next)
			;
		Node *temp = p->next;
		p->next = temp->next;
		free(temp->key);
		free(temp);
		LL->size--;
	}
}
void removeList(List *LL)
{
	while (LL->head != NULL)
		removeHead(LL);
}

bool cmpVoid(void *A, void *B, int dSize)
{
	for (int i = 0; i < dSize; i++)
	{
		if (*((char *)A + i) != *((char *)B + i))
			return false;
	}
	return true;
}
Node *findList(List *LL, Data *DT, bool(*cmp)(void *, void*, int dSize))
{
	Node *p = LL->head;
	for (p; p != NULL; p = p->next)
	{
		if (cmp(p->key, DT->key, DT->dSize))
		{
			return p;
			break;
		}
	}
	return NULL;
}

void printList(List *LL)
{
	Node *p = LL->head;
	while (p != LL->tail && p)
	{
		printf("%d->", p->key);
		p = p->next;
	}
	if (p)
		printf("%d->NULL\n", p->key);
	else
		printf("NULL\n");
}
