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

pNode findLast(pNode head, int i)
{
	/* idea is, p and q have i node between
	 * when q reach tail, p is ith from tail
	 */
	if (!head || i < 0)
		return NULL;
	if (!head->next) {
		if (i == 0)
			return head;
		else
			return NULL;
	}
	pNode p = head;
	pNode q = p;
	while (i > 0 && q->next) {
		q = q->next;
		--i;
	}
	if (i > 0) // i > size of list
		return NULL;

	while (q->next) {
		p = p->next;
		q = q->next;
	}
	return p;
}

void removeMid(pNode *head)
{
	if (!*head)
		return;
	if (!(*head)->next) {
		free(*head);
		*head = NULL;
		return;
	}

	// p move 1, q move 2
	// q reach tail, p is mid
	pNode prev = NULL;
	pNode p = *head;
	pNode q = *head;
	while (q) {
		prev = p;
		p = p->next;
		q = q->next;
		if (q) {
			q = q->next;
		}
	}
	prev->next = p->next;
	free(p);
}
