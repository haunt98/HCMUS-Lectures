#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

void main()
{
    List l;

    // Khởi tạo dslk
    InitList(l);

    // Chèn nút có giá trị 8 vào đầu dslk
    Data info;
    info.x = 8;
    AddHead(l, info);
    PrintList(l, "Chen nut 8 vao dau:\t\t");

    // Chèn nút có giá trị 9 vào đầu dslk
    info.x = 9;
    Node *q = AddHead(l, info);
    PrintList(l, "Chen nut 9 vao dau:\t\t");

    // Chèn nút có giá trị 10 vào đầu dslk
    info.x = 10;
    AddHead(l, info);
    PrintList(l, "Chen nut 10 vao dau:\t\t");

    // Chèn nút có giá trị 999 vào cuối dslk
    info.x = 999;
    AddTail(l, info);
    PrintList(l, "Chen nut 999 vao cuoi:\t\t");

    // Chèn nút có giá trị 789 vào cuối dslk
    info.x = 789;
    AddTail(l, info);
    PrintList(l, "Chen nut 789 vao cuoi:\t\t");

    // Chèn nút có giá trị 111 vào sau nút q (nút có giá trị 9 ở trên)
    info.x = 111;
    AddAfter(l, q, info);
    PrintList(l, "Chen nut 111 vao sau nut 9:\t");

    // Chèn nút có giá trị 123 vào trước nút q (nút có giá trị 9 ở trên)
    info.x = 123;
    AddBefore(l, q, info);
    PrintList(l, "Chen nut 123 vao truoc nut 9:\t");

    // Xóa nút đầu tiên
    Node *p;
    p = RemoveHead(l);
    PrintList(l, "Xoa nut dau tien:\t\t");
    if (p != NULL)
    {
        cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
        delete p;
    }
    else
    {
        cout << "=> Xoa khong thanh cong!" << endl;
    }

    // Xóa nút cuối cùng
    p = RemoveTail(l);
    PrintList(l, "Xoa nut cuoi cung:\t\t");
    if (p != NULL)
    {
        cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
        delete p;
    }
    else
    {
        cout << "=> Xoa khong thanh cong!" << endl;
    }

    // Xóa nút sau nút q (nút có giá trị 9 ở trên)
    p = RemoveAfter(l, q);
    PrintList(l, "Xoa nut sau nut 9:\t\t");
    if (p != NULL)
    {
        cout << "=> Gia tri cua nut bi xoa:\t" << p->info.x << endl;
        delete p;
    }
    else
    {
        cout << "=> Xoa khong thanh cong!" << endl;
    }

    // Xóa nút có giá trị cho trước
    cout << "Nhap gia tri nut can xoa: ";
    cin >> info.x;
    p = RemoveNode(l, info);
    if (p != NULL)
    {
        PrintList(l, "=> Xoa thanh cong:\t\t");
        delete p;
    }
    else
        PrintList(l, "=> Xoa khong thanh cong:\t");

    // Xóa tất cả
    RemoveAll(l);
    PrintList(l, "Xoa toan bo danh sach lien ket!\n");

    // Chèn nút 6 vào mảng tăng dần
    info.x = 6;
    AddAscendingList(l, info);
    PrintList(l, "Chen nut 6 (sao cho tang dan):\t");

    // Chèn nút 8 vào mảng tăng dần
    info.x = 8;
    AddAscendingList(l, info);
    PrintList(l, "Chen nut 8 (sao cho tang dan):\t");

    // Chèn nút 7 vào mảng tăng dần
    info.x = 7;
    AddAscendingList(l, info);
    PrintList(l, "Chen nut 7 (sao cho tang dan):\t");

    // Chèn nút 5 vào mảng tăng dần
    info.x = 5;
    AddAscendingList(l, info);
    PrintList(l, "Chen nut 5 (sao cho tang dan):\t");

    // Chèn nút 9 vào mảng tăng dần
    info.x = 9;
    AddAscendingList(l, info);
    PrintList(l, "Chen nut 9 (sao cho tang dan):\t");

    RemoveAll(l);
    PrintList(l, "Xoa toan bo danh sach lien ket!\n");
}