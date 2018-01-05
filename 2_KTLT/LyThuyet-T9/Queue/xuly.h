#include <iostream>
using namespace std;
#define MAX 10

struct CNode {
	int data;
	CNode *next;
};

// Mang dong
struct aQueue {
	int *data;
	int size;
	int in;
	int out;
	int count;
};

void init_aQueue(aQueue &Q, int initSize);
bool Empty_aQueue(aQueue Q);
bool Full_aQueue(aQueue Q);

bool push_aQueue(aQueue &Q, int x);
bool pop_aQueue(aQueue &Q, int &x);
bool peek_aQueue(aQueue Q, int &x);

void rand_aQueue(aQueue &Q);
void print_aQueue(aQueue Q);

// Danh sach
struct lQueue {
	CNode *head;
	CNode *tail;
};

void init_lQueue(lQueue &Q);
bool Empty_lQueue(lQueue Q);

void push_lQueue(lQueue &Q, int x);
bool pop_lQueue(lQueue &Q, int &x);
bool peek_lQueue(lQueue Q, int &x);

void rand_lQueue(lQueue &Q);
void print_lQueue(lQueue Q);