#include "Sap.h"

// Sap (base class)
float SAP::DON_GIA = 40000; // 40 trieu

istream &operator>>(istream &in, SAP &sap)
{
	cout << "Nhap thu tu, dien tich, doanh thu: ";
	in >> sap.mThuTu >> sap.mDienTich >> sap.mDoanhThu;
	return in;
}

ostream &operator<<(ostream &out, const SAP &sap)
{
	out << "Thu tu: " << sap.mThuTu << endl;
	out << "Dien tich: " << sap.mDienTich << endl;
	out << "Doanh thu: " << sap.mDoanhThu << endl;
	out << "Tien cuoi nam: " << sap.tienCuoiNam() << "kVND" << endl;
	return out;
}

// derived class
const float SThucPham::THUE_THUC_PHAM = 0.05;
const float SQuanAo::THUE_QUAN_AO = 0.1;
const float STrangSuc::THUE_TRANG_SUC_Small = 0.2;
const float STrangSuc::THUE_TRANG_SUC_Big = 0.3;
