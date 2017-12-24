// 1612180
// Nguyen Tran Hau
// Bai02

#include "Diem.h"
#include "MangTamGiac.h"
#include "TamGiac.h"
#include <iostream>

using namespace std;

// ham de test cac chuc nang trong class
void testDiem();
void testTamGiac();
void testMangTamGiac();

int main()
{
    int temp;
    cout << "1 - Diem, 2 - Tam giac, 3 - Mang tam giac : ";
    cin >> temp;
    switch (temp)
    {
    case 1:
        testDiem();
        break;
    case 2:
        testTamGiac();
        break;
    case 3:
        testMangTamGiac();
        break;
    default:
        cout << "Chon 1,2 hoac 3" << endl;
        break;
    }
    return 0;
}

void testDiem()
{
    cout << "TEST CLASS DIEM" << endl;
    Diem A, B;
    A.nhap();
    A.xuat();
    cout << endl;
    B.nhap();
    B.xuat();
    cout << endl;
    cout << "Khoang cach cua 2 diem : " << A.khoangcach(B) << endl;
}

void testTamGiac()
{
    cout << "TEST CLASS TAM GIAC" << endl;
    TamGiac tg;
    tg.nhap();
    tg.xuat();
    tg.loai();
    cout << "Chu vi : " << tg.chuvi() << endl;
    cout << "Dien tich : " << tg.dientich() << endl;
    tg.xoa();
}

void testMangTamGiac()
{
    cout << "TEST CLASS MANG TAM GIAC" << endl;
    MangTamGiac mtg;
    mtg.nhap();
    mtg.xuat();

    cout << "Cac tam giac deu : " << endl;
    mtg.lietke(&TamGiac::laTamGiacDeu);
    cout << "Cac tam giac vuong can : " << endl;
    mtg.lietke(&TamGiac::laTamGiacVuongCan);
    cout << "Cac tam giac vuong : " << endl;
    mtg.lietke(&TamGiac::laTamGiacVuong);
    cout << "Cac tam giac can : " << endl;
    mtg.lietke(&TamGiac::laTamGiacCan);

    cout << "Tam giac co chu vi nho nhat : " << endl;
    mtg.tim(&TamGiac::chuvi, &MangTamGiac::nhohon).xuat();
    cout << "Tam giac co chu vi lon nhat : " << endl;
    mtg.tim(&TamGiac::chuvi, &MangTamGiac::lonhon).xuat();
    cout << "Tam giac co dien tich nho nhat : " << endl;
    mtg.tim(&TamGiac::dientich, &MangTamGiac::nhohon).xuat();
    cout << "Tam giac co dien tich lon nhat : " << endl;
    mtg.tim(&TamGiac::dientich, &MangTamGiac::lonhon).xuat();

    cout << "Sap xep tam giac tang dan theo chu vi : " << endl;
    mtg.sapxep(&TamGiac::chuvi, &MangTamGiac::nhohon);
    mtg.xuat();
    cout << "Sap xep tam giac giam dan theo dien tich : " << endl;
    mtg.sapxep(&TamGiac::dientich, &MangTamGiac::lonhon);
    mtg.xuat();
    mtg.xoa();
}