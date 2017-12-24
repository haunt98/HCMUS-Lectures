// The perfect balanced tree
// Definition of perfect balanced tree:
// - Left subtree and right substree is balanced (recursive)
// - The *number of node* of left subtree and right subtrue is at most 1

#include "balance.h"
#include <iostream>

using namespace std;

int main()
{
    int n = 3;

    pNode root = balancedTree(n);
    printTree(root, 0);

    postorder(root);
    cout << endl;

    postorderStack(root);
    cout << endl;

    delTree(root);

    return 0;
}