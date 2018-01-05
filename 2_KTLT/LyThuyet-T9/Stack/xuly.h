#include <iostream>
using namespace std;
#define MAX 10

struct SNode {
	int data;
	SNode *next;
};

SNode *makeSNode(int x);

// mang dong
struct aStack {
	int *data;
	int top;
	int size;
};

void init_aStack(aStack &S, int initSize);
bool Empty_aStack(aStack S);
bool Full_aStack(aStack S);
void push_aStack(aStack &S, int x);
bool pop_aStack(aStack &S, int &x);
bool peek_aStack(aStack S, int &x);

void rand_aStack(aStack &S);
void print_aStack(aStack S);
// lien ket
struct lStack {
	SNode *head;
};

void init_lStack(lStack &S);
bool Empty_lStack(lStack S);
bool Full_lStack(lStack S);
void push_lStack(lStack &S, int x);
bool pop_lStack(lStack &S, int &x);
bool peek_lStack(lStack &S, int &x);

void rand_lStack(lStack &S);
void print_lStack(lStack S);