#include "DocGiaThuong.h"

void DocGiaThuong::nhap()
{
    DocGia::nhap();
    cout << "Nhap so sach muon trong thang: ";
    do
    {
        cin >> m_soSachMuon;
    } while (m_soSachMuon < 0);
}

void DocGiaThuong::xuat()
{
    DocGia::xuat();
    cout << "So sach muon trong thang: " << m_soSachMuon << endl;
    cout << "Le phi: " << lePhi() << endl;
}

int DocGiaThuong::lePhi()
{
    return m_soSachMuon * DocGia::TIEN_SACH;
}