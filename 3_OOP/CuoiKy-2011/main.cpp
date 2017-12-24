#include "MayLoc.h"
#include <iostream>

using namespace std;

int main()
{
    // Bai 1
    MayLoc *pm = new MayLoc();
    delete pm;
    {
        MayLyTam m1(81.9, 10);
        pm = &m1;
        cout << "Luong nuoc = " << pm->tinhLuongNuoc() << endl;
    }
    // Bai 2
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap();
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;
    return 0;
}
