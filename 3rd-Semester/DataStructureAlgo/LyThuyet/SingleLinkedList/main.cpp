#include "SlinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    ref head = NULL;
    ref tail = NULL;

    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i)
    {
        addHead(head, tail, arr[i]);
    }

    delNode(head, tail, head->next->next->next);

    priList(head);
    cout << tail->key << endl;

    delList(head, tail);

    return 0;
}
