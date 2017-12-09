// Red-black tree is a bst tree with one extra bit: color
// 1. Every node is either red or black
// 2. Root is black
// 3. Leaf (NULL) is black
// 4. If a node is red, both children are black
// 5. For each node, all simple path from the node to descendant leaves
// contain the same number of black nodes
// Single sentinel to represent NULL, its color: black
#include "redblack.h"
#include <iostream>

using namespace std;

int main()
{
    Tree T;
    rbInsert(T, 1);
    rbInsert(T, 2);
    rbInsert(T, 3);
    rbInsert(T, 4);
    rbInsert(T, 5);
    rbInsert(T, 6);
    rbInsert(T, 7);
    rbInsert(T, 8);
    printPreOrder(T.root, T.NIL, 0);

    rbDelete(T, 2);
    printPreOrder(T.root, T.NIL, 0);

    delPostOrder(T.root, T.NIL);
    delete T.NIL;
    return 0;
}