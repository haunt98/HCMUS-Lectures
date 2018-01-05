#include "SortLinkedList.h"
#include <iostream>

// Test
void resetList(List &l, int size, int *arr_test)
{
	delList(l);
	for (int i = 0; i < size; ++i) {
		addTail(l, arr_test[i]);
	}
}

bool isSort(List l)
{
	pNode temp = l.pHead;
	while (temp != l.pTail) {
		if (temp->key > temp->pNext->key) {
			return false;
		}
		temp = temp->pNext;
	}
	return true;
}

// Quicksort
void quickSortWithPrev(List &l, pNode prevHead)
{
	// Truong hop list rong, list co 1 phan tu
	// Truong hop neu pivot tra ve head hoac tail
	if (l.pHead == l.pTail || prevHead == l.pTail) {
		return;
	}

	// Chon pivot cuoi danh sach
	pNode prevPivot = prevHead;
	pNode pivot = l.pTail;

	// prev va cur chay song song
	pNode prev = prevHead;
	pNode cur = prev->pNext;
	while (cur != pivot) {
		if (cur->key > pivot->key) {
			// Move cur after pivot
			prev->pNext = cur->pNext;
			cur->pNext = pivot->pNext;
			pivot->pNext = cur;

			// Only update tail 1 time, when pivot is tail
			if (l.pTail == pivot) {
				l.pTail = cur;
			}

			cur = prev->pNext;
		} else {
			// Move prev and cur
			prev = cur;
			cur = cur->pNext;
			prevPivot = prev;
		}
	}
	l.pHead = prevHead->pNext; // Update head again

	// De quy, cho head..prevPivot va pivot->pNext..tail
	List lLeft;
	lLeft.pHead = l.pHead;
	lLeft.pTail = prevPivot;

	List lRight;
	lRight.pHead = pivot->pNext;
	lRight.pTail = l.pTail;

	quickSortWithPrev(lLeft, prevHead);
	quickSortWithPrev(lRight, pivot);

	// Cap nhap head va tail cua l theo lLeft va lRight
	// Vi khi chay de quy, l.pHead va l.pTail khong tu cap nhap
	l.pHead = lLeft.pHead;
	l.pTail = lRight.pTail;
}

void quickSort(List &l)
{
	pNode prevHead = getNode(-1);
	prevHead->pNext = l.pHead;
	quickSortWithPrev(l, prevHead);
	delete prevHead;
}

// Merge sort
void divideList(List &l, List &lleft, List &lright)
{
	if (isEmptyList(l)) {
		initList(lleft);
		initList(lright);
		return;
	}
	if (!l.pHead->pNext) {
		lleft = l;
		initList(lright);
		return;
	}
	// set up begin and end
	lleft.pHead = l.pHead;
	lright.pTail = l.pTail;
	// step1 skip 1 node
	// step2 skip 2 node
	// when step2 reach tail, step1 is the middle
	pNode step1 = l.pHead;
	pNode step2 = l.pHead->pNext;
	while (step2 && step2->pNext) {
		step1 = step1->pNext;
		if (step2->pNext) {
			step2 = step2->pNext->pNext;
		} else {
			step2 = step2->pNext;
		}
	}
	// set up middle
	lleft.pTail = step1;
	lright.pHead = step1->pNext;
	lleft.pTail->pNext = NULL;
}

void merge(List &l, List &lleft, List &lright)
{
	if (isEmptyList(lleft) && isEmptyList(lright)) {
		l.pHead = NULL;
		l.pTail = NULL;
		return;
	}
	if (isEmptyList(lleft)) {
		l = lright;
		return;
	}
	if (isEmptyList(lright)) {
		l = lleft;
		return;
	}
	pNode prevList = getNode(-1);
	pNode temp = prevList;

	// so nao nho hon dua vao
	while (lleft.pHead && lright.pHead) {
		if (lleft.pHead->key < lright.pHead->key) {
			temp->pNext = lleft.pHead;
			lleft.pHead = lleft.pHead->pNext;
		} else {
			temp->pNext = lright.pHead;
			lright.pHead = lright.pHead->pNext;
		}
		temp = temp->pNext;
	}

	// Neu con mot list chua duoc merge
	while (lleft.pHead) {
		temp->pNext = lleft.pHead;
		lleft.pHead = lleft.pHead->pNext;
		temp = temp->pNext;
	}
	while (lright.pHead) {
		temp->pNext = lright.pHead;
		lright.pHead = lright.pHead->pNext;
		temp = temp->pNext;
	}

	temp->pNext = NULL;
	l.pHead = prevList->pNext;
	l.pTail = temp;
	delete prevList;
}

void mergeSort(List &l)
{
	if (l.pHead != l.pTail) {
		List lleft, lright;
		divideList(l, lleft, lright);
		mergeSort(lleft);
		mergeSort(lright);
		merge(l, lleft, lright);
	}
}

// Insertion sort
void insertionSort(List &l)
{
	if (isEmptyList(l) || !l.pHead->pNext) {
		return;
	}
	pNode prevKey = l.pHead;
	pNode key = l.pHead->pNext;
	// Bien tam de tro ve head
	pNode prevList = getNode(-1);
	prevList->pNext = l.pHead;
	while (key) {
		// Kiem tra co chen hay khong
		bool isInsert = false;
		// Thay vi duyet nguoc nhu mang, ta duyet tu dau list,
		// khi gap node dau tien > key, insertBefore node do
		for (pNode prevP = prevList, p = prevList->pNext; p != key;
		     prevP = p, p = p->pNext) {
			if (p->key > key->key) {
				// Chen key vao giua prevP va P
				// dong thoi thay doi prevKey->pNext de tiep tuc
				// vong lap key
				prevP->pNext = key;
				prevKey->pNext = key->pNext;
				key->pNext = p;
				isInsert = true;
				break;
			}
		}
		if (!isInsert) {
			prevKey = key;
			key = key->pNext;
		}
	}
	// Xu ly head va tail
	l.pHead = prevList->pNext;
	l.pTail = prevKey;
	delete prevList;
}

// Selection sort
void selectionSort(List &l)
{
	if (isEmptyList(l) || !l.pHead->pNext) {
		return;
	}
	// Bien tam
	pNode prevList = getNode(-1);
	prevList->pNext = l.pHead;
	for (pNode prevP = prevList, p = prevP->pNext; p;
	     prevP = p, p = p->pNext) {
		// q chay sau p
		for (pNode prevQ = p, q = p->pNext; q;
		     prevQ = q, q = q->pNext) {
			if (p->key > q->key) {
				if (prevQ == p) {
					// swap next cua p va q
					prevP->pNext = q;
					p->pNext = q->pNext;
					q->pNext = p;
				} else {
					// swap prev cua p va q
					prevP->pNext = q;
					prevQ->pNext = p;
					// swap next cua p va q
					pNode temp = p->pNext;
					p->pNext = q->pNext;
					q->pNext = temp;
				}
				// swap p va q
				pNode temp = p;
				p = q;
				q = temp;
			}
		}
		// Xu ly tail
		if (!p->pNext) {
			l.pTail = p;
		}
	}
	l.pHead = prevList->pNext;
	delete prevList;
}