// 1612180
// Nguyen Tran Hau
// Bai03

#include "DuongTron.h"
#include "MangDuongTron.h"
#include <iostream>

using namespace std;

// ham test class duong tron va mang duong tron
void testDuongTron();
void testMangDuongTron();

int main()
{
    cout << "1 - test Duong tron, 2 - test Mang duong tron: ";
    int test;
    cin >> test;
    switch (test)
    {
    case 1:
        testDuongTron();
        break;
    case 2:
        testMangDuongTron();
        break;
    default:
        cout << "Press 1 - 2" << endl;
        break;
    }
    return 0;
}

void testDuongTron()
{
    DuongTron dt;
    dt.nhap();
    dt.xuat();
    cout << "Chu vi: " << dt.chuvi() << endl;
    cout << "Dien tich: " << dt.dientich() << endl;
}

void testMangDuongTron()
{
    MangDuongTron mdt;
    mdt.nhap();
    mdt.xuat();

    cout << "Duong tron co chu vi nho nhat: ";
    mdt.tim(&DuongTron::chuvi, &MangDuongTron::nhohon).xuat();
    cout << "Duong tron co chu vi lon nhat: ";
    mdt.tim(&DuongTron::chuvi, &MangDuongTron::lonhon).xuat();
    cout << "Duong tron co dien tich nho nhat: ";
    mdt.tim(&DuongTron::dientich, &MangDuongTron::nhohon).xuat();
    cout << "Duong tron co dien tich lon nhat: ";
    mdt.tim(&DuongTron::dientich, &MangDuongTron::lonhon).xuat();

    cout << "Sap xep cac duong tron tang dan theo chu vi: " << endl;
    mdt.sapxep(&DuongTron::chuvi, &MangDuongTron::nhohon);
    mdt.xuat();
    cout << "Sap xep cac duong tron giam dan theo dien tich: " << endl;
    mdt.sapxep(&DuongTron::dientich, &MangDuongTron::lonhon);
    mdt.xuat();
}