#include "DocGiaVIP.h"

void DocGiaVip::nhap()
{
    DocGia::nhap();
}

void DocGiaVip::xuat()
{
    DocGia::xuat();
    cout << "Le phi: " << lePhi() << endl;
}

int DocGiaVip::lePhi()
{
    return DocGia::PHI_VIP;
}