#ifndef _BALANCE_H
#define _BALANCE_H

typedef struct Node *pNode;
struct Node {
	int key;
	pNode pLeft;
	pNode pRight;
};

pNode getNode(int k);

// n la kich thuoc cua cay
pNode balancedTree(int n);

void printTree(pNode root, int indent);
void delTree(pNode &root);

// Duyet: truoc, giua, sau
void xuly(pNode root);
void preorder(pNode root);
void inorder(pNode root);
void postorder(pNode root);

// Duyet su dung stack
// LIFO: Last In Fist Out
typedef struct StackNode *pStackNode;
struct StackNode {
	pNode key;
	pStackNode pNext;
};

class Stack
{
      private:
	pStackNode m_top;

      public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(pNode p);
	pNode pop();
};

void preorderStack(pNode root);
void inorderStack(pNode root);
void postorderStack(pNode root);

#endif