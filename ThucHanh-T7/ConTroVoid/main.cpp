#include "xuly.h"
#define N 8

void randList(List *);

int main()
{
	List *LL = initList();
	randList(LL);

	// tao 1 Data
	Data *DT = (Data *)malloc(sizeof(Data));
	DT->dSize = sizeof(float);
	float x = 20;
	DT->key = &x;

	Data *NEW = (Data *)malloc(sizeof(Data));
	NEW->dSize = sizeof(float);
	float y = 99;
	NEW->key = &y;

	printList(LL);
	addMid(LL, DT, 8);
	printList(LL);
	addAfter(LL, DT, NEW, cmpVoid);
	printList(LL);
	removeList(LL);
	return 0;
}

void randList(List *LL)
{
	Data *DT = (Data *)malloc(sizeof(Data));
	for (int i = 0; i < N; i++)
	{
		DT->dSize = sizeof(int);
		DT->key = &i;
		addHead(LL, DT);
	}
	free(DT);
}
