#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

pNode newNode(int x)
{
	pNode temp = (pNode)malloc(sizeof(struct Node));
	if (!temp) {
		printf("Can't malloc\n");
		return NULL;
	}
	temp->x = x;
	temp->next = NULL;
	return temp;
}

void printList(pNode head)
{
	pNode p = head;
	while (p) {
		printf("%d->", p->x);
		p = p->next;
	}
	printf("NULL\n");
}

void freeList(pNode *head)
{
	while (*head) {
		pNode p = *head;
		*head = (*head)->next;
		free(p);
	}
}

void addHead(pNode *head, int x)
{
	pNode newHead = newNode(x);
	if (!newHead)
		return;

	newHead->next = *head;
	*head = newHead;
}

void removeDup(pNode *head)
{
	if (!*head || !(*head)->next)
		return;
	for (pNode prev = *head, cur = (*head)->next; cur;) {
		pNode p;
		for (p = *head; p != cur; p = p->next) {
			if (p->x == cur->x)
				break;
		}
		if (p == cur) { // no dup
			prev = cur;
			cur = cur->next;
		} else {
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
	}
}
