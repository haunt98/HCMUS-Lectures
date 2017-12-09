#include "avl.h"
#include <iostream>

using namespace std;

pNode getNode(int k)
{
    pNode newNode = new Node;
    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->height = 0;
    return newNode;
}

void printPreOrder(pNode root, int indent)
{
    if (root)
    {
        // print in preorder
        for (int i = 0; i < indent; ++i)
        {
            cout << ' ';
        }
        cout << root->key << " " << root->height << endl;

        printPreOrder(root->left, indent + 4);
        printPreOrder(root->right, indent + 4);
    }
    else
    {
        for (int i = 0; i < indent; ++i)
        {
            cout << ' ';
        }
        cout << "NULL" << endl;
    }
}

void delPostOrder(pNode &root)
{
    if (root)
    {
        delPostOrder(root->left);
        delPostOrder(root->right);
        delete root;
    }
}

pNode search(pNode root, int k)
{
    pNode r = root;
    while (r && r->key != k)
    {
        if (r->key > k)
        {
            r = r->left;
        }
        else
        {
            r = r->right;
        }
    }
    return r;
}

// height check
int height(pNode p)
{
    // NULL co height la -1
    if (!p)
    {
        return -1;
    }
    return p->height;
}

void update_height(pNode p)
{
    if (p)
    {
        p->height = 1 + max(height(p->left), height(p->right));
    }
}

// min and max
pNode minimum(pNode root)
{
    pNode r = root;
    while (r && r->left)
    {
        r = r->left;
    }
    return r;
}

pNode maximum(pNode root)
{
    pNode r = root;
    while (r && r->right)
    {
        r = r->right;
    }
    return r;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

// rotate
void leftRotate(pNode &root, pNode x)
{
    // x          y
    //  \        / \
	//  y  ->   x
    // / \     / \

    if (!x || !x->right)
    {
        return;
    }
    // left rotate: replace x by its right child
    pNode y = x->right;
    y->parent = x->parent;

    // y left child become x right child
    x->right = y->left;
    if (y->left)
    {
        y->left->parent = x;
    }

    // x is root
    if (!x->parent)
    {
        root = y;
    }
    // x is left child
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    // make x become left child of y
    y->left = x;
    x->parent = y;

    // Update height
    update_height(x);
    update_height(y);
}

void rightRotate(pNode &root, pNode x)
{
    //    x       y
    //   / \     / \
	//  y     ->    x
    // / \         / \

    if (!x || !x->left)
    {
        return;
    }
    // right rotate: replace x by its left child
    pNode y = x->left;
    y->parent = x->parent;

    // y right child become x left child
    x->left = y->right;
    if (y->right)
    {
        y->right->parent = x;
    }

    // x is root
    if (!x->parent)
    {
        root = y;
    }
    // x is left child
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    // make x become right child of y
    y->right = x;
    x->parent = y;

    // Update height
    update_height(x);
    update_height(y);
}

// insert and delete
void avlInsert(pNode &root, int k)
{
    pNode y = NULL;
    pNode x = root;
    pNode z = getNode(k);

    // find where to insert
    while (x)
    {
        if (x->key == k)
        {
            cout << k << " already exist" << endl;
            delete z;
            return;
        }
        if (x->key > k)
        {
            y = x;
            x = x->left;
        }
        else
        {
            y = x;
            x = x->right;
        }
    }

    // Empty tree because y still NULL
    if (!y)
    {
        root = z;
        return;
    }
    else
    {
        // insert z to left child of y
        if (y->key > k)
        {
            y->left = z;
        }
        // right child of y
        else
        {
            y->right = z;
        }
        z->parent = y;
        update_height(y);
    }

    // rebalance height
    avlRebalance(root, y);
}

void avlRebalance(pNode &root, pNode x)
{
    // from bottom to root
    // check violate height-balance and update_height
    while (x)
    {
        update_height(x);
        // nghieng trai
        if (height(x->left) > height(x->right) + 1)
        {
            // left-left case
            if (height(x->left->left) >= height(x->left->right))
            {
                rightRotate(root, x);
            }
            // left-right case
            else
            {
                leftRotate(root, x->left);
                rightRotate(root, x);
            }
        }
        // nghieng phai
        else if (height(x->right) > height(x->left) + 1)
        {
            // right-right case
            if (height(x->right->right) >= height(x->right->left))
            {
                leftRotate(root, x);
            }
            // right-left case
            else
            {
                rightRotate(root, x->left);
                leftRotate(root, x);
            }
        }
        x = x->parent;
    }
}

void transplant(pNode &root, pNode u, pNode v)
{
    // replace u by v
    // u is root
    if (!u->parent)
    {
        root = v;
    }
    // u is left child
    else if (u->parent->left == u)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if (v)
    {
        v->parent = u->parent;
    }
}

void avlDelete(pNode &root, int k)
{
    pNode z = search(root, k);
    if (!z)
    {
        cout << "Don't exist don't delete" << endl;
        return;
    }
    // track: track positon where first potentially violate AVL
    // keep track is hard
    // if z has no children, when delete z, z->parent may violate
    // if z has only left child, when delete z, z->left take place
    // z original position, may violate
    // if z has only right child, same as only left child
    // if z has 2 children, z now replace by successor(z)
    // may violate at z original position
    pNode track = z;
    if (!z->left)
    {
        if (!z->right)
        {
            track = z->parent;
        }
        else
        {
            track = z->right;
        }
        transplant(root, z, z->right);
    }
    else if (!z->right)
    {
        track = z->left;
        transplant(root, z, z->left);
    }
    // z has 2 children
    else
    {
        // y is successor(x), y has no left child
        pNode y = minimum(z->right);
        if (y->parent != z)
        {
            transplant(root, y, y->right);
            // z->right become y->right
            y->right = z->right;
            y->right->parent = y;
            track = y->parent;
        }
        else
        {
            track = y;
        }
        transplant(root, z, y);
        // z->left become y->left
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
    avlRebalance(root, track);
}