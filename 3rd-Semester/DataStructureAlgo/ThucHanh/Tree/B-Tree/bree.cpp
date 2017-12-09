#include "btree.h"
#include <iostream>

using namespace std;

// so key moi node co the chua:
// it nhat: T_MIN_DEGREE-1
// nhieu nhat 2*T_MIN_DEGREE-1
const int T_MIN_DEGREE = 2;

void B_Tree_Print(pNode root, int indent)
{
    if (root)
    {
        // print in preorder
        for (int i = 0; i < indent; ++i)
        {
            cout << ' ';
        }
        for (int i = 0; i < root->n; ++i)
        {
            cout << root->key[i] << " ";
        }
        cout << endl;
        if (!root->leaf)
        {
            for (int i = 0; i < root->n + 1; ++i)
            {
                B_Tree_Print(root->children[i], indent + 8);
            }
        }
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

// Create empty B-Tree
void B_Tree_Create(pNode &root)
{
    root = new Node;
    root->n = 0;
    root->leaf = true;
    root->key = NULL;
    root->children = NULL;
}

void B_Tree_DeAllocate(pNode &root)
{
    if (root)
    {
        if (!root->leaf)
        {
            for (int i = 0; i < root->n + 1; ++i)
            {
                B_Tree_DeAllocate(root->children[i]);
            }
            free(root->children);
        }
        free(root->key);
        delete root;
    }
}

pNode B_Tree_Search(pNode root, int k, int &index)
{
    int j = 0;
    while (j < root->n && k > root->key[j])
    {
        ++j;
    }
    // stop when k >= root->key[j] or j == root->n
    if (j < root->n && k == root->key[j])
    {
        index = j;
        return root;
    }
    if (root->leaf)
    {
        return NULL;
    }
    return B_Tree_Search(root->children[j], k, index);
}

// Insert
// Insert in B-Tree is different from insert in BST
// We don't create new node then insert x,
// instead we insert key to existing leaf node
// If leaf node is full(2t-1 keys) we split it
// A tip: we split (if node full) as we go down
// From root, if root full split it
// then split ... to the node
void B_Tree_Split_Child(pNode &father, int i)
{
    // old_son=children(father) ith is full
    // split old_son to old_son and new_son
    // old_son->n: t-1 and new_son->n: t-1
    // the other key make to father
    pNode old_son = father->children[i];
    pNode new_son = new Node;
    new_son->leaf = old_son->leaf;
    new_son->n = T_MIN_DEGREE - 1;
    new_son->key = (int *)malloc(sizeof(int) * new_son->n);
    // copy t-1 largest key from old_son to new_son
    for (int j = 0; j < T_MIN_DEGREE - 1; ++j)
    {
        // new_son->key[0..t-2] and old_son->key[t..2t-2]
        new_son->key[j] = old_son->key[j + T_MIN_DEGREE];
    }
    // old_son is not leaf node so copy children
    if (!old_son->leaf)
    {
        // copy t largest children from y to z
        new_son->children = (pNode *)malloc(sizeof(pNode) * (new_son->n + 1));
        for (int j = 0; j < T_MIN_DEGREE; ++j)
        {
            // new_son->c[0..t-1] and old_son->c[t..2t-1]
            new_son->children[j] = old_son->children[j + T_MIN_DEGREE];
        }
    }
    old_son->n = T_MIN_DEGREE - 1;
    //// increase father's children and father's key
    // move its childrean to the right
    father->children =
        (pNode *)realloc(father->children, sizeof(pNode) * (father->n + 2));
    for (int j = father->n + 1; j > i + 1; --j)
    {
        father->children[j] = father->children[j - 1];
    }
    father->children[i + 1] = new_son;
    // move its key to the right
    father->key = (int *)realloc(father->key, sizeof(int) * (father->n + 1));
    for (int j = father->n; j > i; --j)
    {
        father->key[j] = father->key[j - 1];
    }
    father->key[i] = old_son->key[T_MIN_DEGREE - 1];
    ++father->n;
    // strip old son's key and children
    old_son->key = (int *)realloc(old_son->key, sizeof(int) * old_son->n);
    if (!old_son->leaf)
    {
        old_son->children = (pNode *)realloc(old_son->children,
                                             sizeof(pNode) * (old_son->n + 1));
    }
}

void B_Tree_Insert(pNode &root, int k)
{
    // root is full, split before do anything
    // only change root 1 time when root is full
    pNode r = root;
    if (r->n == 2 * T_MIN_DEGREE - 1)
    {
        pNode s = new Node;
        root = s;
        s->leaf = false;
        s->n = 0;
        s->key = NULL;
        s->children = (pNode *)malloc(sizeof(pNode) * (1));
        s->children[0] = r;
        B_Tree_Split_Child(s, 0);
        B_Tree_Insert_NonFull(s, k);
    }
    else
    {
        B_Tree_Insert_NonFull(r, k);
    }
}

void B_Tree_Insert_NonFull(pNode &x, int k)
{
    int i = x->n - 1;
    // Chi chen vao nut la
    if (x->leaf)
    {
        x->key = (int *)realloc(x->key, sizeof(int) * (x->n + 1));
        // Giong insertion sort
        while (i >= 0 && k < x->key[i])
        {
            x->key[i + 1] = x->key[i];
            --i;
        }
        x->key[i + 1] = k;
        ++x->n;
    }
    else
    {
        // child ith la con can chen vao
        while (i >= 0 && k < x->key[i])
        {
            --i;
        }
        ++i;
        // children ith is full
        if (x->children[i]->n == 2 * T_MIN_DEGREE - 1)
        {
            B_Tree_Split_Child(x, i);
            // x now have 2 children, which child we should insert k?
            // key:          i
            // children:    i i+1
            if (x->key[i] < k)
            {
                ++i;
            }
        }
        B_Tree_Insert_NonFull(x->children[i], k);
    }
}