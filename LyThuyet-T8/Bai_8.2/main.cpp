#include "xuly.h"

int main(void)
{
	SNode *head;
	createSNode(head);
	insert_into_ordered_list(head, -20);
	//reverseSNode(head);
	printSNode(head);
	return 0;
}