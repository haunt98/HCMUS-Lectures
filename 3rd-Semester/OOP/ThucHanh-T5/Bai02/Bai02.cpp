// 1612180
// Nguyen Tran Hau
// Bai 2

#include "DocGia.h"
#include "DocGiaThuong.h"
#include "DocGiaVIP.h"

int DocGia::TIEN_SACH = 5000;
int DocGia::PHI_VIP = 50000;

int main()
{
    DocGia a("abc", "tieu phi");
    a.xuat();

    DocGiaThuong b;
    b.nhap();
    b.xuat();

    DocGiaVip c("def", "hau");
    c.xuat();
    return 0;
}