// Binary search tree
// Definition: *all* keys of left subtree < key of root < *all* keys of right
// subtree
// Example
//    7
//  /   \
// 3    13

#include "SearchTree.h"
#include <iostream>

using namespace std;

int main()
{
    pNode root = NULL;

    findAdd(root, 2);
    findAdd(root, 1);
    findAdd(root, 5);
    findAdd(root, 0);
    findAdd(root, 6);

    printTree(root, 0);

    findDel(root, 0);

    printTree(root, 0);

    delTree(root);
    return 0;
}