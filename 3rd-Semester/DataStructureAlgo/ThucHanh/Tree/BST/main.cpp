// Binary Search Tree
// All the nodes in left subtree < root < in right
#include "bst.h"
#include <iostream>

using namespace std;

int main()
{
    pNode root = NULL;
    insertionRecursive(root, NULL, 9);
    insertionRecursive(root, NULL, 3);
    insertionRecursive(root, NULL, 4);
    insertionRecursive(root, NULL, 5);
    insertionRecursive(root, NULL, 11);
    insertionRecursive(root, NULL, 13);
    insertionRecursive(root, NULL, 12);
    insertionRecursive(root, NULL, 5);
    insertionRecursive(root, NULL, 14);
    insertionRecursive(root, NULL, 10);
    printPreOrder(root, 0);

    deletionPre(root, 13);
    printPreOrder(root, 0);

    delPostOder(root);
    return 0;
}
