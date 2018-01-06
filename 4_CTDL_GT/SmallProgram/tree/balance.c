/* simple tree (no search or anything)
 * need to check if tree is balanced
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pNode;
struct Node {
	pNode left, right;
};

pNode newNode()
{
	pNode temp = malloc(sizeof(struct Node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(pNode r)
{
	if (!r) {
		return -1;
	}
	return 1 + max(height(r->left), height(r->right));
}

int isBalanced(pNode root)
{
	if (!root)
		return 1;
	int differ = height(root->left) - height(root->right);
	if (differ < -1 || differ > 1)
		return 0;
	if (!isBalanced(root->left) || !isBalanced(root->right))
		return 0;
	return 1;
}

int main()
{
	pNode p1 = newNode();
	pNode p2 = newNode();
	pNode p3 = newNode();
	pNode p4 = newNode();
	pNode p5 = newNode();
	pNode p6 = newNode();

	p1->left = p2;
	p1->right = p3;
	p3->left = p4;
	p3->right = p5;
	p5->right = p6;

	printf("%d\n", isBalanced(p2));

	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	return 0;
}
