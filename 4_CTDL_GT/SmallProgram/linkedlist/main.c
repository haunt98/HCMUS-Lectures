#include "llist.h"
#include <stdlib.h>

int main()
{
	pNode head = NULL;
	addHead(&head, 1);
	addHead(&head, 2);
	addHead(&head, 3);
	addHead(&head, 2);
	addHead(&head, 1);
	addHead(&head, 4);
	addHead(&head, 5);
	addHead(&head, 4);
	addHead(&head, 3);
	printList(head);

	removeDup(&head);
	printList(head);

	freeList(&head);
	return 0;
}
