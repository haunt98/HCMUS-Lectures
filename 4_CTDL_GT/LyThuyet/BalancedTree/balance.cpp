#include "balance.h"
#include <iostream>

using namespace std;

pNode getNode(int k)
{
	pNode temp = new Node;
	if (!temp) {
		cout << "Can't make node" << endl;
	}
	temp->key = k;
	temp->pLeft = NULL;
	temp->pRight = NULL;
	return temp;
}

pNode balancedTree(int n)
{
	if (n == 0) {
		return NULL;
	}
	int nl = n / 2;
	int nr = n - nl - 1; // -1 is for the root
	int k;
	cin >> k;
	pNode p = getNode(k);
	p->pLeft = balancedTree(nl);
	p->pRight = balancedTree(nr);
	return p;
}

void printTree(pNode root, int indent)
{
	if (root) {
		// print in preorder
		for (int i = 0; i < indent; ++i) {
			cout << ' ';
		}
		cout << root->key << endl;

		printTree(root->pLeft, indent + 4);
		printTree(root->pRight, indent + 4);
	} else {
		for (int i = 0; i < indent; ++i) {
			cout << ' ';
		}
		cout << "NULL" << endl;
	}
}

void delTree(pNode &root)
{
	if (root) {
		delTree(root->pLeft);
		delTree(root->pRight);
		delete root;
	}
}

// Duyet cac thu tu
// Luon luon left truoc right sau
// Vi tri cua root co the la truoc, giua hoac sau
void xuly(pNode root)
{
	if (!root) {
		return;
	}
	cout << root->key << " ";
}

// xuly truoc roi den left, right
void preorder(pNode root)
{
	if (!root) {
		return;
	}
	xuly(root);
	preorder(root->pLeft);
	preorder(root->pRight);
}

// left truoc roi den xuly, right
void inorder(pNode root)
{
	if (!root) {
		return;
	}
	inorder(root->pLeft);
	xuly(root);
	inorder(root->pRight);
}

// left, right truoc roi den xu ly
void postorder(pNode root)
{
	if (!root) {
		return;
	}
	postorder(root->pLeft);
	postorder(root->pRight);
	xuly(root);
}

// Cai dat stack
Stack::Stack()
{
	m_top = NULL;
}

Stack::~Stack()
{
	pStackNode p = m_top;
	while (p) {
		pStackNode temp = p;
		p = p->pNext;
		delete temp;
	}
}

bool Stack::isEmpty()
{
	return m_top == NULL;
}

void Stack::push(pNode p)
{
	if (!p) {
		return;
	}
	pStackNode new_top = new StackNode;
	new_top->key = p;
	new_top->pNext = m_top;
	m_top = new_top;
}

pNode Stack::pop()
{
	if (!m_top) {
		return NULL;
	}
	pNode k = m_top->key;
	pStackNode temp = m_top;
	m_top = m_top->pNext;
	delete temp;
	return k;
}

// Duyet su dung stack de khu de quy
// bang cach su dung vong while
void preorderStack(pNode root)
{
	if (!root) {
		return;
	}
	pNode p = root;
	Stack s;
	s.push(p);
	while (!s.isEmpty()) {
		p = s.pop();
		xuly(p);
		// Dua right vao stack truoc left,
		// De khi lay left ra truoc right (LIFO)
		s.push(p->pRight);
		s.push(p->pLeft);
	}
}

// Duyet theo thu tu giua
// - nut co 2 con: dua right truoc nut sau
// - nut chi co con phai: nhu tren
// - nut chi co con trai: dua nut vao ngan xep
// truoc khi xu ly ben trai
void inorderStack(pNode root)
{
	pNode p = root;
	Stack s;
	// Vong while dung lai khi p la NULL
	while (p) {
		// Move p to the most left
		while (p) {
			// Dua right vao truoc root,
			// De xu ly root truoc right (LIFO)
			s.push(p->pRight);
			s.push(p);
			p = p->pLeft;
		}

		// Lay p, luc nay la most left cua tree
		p = s.pop();
		// Kiem tra p khong co right descendant
		while (!s.isEmpty() && !p->pRight) {
			xuly(p);
			p = s.pop();
		}

		// Dung lai vong while o tren khi p->pRight ton tai,
		// Xu ly p la vi tri giua, sau khi da xu ly left
		xuly(p);

		// Dung neu s empty, neu khong tra ve right cua p
		// pop becuase in next while, p will be add again
		p = s.isEmpty() ? NULL : s.pop();
	}
}

// Duyet theo thu tu sau
// - nut co 2 con: dat nut vao 2 lan
//   + lan 1: sau khi xu ly con ben trai
//   + lan 2: sau khi xu ly con ben phai
// - nut khong co con: xu ly truc tiep
void postorderStack(pNode root)
{
	pNode p = root;
	pNode q = root;
	Stack s;
	while (p) {
		// Truoc khi di xuong, dat goc vao ngan xep
		// Ket thuc vong while, p la most left cua
		while (p->pLeft) {
			s.push(p);
			p = p->pLeft;
		}
		// Neu p->pRight == q, p right ton tai,
		// nhung vua duoc xu ly, nen chi xu ly p
		while (p->pRight == q || !p->pRight) {
			xuly(p);
			q = p; // q tro vao nut vua duoc xu ly
			if (s.isEmpty()) {
				return;
			}
			p = s.pop(); // pop goc ra ngoai
		}

		// push goc lan 2
		s.push(p);
		p = p->pRight;
	}
}