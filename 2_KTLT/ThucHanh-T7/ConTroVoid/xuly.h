#ifndef XULY_H
#define XULY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	void *key;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
	int size;
};

struct Data {
	void *key;
	int dSize;
};

struct PhanSo {
	int tu, mau;
};

Data *getData(void *, int dSize);
Node *getNode(Data *DT);
List *initList();
int count(List *LL);

void addHead(List *LL, Data *DT);
void addTail(List *LL, Data *DT);
void addMid(List *LL, Data *DT, int pos);
Node *addAfter(List *LL, Data *X, Data *Add,
	       bool (*cmp)(void *, void *, int dSize));

void removeHead(List *LL);
void removeTail(List *LL);
void removeMid(List *LL, int pos);
void removeList(List *LL);

bool cmpVoid(void *, void *, int dSize);
Node *findList(List *LL, Data *DT, bool (*cmp)(void *, void *, int dSize));

void printList(List *LL);
#endif
