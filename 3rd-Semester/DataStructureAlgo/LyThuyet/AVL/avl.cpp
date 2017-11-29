#include "avl.h"
#include <iostream>

using namespace std;

// Co 4 truong hop
// TH1: left left -> quay phai
//    P
//   / \
//  P1    -> P1
// / \      / \
//    T        P
//            / \
//           T
//
// TH2: right right -> quay trai
//   P
//  / \          
//    P1    -> P1
//   /  \     /  \
//  T         P
//           / \
//              T
//
// TH3: left right -> quay trai, quay phai
//    P           P
//   / \         / \
//  P1     ->   P2     ->   P2
// /  \        / \         /   \
//     P2     P1  T       P1    P
//    / \    / \         /  \  / \ 
//   Q   T      Q           Q T
//
// TH4: right left -> quay phai, quay trai
//    P            P
//  /   \        /   \
//      P1    ->     P2     ->    P2
//     /  \         /  \         /  \
//    P2           Q    P1      P   P1
//   /  \              /       / \   /
//  Q    T            T           Q T

void findAdd(pNode &root, int k)
{
    ;
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
