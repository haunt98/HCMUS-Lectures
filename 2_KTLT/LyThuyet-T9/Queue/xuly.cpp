#include "xuly.h"

// Mang dong
void init_aQueue(aQueue &Q, int initSize)
{
	Q.data = new int[initSize];
	Q.size = initSize;
	Q.in = 0;
	Q.out = 0;
	Q.count = 0;
}

bool Empty_aQueue(aQueue Q)
{
	return Q.count == 0;
}

bool Full_aQueue(aQueue Q)
{
	return Q.count == Q.size;
}

bool push_aQueue(aQueue &Q, int x)
{
	if (!Full_aQueue(Q)) {
		Q.data[Q.in] = x;
		Q.in = (Q.in + 1) % Q.size;
		Q.count++;
		return true;
	}
	return false;
}

bool pop_aQueue(aQueue &Q, int &x)
{
	if (!Empty_aQueue(Q)) {
		x = Q.data[Q.out];
		Q.out = (Q.out + 1) % Q.size;
		Q.count--;
		return true;
	}
	return false;
}

bool peek_aQueue(aQueue Q, int &x)
{
	if (!Empty_aQueue(Q)) {
		x = Q.data[Q.out];
		return true;
	}
	return false;
}

void rand_aQueue(aQueue &Q)
{
	for (int i = 0; i < MAX; ++i) {
		push_aQueue(Q, i * i);
	}
}

void print_aQueue(aQueue Q)
{
	if (!Empty_aQueue(Q)) {
		if (Q.out < Q.in) {
			for (int i = Q.out; i < Q.in; ++i) {
				cout << Q.data[i] << endl;
			}
		}

		else {
			for (int i = Q.out; i < Q.size; ++i) {
				cout << Q.data[i] << endl;
			}
			for (int i = 0; i < Q.in; ++i) {
				cout << Q.data[i] << endl;
			}
		}
	}
}

// Danh sach
void init_lQueue(lQueue &Q)
{
	Q.head = NULL;
	Q.tail = NULL;
}

bool Empty_lQueue(lQueue Q)
{
	return Q.head == NULL;
}

void push_lQueue(lQueue &Q, int x)
{
	CNode *temp = new CNode;
	temp->data = x;
	temp->next = NULL;
	if (Q.head == NULL) {
		Q.head = temp;
		temp->next = Q.head;
		Q.tail = temp;
	} else {
		temp->next = Q.head;
		Q.head = temp;
		Q.tail->next = Q.head;
	}
}

bool pop_lQueue(lQueue &Q, int &x)
{
	if (!Empty_lQueue(Q)) {
		CNode *temp = Q.head;
		for (; temp; temp = temp->next) {
			if (temp->next == Q.tail)
				break;
		}
		x = Q.tail->data;
		temp->next = Q.head;
		delete Q.tail;
		Q.tail = temp;
		return true;
	}
	return false;
}

bool peek_lQueue(lQueue Q, int &x)
{
	if (!Empty_lQueue(Q)) {
		x = Q.tail->data;
		return true;
	}
	return false;
}

void rand_lQueue(lQueue &Q)
{
	for (int i = 0; i < MAX; ++i) {
		push_lQueue(Q, i * i);
	}
}

void print_lQueue(lQueue Q)
{
	CNode *temp = Q.head;
	while (temp) {
		cout << temp->data << endl;
		temp = temp->next;
		if (temp == Q.head)
			break;
	}
}