#include "redblack.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
	// Sentinel node, always black
	NIL = new Node;
	NIL->color = Black;
	root = NIL;
}

pNode getNode(int k, Colors color, pNode NIL)
{
	pNode newNode = new Node;
	if (!newNode) {
		cout << "Can't make node" << endl;
	}
	newNode->key = k;
	newNode->left = NIL;
	newNode->right = NIL;
	newNode->parent = NIL;
	newNode->color = color;
	return newNode;
}

void printPreOrder(pNode root, pNode NIL, int indent)
{
	if (root != NIL) {
		// print in preorder
		for (int i = 0; i < indent; ++i) {
			cout << ' ';
		}
		cout << root->key << " ";
		if (root->color == Black) {
			cout << "B" << endl;
		} else {
			cout << "R" << endl;
		}

		printPreOrder(root->left, NIL, indent + 4);
		printPreOrder(root->right, NIL, indent + 4);
	} else {
		for (int i = 0; i < indent; ++i) {
			cout << ' ';
		}
		cout << "NULL" << endl;
	}
}

void delPostOrder(pNode &root, pNode NIL)
{
	if (root != NIL) {
		delPostOrder(root->left, NIL);
		delPostOrder(root->right, NIL);
		delete root;
	}
}

pNode search(Tree T, int k)
{
	pNode r = T.root;
	while (r != T.NIL && r->key != k) {
		if (r->key > k) {
			r = r->left;
		} else {
			r = r->right;
		}
	}
	return r;
}

// rotate
void leftRotate(Tree &T, pNode x)
{
	if (x == T.NIL || x->right == T.NIL) {
		return;
	}
	// left rotate is replace x by y,
	pNode y = x->right;
	y->parent = x->parent;

	// y left child become x right child
	x->right = y->left;
	if (y->left != T.NIL) {
		y->left->parent = x;
	}

	// x is root
	if (x->parent == T.NIL) {
		T.root = y;
	}
	// x is left child of its parent
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	// x is right child of its parent
	else {
		x->parent->right = y;
	}
	// left rotate make x become left child of y
	y->left = x;
	x->parent = y;
}

void rightRotate(Tree &T, pNode x)
{
	if (x == T.NIL || x->left == T.NIL) {
		return;
	}
	// right rotate is replace x by y
	pNode y = x->left;
	y->parent = x->parent;

	// y right child become x left child
	x->left = y->right;
	if (x->left != T.NIL) {
		x->left->parent = x;
	}

	// x is root
	if (x->parent == T.NIL) {
		T.root = y;
	}
	// x is left child
	else if (x->parent->left == x) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	// right rotate make x become right child of y
	x->parent = y;
	y->right = x;
}

// insert
void rbInsert(Tree &T, int k)
{
	pNode y = T.NIL;
	pNode x = T.root;
	pNode z = getNode(k, Red, T.NIL);

	// find where to insert
	while (x != T.NIL) {
		if (x->key == k) {
			cout << k << " already exist" << endl;
			delete z;
			return;
		}
		if (x->key < k) {
			y = x;
			x = x->right;
		} else {
			y = x;
			x = x->left;
		}
	}

	// Empty tree
	if (y == T.NIL) {
		T.root = z;
	} else if (y->key > k) {
		y->left = z;
	} else {
		y->right = z;
	}
	z->parent = y;
	// Recolor and rotate when violate red black tree
	rbInsertFixUp(T, z);
}

void rbInsertFixUp(Tree &T, pNode z)
{
	// violate z and z->parent same Red
	// Terminate when z is root os parent(z) is Black
	while (z->parent->color == Red) {
		if (z->parent == z->parent->parent->left) {
			// y is right uncle(z)
			pNode y = z->parent->parent->right;
			if (y->color == Red) {
				// Case 1, z->parent and y color is Red
				// Change z->parent and y color to Black
				// change z->parent->parent (grandparent) color
				// to Red
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			}
			// if y color is Black
			else {
				if (z->parent->right == z) {
					// Case 2, z is right child
					// left rotate z and z->parent to make z
					// left child
					z = z->parent;
					leftRotate(T, z);
				}
				// Case 3, z is left child
				// right rotate grandparent(z) and change color
				z->parent->color = Black;
				z->parent->parent->color = Red;
				rightRotate(T, z->parent->parent);
			}
		} else {
			// opposite of above
			// y is left uncle(z)
			pNode y = z->parent->parent->left;
			if (y->color == Red) {
				// Case 1, z->parent and y color is Red
				// Change z->parent and y color to Black
				// change z->parent->parent (grandparent) color
				// to Red
				z->parent->color = Black;
				y->color = Black;
				z->parent->parent->color = Red;
				z = z->parent->parent;
			}
			// if y color is Black
			else {
				if (z->parent->left == z) {
					// Case 2, z is left child
					// right rotate z and z->parent to make
					// z right child
					z = z->parent;
					rightRotate(T, z);
				}
				// Case 3, z is right child
				// left rotate grandparent(z) and change color
				z->parent->color = Black;
				z->parent->parent->color = Red;
				leftRotate(T, z->parent->parent);
			}
		}
	}
	T.root->color = Black;
}

// min and max
pNode minimum(pNode root, pNode NIL)
{
	// The most left
	pNode r = root;
	while (r != NIL && r->left != NIL) {
		r = r->left;
	}
	return r;
}

pNode maximum(pNode &root, pNode NIL)
{
	// The most right
	pNode r = root;
	while (r != NIL && r->right != NIL) {
		r = r->right;
	}
	return r;
}

// delete
void rbTransplant(Tree &T, pNode u, pNode v)
{
	// Emptry tree
	if (u->parent == T.NIL) {
		T.root = v;
	}
	// u is left child
	if (u->parent->left == u) {
		u->parent->left = v;
	}
	// u is right child
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

void rbDelete(Tree &T, int k)
{
	pNode z = search(T, k);
	if (z == T.NIL) {
		cout << "Don't exist don't delete" << endl;
		return;
	}
	// y need to be removed-z or to moved-successor(z)
	pNode y = z;
	Colors y_original_color = y->color;
	// x keep track of y's original position
	pNode x;
	if (z->left == T.NIL) {
		x = z->right;
		rbTransplant(T, z, z->right);
	} else if (z->right == T.NIL) {
		x = z->left;
		rbTransplant(T, z, z->left);
	}
	// z has 2 children
	else {
		// y is successor(z), y has no left child
		y = minimum(z->right, T.NIL);
		y_original_color = y->color;
		x = y->right;
		// if y is right child of z
		if (y->parent == z) {
			// make sure x->parent point to y
			// even if x is NIL
			x->parent = y;
		} else {
			// replace y by y->right
			rbTransplant(T, y, y->right);
			// make sure z->right is right child of y
			y->right = z->right;
			y->right->parent = y;
		}
		// replace z by y
		rbTransplant(T, z, y);
		// make sure z->left is left child of y
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	// if y original color is black, violate the height of black nodes
	if (y_original_color == Black) {
		rbDeleteFixUp(T, x);
	}
}

void rbDeleteFixUp(Tree &T, pNode x)
{
	// x is doubly-black
	while (x != T.root && x->color == Black) {
		// x is left child
		if (x->parent->left == x) {
			// w is sibling of x
			// w can't be NIL because it violate height of black
			// tree remember x is doubly-black if w is NIL, simple
			// path to w less then simple path to x
			pNode w = x->parent->right;
			if (w->color == Red) {
				// Case 1
				// make w Black and left rotate to convert to
				// case 2,3,4
				x->parent->color = Red;
				w->color = Black;
				leftRotate(T, x->parent);
				w = x->parent->right; // reset sibling
			}
			if (w->left->color == Black &&
			    w->right->color == Black) {
				// Case 2
				// Both children of w is Black
				w->color = Red;
				// move x
				x = x->parent;
			} else {
				if (w->right->color == Black) {
					// Case 3
					// right child of w is Black
					// right rotate then change color
					w->color = Red;
					w->left->color = Black;
					rightRotate(T, w);
					w = x->parent->right;
				}
				// Case 4
				// right child of w is Red
				w->color = x->parent->color;
				x->parent->color = Black;
				w->right->color = Black;
				leftRotate(T, x->parent);
				x = T.root;
			}
		}
		// x is right child
		else {
			// this is symmetric of above
			// w is sibling of x
			// w can't be NIL because it violate height of black
			// tree remember x is doubly-black if w is NIL, simple
			// path to w less then simple path to x
			pNode w = x->parent->left;
			if (w->color == Red) {
				// Case 1
				// make w Black and right rotate to convert to
				// case 2,3,4
				x->parent->color = Red;
				w->color = Black;
				rightRotate(T, x->parent);
				w = x->parent->left; // reset sibling
			}
			if (w->left->color == Black &&
			    w->right->color == Black) {
				// Case 2
				// Both children of w is Black
				w->color = Red;
				// move x
				x = x->parent;
			} else {
				if (w->left->color == Black) {
					// Case 3
					// left child of w is Black
					// left rotate and change color
					w->color = Red;
					w->right->color = Black;
					leftRotate(T, w);
					w = x->parent->left;
				}
				// Case 4
				// left child of w is Red
				w->color = x->parent->color;
				x->parent->color = Black;
				w->left->color = Black;
				rightRotate(T, x->parent);
				x = T.root;
			}
		}
	}
	// x is red-and-black
	x->color = Black;
}