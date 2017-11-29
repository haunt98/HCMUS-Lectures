#include "sort.h"
#include <iostream>

using namespace std;

// Kiem tra sap xep thanh cong
bool isSort(List l)
{
    pNode temp = l.pHead;
    while (temp != l.pTail)
    {
        if (temp->key > temp->pNext->key)
        {
            return false;
        }
        temp = temp->pNext;
    }
    return true;
}

int maxList(List l)
{
    pNode max = l.pHead;
    pNode temp = l.pHead;
    while (temp != l.pTail)
    {
        if (temp->key > max->key)
        {
            max = temp;
        }
        temp = temp->pNext;
    }
    return max->key;
}

// Lay chu so thu k trong co so base
int getK(int n, int base, int k)
{
    for (int i = 1; i < k; ++i)
    {
        n /= base;
    }
    return n % base;
}

int soChuSo(int n, int base)
{
    int count = 0;
    while (n > 0)
    {
        n /= base;
        ++count;
    }
    return count;
}

// Sort theo co so MSD (theo so co gia tri lon nhat)
// vi du 001, 020, 123 ,102 la sap xep tu hang tram -> chuc -> don vi
// thuc hien voi chu so thu k (tu phai qua)
void radixListK(List &l, int base, int k)
{
    if (l.pHead == l.pTail || k < 1)
    {
        return;
    }

    // Tao mang count, dac trung cua radix
    List *count = new List[base];
    for (int i = 0; i < base; ++i)
    {
        initList(count[i]);
    }

    // Break the list
    pNode temp = l.pHead;
    while (temp != l.pTail->pNext)
    {
        // Lay p trong list ra,
        // dua vao count
        pNode p = temp;
        temp = temp->pNext;
        int i = getK(p->key, base, k);
        addTail(count[i], p);
    }

    // Recursive
    for (int i = 0; i < base; ++i)
    {
        radixListK(count[i], base, k - 1);
    }

    // Relink the list
    // Tim vi tri dat l.pHead
    int index;
    for (index = 0; index < base - 1; ++index)
    {
        if (!isEmptyList(count[index]))
        {
            l.pHead = count[index].pHead;
            break;
        }
    }
    for (; index < base - 1;)
    {
        int j;
        for (j = index + 1; j < base; ++j)
        {
            if (!isEmptyList(count[j]))
            {
                // Neu ton tai list tiep, link it!
                count[index].pTail->pNext = count[j].pHead;
                l.pTail = count[j].pTail;
                break;
            }
        }
        index = j;
    }

    delete[] count;
}

void radixList(List &l, int base)
{
    int k = soChuSo(maxList(l), base);
    radixListK(l, base, k);
}

void quickSortWithPrev(List &l, pNode prevHead)
{
    // Truong hop list rong, list co 1 phan tu
    // Truong hop neu pivot tra ve head hoac tail
    if (l.pHead == l.pTail || prevHead == l.pTail)
    {
        return;
    }

    // Chon pivot cuoi danh sach
    pNode prevPivot = prevHead;
    pNode pivot = l.pTail;

    // prev va cur chay song song
    pNode prev = prevHead;
    pNode cur = prev->pNext;
    while (cur != pivot)
    {
        if (cur->key > pivot->key)
        {
            // Move cur after pivot
            prev->pNext = cur->pNext;
            cur->pNext = pivot->pNext;
            pivot->pNext = cur;

            // Only update tail 1 time, when pivot is tail
            if (l.pTail == pivot)
            {
                l.pTail = cur;
            }

            cur = prev->pNext;
        }
        else
        {
            // Move prev and cur
            prev = cur;
            cur = cur->pNext;
            prevPivot = prev;
        }
    }
    l.pHead = prevHead->pNext; // Update head again

    // De quy, cho head..prevPivot va pivot->pNext..tail
    List lLeft;
    lLeft.pHead = l.pHead;
    lLeft.pTail = prevPivot;

    List lRight;
    lRight.pHead = pivot->pNext;
    lRight.pTail = l.pTail;

    quickSortWithPrev(lLeft, prevHead);
    quickSortWithPrev(lRight, pivot);

    // Cap nhap head va tail cua l theo lLeft va lRight
    // Vi khi chay de quy, l.pHead va l.pTail khong tu cap nhap
    l.pHead = lLeft.pHead;
    l.pTail = lRight.pTail;
}

void quickSort(List &l)
{
    pNode prevHead = getNode(-1);
    prevHead->pNext = l.pHead;
    quickSortWithPrev(l, prevHead);
    delete prevHead;
}