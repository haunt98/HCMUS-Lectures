#include <iostream>
using namespace std;

struct DNode{
	int data;
	DNode *prev;
	DNode *next;
};

void Initialzie(DNode *&head);

bool isEmpty(DNode *head);

int countDNode(DNode *head);

// find
DNode *findMid(DNode *head, int pos);

DNode *findValue(DNode *head, int x);

DNode *findTail(DNode *head);

// add
void addHead(DNode *&head, int x);

void addMid(DNode *&head, int pos, int x);

void addTail(DNode *&head, int x);

// delete
void deleteHead(DNode *&head);

void deleteMid(DNode *&head, int pos);

void deleteTail(DNode *&head);

void deleteAll(DNode *&head);

// test
void printDNode(DNode *head);

void createDNode(DNode *&head);