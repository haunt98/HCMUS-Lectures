#define _CRT_SECURE_NO_WARNINGS
#include "DocGia.h"
#include <string.h>

#define MAX 1000

DocGia::DocGia()
{
	m_maDocGia = new char[1];
	m_maDocGia[0] = '\0';

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_ngayHetHan = Date(1, 1, 2018);
	m_gioiTinh = 0; // mac dinh la nam
}

DocGia::DocGia(const char *maDocGia, const char *hoTen, Date ngayHetHan,
	       int gioiTinh)
{
	m_maDocGia = new char[strlen(maDocGia) + 1];
	strcpy(m_maDocGia, maDocGia);

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_ngayHetHan = ngayHetHan;
	m_gioiTinh = gioiTinh == 0 || gioiTinh == 1 ? gioiTinh : 0;
}

DocGia::DocGia(const DocGia &dg)
{
	m_maDocGia = new char[strlen(dg.m_maDocGia) + 1];
	strcpy(m_maDocGia, dg.m_maDocGia);

	m_hoTen = new char[strlen(dg.m_hoTen) + 1];
	strcpy(m_hoTen, dg.m_hoTen);

	m_ngayHetHan = dg.m_ngayHetHan;
	m_gioiTinh = dg.m_gioiTinh;
}

DocGia::DocGia(const char *maDocGia)
{
	m_maDocGia = new char[strlen(maDocGia) + 1];
	strcpy(m_maDocGia, maDocGia);

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_ngayHetHan = Date(1, 1, 2018);
	m_gioiTinh = 0; // mac dinh la nam
}

DocGia::DocGia(const char *maDocGia, const char *hoTen)
{
	m_maDocGia = new char[strlen(maDocGia) + 1];
	strcpy(m_maDocGia, maDocGia);

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_ngayHetHan = Date(1, 1, 2018);
	m_gioiTinh = 0; // mac dinh la nam
}

DocGia &DocGia::operator=(const DocGia &dg)
{
	delete[] m_maDocGia;
	m_maDocGia = new char[strlen(dg.m_maDocGia) + 1];
	strcpy(m_maDocGia, dg.m_maDocGia);

	delete[] m_hoTen;
	m_hoTen = new char[strlen(dg.m_hoTen) + 1];
	strcpy(m_hoTen, dg.m_hoTen);

	m_ngayHetHan = dg.m_ngayHetHan;
	m_gioiTinh = dg.m_gioiTinh;
	return *this;
}

DocGia::~DocGia()
{
	delete[] m_maDocGia;
	delete[] m_hoTen;
}

void DocGia::nhap()
{
	cout << "Nhap ma doc gia: ";
	char maDocGia[MAX];
	gets(maDocGia);
	delete[] m_maDocGia;
	m_maDocGia = new char[strlen(maDocGia) + 1];
	strcpy(m_maDocGia, maDocGia);

	cout << "Nhap ho ten: ";
	char hoTen[MAX];
	gets(hoTen);
	delete[] m_hoTen;
	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	cout << "Nhap ngay het han: ";
	cin >> m_ngayHetHan;
	getchar();

	cout << "0 - Nam, 1 - Nu: ";
	do {
		cin >> m_gioiTinh;
	} while (m_gioiTinh != 0 && m_gioiTinh != 1);
}

void DocGia::xuat()
{
	cout << "Ma doc gia: " << m_maDocGia << endl;
	cout << "Ho ten: " << m_hoTen << endl;
	cout << "Ngay het han: " << m_ngayHetHan << endl;

	cout << "Gioi tinh: ";
	if (m_gioiTinh == 0)
		cout << "nam" << endl;
	else
		cout << "nu" << endl;
}