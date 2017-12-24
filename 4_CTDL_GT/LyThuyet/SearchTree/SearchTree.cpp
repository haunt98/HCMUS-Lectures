#include "SearchTree.h"

#include <iostream>

using namespace std;

pNode getNode(int k)
{
    pNode temp = new Node;
    if (!temp)
    {
        cout << "Can't make node" << endl;
    }
    temp->key = k;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}

pNode search(pNode root, int k)
{
    if (!root)
    {
        return NULL;
    }
    if (root->key)
    {
        return root;
    }

    // recursive
    if (root->key > k)
    {
        return search(root->pLeft, k);
    }
    return search(root->pRight, k);
}

pNode searchNonRecur(pNode root, int k)
{
    if (!root)
    {
        return NULL;
    }
    pNode p = root;
    while (p && p->key != k)
    {
        if (p->key > k)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }
    return p;
}

void findAdd(pNode &root, int k)
{
    // Su dung p1 va p2 chay noi tiep nhau
    // vi co 2 nhanh nen phai can than
    pNode p1 = getNode(-1);
    pNode prevRoot = p1;
    p1->pRight = root;
    pNode p2 = root;
    int d = 1; // move right

    // Di chuyen p1 va p2 den khi p2 la nut moi
    while (p2 && d)
    {
        // Di chuyen ve ben phai
        if (p2->key < k)
        {
            p1 = p2;
            p2 = p2->pRight;
            d = 1;
        }
        // Di chuyen ve ben trai
        else if (p2->key > k)
        {
            p1 = p2;
            p2 = p2->pLeft;
            d = -1;
        }

        // Da co trong search tree
        else
        {
            d = 0;
        }
    }
    if (d == 0)
    {
        cout << "Da co " << k << " trong search tree, khong them lai" << endl;
    }
    else
    {
        // Them p2, link p1 voi p2 theo d
        p2 = getNode(k);
        if (d == 1)
        {
            p1->pRight = p2;
        }
        else if (d == -1)
        {
            p1->pLeft = p2;
        }
    }
    root = prevRoot->pRight;
    delete prevRoot;
}

// Tim vi tri can xoa de xoa
void findDel(pNode &root, int k)
{
    if (!root)
    {
        return;
    }
    if (root->key > k)
    {
        findDel(root->pLeft, k);
    }
    else if (root->key < k)
    {
        findDel(root->pRight, k);
    }
    // Xoa tai vi tri nay
    else
    {
        pNode q = root; // Nut can xoa
        if (!q->pLeft)
        {
            root = q->pRight;
        }
        else if (!q->pRight)
        {
            root = q->pLeft;
        }
        else
        {
            // Thay root boi nut phai nhat ben trai
            // (Nut lon nhat ben trai)
            del(root->pLeft, q);
        }
        delete q;
    }
}

// Thay q boi nut phai nhat ben trai
void del(pNode &root, pNode &q)
{
    // Di toi nut phai nhat ben trai
    if (root->pRight)
    {
        del(root->pRight, q);
    }
    else
    {
        q->key = root->key;
        // Chuyen q ve nu phai nhat ben trai
        // de xoa q sau do
        q = root;
        root = root->pLeft;
    }
}

void printTree(pNode root, int indent)
{
    if (root)
    {
        // print in preorder
        for (int i = 0; i < indent; ++i)
        {
            cout << ' ';
        }
        cout << root->key << endl;

        printTree(root->pLeft, indent + 4);
        printTree(root->pRight, indent + 4);
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

void delTree(pNode &root)
{
    if (root)
    {
        delTree(root->pLeft);
        delTree(root->pRight);
        delete root;
    }
}