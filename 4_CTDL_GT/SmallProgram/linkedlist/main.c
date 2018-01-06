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
	printList(head);

	freeList(&head);
	return 0;
}
