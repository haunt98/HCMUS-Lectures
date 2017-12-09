#include "bst.h"
#include <iostream>

using namespace std;

void printPreOrder(pNode root, int indent)
{
    if (root)
    {
        // print in preorder
        for (int i = 0; i < indent; ++i)
        {
            cout << ' ';
        }
        cout << root->key << endl;

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

void delPostOder(pNode &root)
{
    if (root)
    {
        delPostOder(root->left);
        delPostOder(root->right);
        delete root;
    }
}

pNode getNode(int k)
{
    pNode newNode = new Node;
    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Walk
// In BST tree, InOrder print in sorted order
void InOrder(pNode root)
{
    if (root)
    {
        InOrder(root->left);
        cout << root->key << " "; // mid
        InOrder(root->right);
    }
}

void PreOrder(pNode root)
{
    if (root)
    {
        cout << root->key << " "; // before
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(pNode root)
{
    if (root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " "; // after
    }
}

// Search
pNode searchRecursive(pNode root, int k)
{
    // NULL or root
    if (!root || root->key == k)
    {
        return root;
    }
    if (root->key < k)
    {
        return searchRecursive(root->right, k);
    }
    return searchRecursive(root->left, k);
}

pNode searchIterative(pNode root, int k)
{
    pNode r = root;
    while (r && r->key != k)
    {
        if (r->key < k)
        {
            r = r->right;
        }
        else
        {
            r = r->left;
        }
    }
    return r;
}

// min and max
pNode minimum(pNode root)
{
    // min is the most left of BST tree
    pNode r = root;
    while (r && r->left)
    {
        r = r->left;
    }
    return r;
}

pNode maximum(pNode root)
{
    // max is the most right of BST tree
    pNode r = root;
    while (r && r->right)
    {
        r = r->right;
    }
    return r;
}

// successor and predecessor
pNode successor(pNode x)
{
    // successor(x) is the node with the smallest key greater than x
    // if x has right subtree, successor(x) is the min of
    // right subtree
    if (x->right)
    {
        return minimum(x->right);
    }
    // if x has no right subtree, successor(x) is the lowest ancestor(x)
    // whose left child is also an ancestor(x)
    pNode y = x->parent;
    while (y && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

pNode predecessor(pNode x)
{
    // predecessor(x) is the node with the largest key smaller than x
    if (x->left)
    {
        return maximum(x->left);
    }
    // if x has no left subtree, predecessor(x) is the lowest ancestor(x)
    // whose right child is also an ancestor(x)
    pNode y = x->parent;
    while (y && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// insertion and deletion
void insertionRecursive(pNode &root, int k)
{
    pNode z = getNode(k);
    pNode y = NULL;
    pNode x = root;
    // Travese to where to insert
    while (x)
    {
        if (x->key == k)
        {
            cout << k << " already exist " << endl;
            delete z;
            return;
        }
        if (x->key < k)
        {
            y = x;
            x = x->right;
        }
        else if (x->key > k)
        {
            y = x;
            x = x->left;
        }
    }
    z->parent = y;
    if (!y) // tree is empty
    {
        root = z;
    }
    else if (y->key > k)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}

void insertionRecursive(pNode &root, pNode parent, int k)
{
    if (!root)
    {
        pNode z = getNode(k);
        root = z;
        // Exception when root is real 'root'
        // when that, parent is NULL
        if (parent)
        {
            z->parent = parent;
            if (parent->key > k)
            {
                parent->left = z;
            }
            else
            {
                parent->right = z;
            }
        }
    }
    else
    {
        if (root->key == k)
        {
            cout << k << " already exist" << endl;
        }
        else if (root->key < k)
        {
            insertionRecursive(root->right, root, k);
        }
        else
        {
            insertionRecursive(root->left, root, k);
        }
    }
}

void transplant(pNode &root, pNode &u, pNode &v)
{
    // replace subtree at node u with subtree at node v
    // u is root
    if (!u->parent)
    {
        root = v;
    }
    // u is left child of parent(u)
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    // u is right child
    else if (u == u->parent->right)
    {
        u->parent->right = v;
    }
    // set parent(v) to match parent(u)
    if (v)
    {
        v->parent = u->parent;
    }
}

void deletionSuc(pNode &root, int k)
{
    pNode z = searchIterative(root, k);
    if (!z)
    {
        cout << "Don't exist so don't delete" << endl;
        return;
    }
    if (!z->left)
    {
        transplant(root, z, z->right);
    }
    else if (!z->right)
    {
        transplant(root, z, z->left);
    }
    // z has 2 children
    else
    {
        // y is successor(z), y has no left child
        pNode y = minimum(z->right);
        // if y is right child of z, only replace z by y
        // if not, first replace y by y->right then
        // replace z by y
        if (y->parent != z)
        {
            // replace y by y->right
            transplant(root, y, y->right);
            // make y right child same as z right child
            y->right = z->right;
            y->right->parent = y;
        }
        // replace z by y
        transplant(root, z, y);
        // make y left child same as z left child
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}

void deletionPre(pNode &root, int k)
{
    pNode z = searchIterative(root, k);
    if (!z)
    {
        cout << "Don't exist so don't delete" << endl;
        return;
    }
    if (!z->left)
    {
        transplant(root, z, z->right);
    }
    else if (!z->right)
    {
        transplant(root, z, z->left);
    }
    // z has 2 children
    else
    {
        // y is predecessor(z), y has no right child
        pNode y = maximum(z->left);
        if (y->parent != z)
        {
            // replace y by y->left
            transplant(root, y, y->left);
            // because z->left != y change y->left to z->left
            y->left = z->left;
            y->left->parent = y;
        }
        // replace z by y
        transplant(root, z, y);
        // set y->right to same as z->right
        y->right = z->right;
        y->right->parent = z->right;
    }
    delete z;
}
