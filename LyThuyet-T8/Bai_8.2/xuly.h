#include <iostream>
using namespace std;

struct SNode{
	int data;
	SNode *next;
};

int countSNode(SNode *head);

void reverseSNode(SNode *&head);

// them nhung van giu thu tu
void insert_into_ordered_list(SNode *&head, int x);

// test
void Initialize(SNode *&head);

void addFirst(SNode *&head, int x);

void addTail(SNode *&head, int x);

void createSNode(SNode *&head);

void printSNode(SNode *head);
