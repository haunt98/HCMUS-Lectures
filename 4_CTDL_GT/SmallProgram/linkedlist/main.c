#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pNode head = NULL;
	addHead(&head, 1);
	addHead(&head, 2);
	addHead(&head, 3);
	addHead(&head, 4);
	addHead(&head, 5);
	addHead(&head, 6);
	printList(head);

	int i = 3;
	pNode p = findLast(head, i);
	if (p)
		printf("%d\n", p->x);

	freeList(&head);
	return 0;
}
