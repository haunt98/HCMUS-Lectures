#include "xuly.h"

int main()
{
	Node *head, *tail;
	createList(head, tail);
	printList(head);

	cout << "Them mot phan so vao cuoi danh sach" << endl;
	PhanSo k;
	cout << "Nhap phan so can them : ";
	do {
		cin >> k.TuSo >> k.MauSo;
	} while (k.MauSo == 0);
	addLast(head, tail, k);
	printList(head);

	cout << "Chen phan so tai vi tri xac dinh" << endl;
	cout << "Nhap phan so can them : ";
	do {
		cin >> k.TuSo >> k.MauSo;
	} while (k.MauSo == 0);
	cout << "Nhap vi tri : ";
	int i;
	cin >> i;
	insertPos(head, tail, i, k);
	printList(head);

	cout << "Xoa phan so tai vi tri xac dinh" << endl;
	cout << "Nhap vi tri : ";
	cin >> i;
	deletePos(head, tail, i);
	printList(head);

	// Huy danh sach
	destroyList(head, tail);
	return 0;
}