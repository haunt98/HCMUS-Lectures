#include "Circular.h"
#include <iostream>

using namespace std;

// N people, Mth person be killed
// 5 people: 1 2 3 4 5
// if M = 2, 2 4 1 5 be killed
void josephus(int N, int M);

int main()
{
    josephus(41, 3);
    return 0;
}

void josephus(int N, int M)
{
    CList l;
    initCList(l);
    for (int i = 1; i <= N; ++i)
    {
        addTail(l, i);
    }

    // To keep track how many people live so far
    int count = N;

    pCNode p = l.pHead;
    // Khi p = p->pNext, nghia la chi con 1 nguoi song sot
    while (p != p->pNext)
    {
        pCNode temp = p;
        for (int i = 0; i < M - 2; ++i)
        {
            temp = temp->pNext;
        }
        removeAfter(l, temp);
        p = temp->pNext;
        --count;
        // Khong co nguoi thu N tiep theo
        if (count < M)
        {
            printList(l);
            break;
        }
    }
    delList(l);
}