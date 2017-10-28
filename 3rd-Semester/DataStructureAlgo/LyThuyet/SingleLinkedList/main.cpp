#include "SlinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    ref head = NULL;
    ref tail = NULL;

    // int arr[] = {1};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < size; ++i)
    // {
    //     addHead(head, tail, arr[i]);
    // }

    priList(head);

    addNodeKeepOrder(head, tail, 7);
    addNodeKeepOrder(head, tail, 0);
    addNodeKeepOrder(head, tail, 3);
    priList(head);

    reverseList(head, tail);
    priList(head);
    cout << head->key << endl;
    cout << tail->key << endl;

    delList(head, tail);

    return 0;
}
