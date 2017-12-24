// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "SortTopology.h"
#include <iostream>

using namespace std;

int main()
{
    lref head = new leader; // Khong can tao gia tri head tro toi
    lref tail = head;
    int z = 0; // Bien dem so leader nhap vao
    lref p, q;
    tref t;

    // INPUT
    // x truoc y
    int x, y;
    cin >> x;
    while (x) // Dung khi x = 0
    {
        cin >> y;

        // Lay vi tri leader cua x, y
        p = addList(head, tail, x, z);
        q = addList(head, tail, y, z);

        t = new trailer; // t cua p tro den q
        t->id = q;
        t->next = p->trail; // Chen t vao nut dau tien cua p->trail
        p->trail = t;
        ++(q->count); // Them mot phan tu (p) dung truoc q

        cin >> x;
    }

    printList(head, tail);

    // SORT
    // Tao list moi la nhung phan tu khong co dung truoc (count = 0)
    // Luon ton tai phan tu khong co ai dung truoc,
    // vi neu khong ton tai -> loop
    p = head;
    head = NULL;      // head moi luu list theo thu tu topo
    while (p != tail) // p chay tu head cu -> tail
    {
        // Xu ly p bang bien tam q, sau do di chuyen p
        q = p;
        p = p->next;

        // Add head nhung phan tu co count = 0
        // la nhung phan tu khong co dung truoc
        if (q->count == 0)
        {
            q->next = head;
            head = q;
        }
    }
    // Ket thuc, p tro thanh tail, q truoc tail (da thay doi next)
    // q->next co the la tail, co the la thuoc head moi

    // Xu ly list vua tao bang trail cua cac phan tu
    // Sau khi dua het trail cua phan tu dau tien vao
    // trail tro thanh leader va xu ly tiep
    q = head;
    while (q)
    {
        // In ra theo thu tu
        cout << q->key << " ";
        --z;

        // Duyet toan bo leader *sau* q
        t = q->trail;
        while (t)
        {
            p = t->id;
            // Giam p->count vi da lay q ra roi (q *truoc* p)
            --(p->count);
            // Neu p khong con phan tu dung *truoc*,
            // dua no vao sau q
            if (p->count == 0)
            {
                p->next = q->next;
                q->next = p;
            }
            t = t->next;
        }
        q = q->next;
    }

    delList(head, tail);

    if (z == 0)
    {
        cout << "Hurray" << endl;
    }
    return 0;
}