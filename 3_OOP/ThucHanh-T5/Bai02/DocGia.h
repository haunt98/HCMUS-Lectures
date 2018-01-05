#ifndef DOCGIA_H
#define DOCGIA_H

#include "Date.h"

class DocGia
{
      private:
	char *m_maDocGia;
	char *m_hoTen;
	Date m_ngayHetHan;
	int m_gioiTinh; // 0 - nam, 1 - nu

      public:
	DocGia();
	DocGia(const char *maDocGia, const char *hoTen, Date ngayHetHan,
	       int gioiTinh);
	DocGia(const DocGia &dg);
	DocGia(const char *maDocGia);
	DocGia(const char *maDocGia, const char *hoTen);
	DocGia &operator=(const DocGia &dg);
	~DocGia();

	void nhap();
	void xuat();
	static int TIEN_SACH;
	static int PHI_VIP;
	int lePhi();
};

#endif