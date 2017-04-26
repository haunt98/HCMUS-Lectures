#include <iostream>
using namespace std;

struct PhanSo
{
	int TuSo, MauSo;
};

struct Node
{
	PhanSo key;
	Node * next;
};

Node *getNode(int k);

void addFirst(Node *&head, Node *&tail, PhanSo k);
void addLast(Node *&head, Node *&tail, PhanSo k);

void insertAfter(Node *base, PhanSo k);
void insertBefore(Node *base, PhanSo k);

void deleteFirst(Node *&head, Node *&tail);
void deleteLast(Node *&head, Node *&tail);
void deleteMiddle(Node *head, Node *tail, Node *Base);

void createList(Node *&head, Node *&tail);
void printList(Node *head);
void destroyList(Node *&head, Node *&tail);

int lenList(Node *head);
void insertPos(Node *&head, Node *&tail, int pos, PhanSo k);
void deletePos(Node *&head, Node *&tail, int pos);