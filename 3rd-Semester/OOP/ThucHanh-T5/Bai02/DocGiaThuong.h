#ifndef DOCGIATHUONG_H
#define DOCGIATHUONG_H

#include "DocGia.h"

class DocGiaThuong : public DocGia
{
private:
    int m_soSachMuon;

public:
    DocGiaThuong() : DocGia(), m_soSachMuon(0) {}
    DocGiaThuong(const char *maDocGia, const char *hoTen, Date ngayHetHan,
                 int gioiTinh, int soSachMuon)
        : DocGia(maDocGia, hoTen, ngayHetHan, gioiTinh),
          m_soSachMuon(soSachMuon)
    {
    }
    DocGiaThuong(const DocGiaThuong &dgt) : DocGia(dgt), m_soSachMuon(0) {}
    DocGiaThuong(const char *maDocGia) : DocGia(maDocGia), m_soSachMuon(0) {}
    DocGiaThuong(const char *maDocGia, const char *hoTen)
        : DocGia(maDocGia, hoTen), m_soSachMuon(0)
    {
    }

    void nhap();
    void xuat();
    int lePhi();
};

#endif