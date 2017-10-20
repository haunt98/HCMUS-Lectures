#ifndef DOCGIAVIP_H
#define DOCGIAVIP_H

#include "DocGia.h"

class DocGiaVip : public DocGia
{
public:
    DocGiaVip() : DocGia() {}
    DocGiaVip(const char *maDocGia, const char *hoTen, Date ngayHetHan,
              int gioiTinh)
        : DocGia(maDocGia, hoTen, ngayHetHan, gioiTinh)
    {
    }
    DocGiaVip(const DocGiaVip &dgv) : DocGia(dgv) {}
    DocGiaVip(const char *maDocGia) : DocGia(maDocGia) {}
    DocGiaVip(const char *maDocGia, const char *hoTen) : DocGia(maDocGia, hoTen)
    {
    }
    void nhap();
    void xuat();
    int lePhi();
};

#endif