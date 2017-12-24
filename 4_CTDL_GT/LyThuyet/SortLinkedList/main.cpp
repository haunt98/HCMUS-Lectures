#include "sort.h"
#include <iostream>

using namespace std;

int main()
{
    List l;
    initList(l);
    randList(l, 10);

    cout << "Original list" << endl;
    printList(l);

    quickSort(l);
    cout << "After sort" << endl;
    printList(l);
    if (l.pTail)
        cout << "Tail: " << l.pTail->key << endl;
    delList(l);

    return 0;
}
