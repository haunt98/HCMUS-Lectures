#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pNode p1 = newNode(1);
	pNode p2 = newNode(2);
	pNode p3 = newNode(3);
	pNode p4 = newNode(4);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p2;

	pNode p = findBeginCir(p1);
	if (p)
		printf("%d\n", p->x);

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	return 0;
}
