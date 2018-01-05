// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "SortTopology.h"
#include <iostream>

using namespace std;

lref addList(lref &head, lref &tail, int w, int &z)
{
	// Luc dau, head va tail tro vao leader chua co gia tri
	lref h = head;
	// Linh canh
	tail->key = w;
	// Tim vi tri w trong list (neu co)
	while (h->key != w) {
		h = h->next;
	}
	// Neu khong tim thay, w xuat hien o tail (linh canh)
	if (h == tail) {
		tail = new leader; // Tao tail moi de trong
		++z;		   // Tang so luong phan tu leader

		h->count = 0;
		h->next = tail;  // Giu tail luc dau
		h->trail = NULL; // Tam thoi chua co leader dung sau
	}
	return h; // Tra ve con tro giu o nho w
}

void printList(lref head, lref tail)
{
	lref l = head;
	while (l != tail) {
		cout << l->key << ", count: " << l->count << ", trail: ";
		tref t = l->trail;
		while (t) {
			cout << t->id->key << "->";
			t = t->next;
		}
		cout << "NULL" << endl;
		l = l->next;
	}
}

void delList(lref &head, lref &tail)
{
	while (head) {
		lref ltemp = head;
		head = head->next;
		tref ltrail = ltemp->trail;
		while (ltrail) {
			tref ttemp = ltrail;
			ltrail = ltrail->next;
			delete ttemp;
		}
		delete ltemp;
	}
	delete tail;
}