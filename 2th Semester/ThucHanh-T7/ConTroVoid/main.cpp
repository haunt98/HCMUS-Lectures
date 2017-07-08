#include "xuly.h"
#define N 8

int main()
{
	// kieu int
	printf("Kieu int\n");
	int x; Data *DT; List *LL_int = initList();
	for (int i = 0; i < 6; i++)
	{
		x = i; DT = getData(&x, sizeof(int));
		addTail(LL_int, DT);
		free(DT);
	}
	printList(LL_int);
	//Them vao dau
	x = 10; DT = getData(&x, sizeof(int));
	addHead(LL_int, DT); free(DT); printList(LL_int);
	//Bo dau,duoi,giua
	removeHead(LL_int); printList(LL_int);
	removeTail(LL_int); printList(LL_int);
	removeMid(LL_int, 3); printList(LL_int);
	removeList(LL_int);
	//kieu phan so
	printf("Kieu phan so\n");
	PhanSo ps[] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 6, 7 }, { -2, 3 }, { 10, 20 } };
	int n = sizeof(ps) / sizeof(ps[0]); int dSize = sizeof(PhanSo);
	List *LL_ps = initList();
	for (int i = 0; i < n; i++)
	{
		DT = getData(&ps[i], dSize);
		addTail(LL_ps, DT);
		free(DT);
	}
	printList(LL_ps);
	//Them vao dau
	PhanSo temp_ps = { 100, 200 }; DT = getData(&temp_ps, dSize);
	addHead(LL_ps, DT); free(DT); printList(LL_ps);
	//Bo dau,duoi,giua
	removeHead(LL_ps); printList(LL_ps);
	removeTail(LL_ps); printList(LL_ps);
	removeMid(LL_ps, 3); printList(LL_ps);
	//removeList(LL_ps);
	return 0;
}
