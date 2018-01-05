// AVL tree is a BST tree that is also height balanced:
// for each node x, the height og the left and right subtrees of x
// differ by at most 1
#include "avl.h"
#include <iostream>

using namespace std;

int main()
{
	pNode root = NULL;
	avlInsert(root, 1);
	avlInsert(root, 2);
	avlInsert(root, 3);
	avlInsert(root, 4);
	avlInsert(root, 5);
	avlInsert(root, 6);
	avlInsert(root, 7);
	avlInsert(root, 8);
	printPreOrder(root, 0);

	avlDelete(root, 3);
	printPreOrder(root, 0);

	avlDelete(root, 1);
	printPreOrder(root, 0);

	avlDelete(root, 8);
	printPreOrder(root, 0);

	avlDelete(root, 2);
	printPreOrder(root, 0);

	avlDelete(root, 1);
	printPreOrder(root, 0);

	delPostOrder(root);
	return 0;
}