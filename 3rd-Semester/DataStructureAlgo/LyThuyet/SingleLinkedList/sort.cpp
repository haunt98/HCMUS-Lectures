#include "sort.h"
#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(ref_n low, ref_n high)
{
    if (!low || low == high)
        return;
    ref_n i = low;
    for (ref_n j = low->next; j != high->next; j = j->next)
    {
        if (j->key < low->key)
        {
            i = i->next;
            swap(j->key, i->key);
        }
    }
    swap(i->key, low->key);

    quickSort(low, i);
    quickSort(i->next, high);
}
