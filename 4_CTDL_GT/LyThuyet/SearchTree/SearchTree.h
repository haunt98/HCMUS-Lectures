#ifndef _SEARCH_TREE_H
#define _SEARCH_TREE_H

typedef struct Node *pNode;
struct Node
{
    int key;
    pNode pLeft;
    pNode pRight;
};

// Tim trong cay nhi phan tim kiem
pNode search(pNode root, int k);
pNode searchNonRecur(pNode root, int k);

// Tim vi tri can them de them
// vao cay tim kiem
void findAdd(pNode &root, int k);

// Tim vi tri can xoa de xoa
void findDel(pNode &root, int k);
// Thay q boi nut phai nhat ben trai
void del(pNode &root, pNode &q);

void printTree(pNode root, int indent);
void delTree(pNode &root);

#endif