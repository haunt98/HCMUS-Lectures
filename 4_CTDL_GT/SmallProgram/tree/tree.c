/* simple tree (no search or anything)
 * need to check if tree is balanced
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pNode;
struct Node {
	pNode left, right, parent;
	int x;
};

pNode newNode()
{
	pNode temp = malloc(sizeof(struct Node));
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

pNode newNodeX(int x)
{
	pNode temp = newNode();
	temp->x = x;
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

void printTree(pNode root, int indent)
{
	if (root) {
		for (int i = 0; i < indent; ++i) {
			printf(" ");
		}
		printf("%d\n", root->x);
		printTree(root->left, indent + 8);
		printTree(root->right, indent + 8);
	} else {
		for (int i = 0; i < indent; ++i) {
			printf(" ");
		}
		printf("NULL\n");
	}
}

void freeTree(pNode *root)
{
	if (*root) {
		freeTree(&((*root)->left));
		freeTree(&((*root)->right));
		free(*root);
	}
}

/* assumer arr is sorted
 * put mid in root
 * put left subarr recursively int root->left
 * right is same
 */
void insertArr(pNode *root, int arr[], int from, int to)
{
	if (from > to) {
		return;
	}
	int mid = from + (to - from) / 2;
	*root = newNodeX(arr[mid]);
	insertArr((&(*root)->left), arr, from, mid - 1);
	insertArr((&(*root)->right), arr, mid + 1, to);

	if ((*root)->left)
		(*root)->left->parent = *root;
	if ((*root)->right)
		(*root)->right->parent = *root;
}

int isAncestor(pNode r, pNode lil)
{
	if (!r)
		return 0;
	if (r == lil)
		return 1;
	return isAncestor(r->left, lil) || isAncestor(r->right, lil);
}

pNode sameAncestor(pNode p, pNode q)
{
	pNode r = p;
	while (r) {
		if (isAncestor(r, q))
			break;
		r = r->parent;
	}
	return r;
}

int main()
{
	pNode p1 = newNodeX(1);
	pNode p2 = newNodeX(2);
	pNode p3 = newNodeX(3);
	pNode p4 = newNodeX(4);
	pNode p5 = newNodeX(5);

	p1->left = p2;
	p2->parent = p1;
	p1->right = p3;
	p3->parent = p1;
	p3->left = p4;
	p4->parent = p3;
	p3->right = p5;
	p5->parent = p3;

	pNode r = sameAncestor(p4, p5);
	if (r)
		printf("%d\n", r->x);
	else
		printf("No r\n");

	freeTree(&p1);
	return 0;
}
