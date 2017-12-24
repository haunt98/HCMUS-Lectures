// 1612180
// Nguyen Tran Hau
// Bai 1

#include "CongTy.h"
#include <iostream>

using namespace std;

float NhanVien::MONEY_PER_OBJ = 20;
float NhanVien::MONEY_PER_DAY = 300;

int main()
{
    CongTy ct;
    ct.nhap();
    ct.xuat();

    cout << "Tong luong: " << ct.tongLuong() << "k" << endl;
    cout << "Luong trung binh: " << ct.tbLuong() << "k" << endl;
    cout << "Nhan vien co luong cao nhat\n";
    if (ct.nvLuongCaoNhat())
        ct.nvLuongCaoNhat()->xuat();
    cout << "Cac nhan vien co luong thap hon 3000000" << endl;
    ct.lietkeLuongThapHon(3000); // vi k = 1000

    cout << "So luong nhan vien san xuat: " << ct.slNVSanXuat() << endl;
    cout << "So luong nhan vien cong nhat: " << ct.slNVCongNhat() << endl;

    cout << "Nhap ma nhan vien can tim: ";
    string maNV;
    getline(cin >> ws, maNV);
    if (ct.timMaNV(maNV))
    {
        cout << "Nhan vien co ma nhan vien: " << maNV << endl;
        ct.timMaNV(maNV)->xuat();
    }
    else
    {
        cout << "Khong tim thay ma nhan vien" << endl;
    }

    cout << "Nhap ten nhan vien can tim: ";
    string ten;
    getline(cin >> ws, ten);
    if (ct.timTen(ten))
    {
        cout << "Nhan vien co ten: " << ten << endl;
        ct.timTen(ten)->xuat();
    }
    else
    {
        cout << "Khong tim thay ten nhan vien" << endl;
    }

    cout << "Cac nhan vien sinh thang 5" << endl;
    ct.lietkeSinhThang(5);

    return 0;
}