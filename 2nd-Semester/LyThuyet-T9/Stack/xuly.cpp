#include "xuly.h"

SNode *makeSNode(int x)
{
	SNode *temp = new SNode;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

// mang dong
void init_aStack(aStack &S, int initSize)
{
	S.data = new int[initSize];
	S.top = 0;
	S.size = initSize;
}

bool Empty_aStack(aStack S)
{
	return S.top == 0;
}

bool Full_aStack(aStack S)
{
	return S.top == S.size;
}

void push_aStack(aStack &S, int x)
{
	S.data[S.top] = x;
	S.top++;
}

bool pop_aStack(aStack &S, int &x)
{
	if (!Empty_aStack(S))
	{
		x = S.data[S.top - 1];
		S.top--;
		return true;
	}
	return false;
}

bool peek_aStack(aStack S, int &x)
{
	if (!Empty_aStack(S))
	{
		x = S.data[S.top - 1];
		return true;
	}
	return false;
}

void rand_aStack(aStack &S)
{
	for (int i = 0; i < S.size; ++i)
	{
		push_aStack(S, i*i);
	}
}

void print_aStack(aStack S)
{
	int temp = S.top - 1;
	while (temp >= 0)
	{
		cout << S.data[temp] << endl;
		temp--;
	}
}
// danh sach

void init_lStack(lStack &S)
{
	S.head = NULL;
}

bool Empty_lStack(lStack S)
{
	return S.head == NULL;
}

bool Full_lStack(lStack S)
{
	return false;
}

void push_lStack(lStack &S, int x)
{
	SNode *temp = makeSNode(x);
	temp->next = S.head;
	S.head = temp;
}

bool pop_lStack(lStack &S, int &x)
{
	if (!Empty_lStack(S))
	{
		SNode *temp = S.head;
		x = temp->data;
		S.head = S.head->next;
		delete temp;
	}
	return false;
}

bool peek_lStack(lStack &S, int &x)
{
	if (!Empty_lStack(S))
	{
		x = S.head->data;
		return true;
	}
	return false;
}

void rand_lStack(lStack &S)
{
	for (int i = 0; i < MAX; ++i)
	{
		push_lStack(S, i*i);
	}
}

void print_lStack(lStack S)
{
	SNode *temp = S.head;
	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}