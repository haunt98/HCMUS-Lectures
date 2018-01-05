#ifndef SORT_TOPOLOGY_H
#define SORT_TOPOLOGY_H

// Sap xep Topology
// a truoc b nghia la cong viec a lam xong
// moi xu ly cong viec b
// 3 tinh chat:
// - Phan xung (a truoc b thi b khong the truoc a)
// - Bac Cau (a truoc b, b truoc c => a truoc c)
// - Phan xa (a khong truoc a)

typedef struct leader *lref;
typedef struct trailer *tref;

struct leader {
	int key;
	int count;  // So phan tu leader "dung truoc" leader dang xet
	lref next;  // Leader tiep theo trong list
	tref trail; // Con tro quan ly 1 danh sach
		    // nhung phan tu trong danh sach nay la 1 con tro
		    // tro den leader "dung sau" leader dang xet
};

struct trailer {
	lref id;
	tref next;
};

// Chi them vao w chua co trong danh sach
// tra ve vi tri cua w
// z la so phan tu da them vao
lref addList(lref &head, lref &tail, int w, int &z);

// Debug by printing it
void printList(lref head, lref tail);
void delList(lref &head, lref &tail);

#endif