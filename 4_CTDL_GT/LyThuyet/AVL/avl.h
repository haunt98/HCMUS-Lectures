#ifndef _AVL_H
#define _AVL_H

typedef struct Node *pNode;
struct Node {
	int key;
	pNode pLeft;
	pNode pRight;
};

// Vua them vua phai can bang lai
void findAdd(pNode &root, int k);

void printTree(pNode root, int indent);

void delTree(pNode &root);

#endif