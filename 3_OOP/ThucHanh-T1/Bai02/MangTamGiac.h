#ifndef MANGTAMGIAC_H
#define MANGTAMGIAC_H

class Diem;

class TamGiac;

class MangTamGiac
{
      private:
	TamGiac *m_arr;
	int m_size;
	void swap(TamGiac &, TamGiac &);

      public:
	void nhap();
	void xuat();
	void xoa();
	void lietke(bool (TamGiac::*dieukien)());
	bool nhohon(double, double);
	bool lonhon(double, double);
	TamGiac tim(double (TamGiac::*giatri)(),
		    bool (MangTamGiac::*thutu)(double, double));
	void sapxep(double (TamGiac::*giatri)(),
		    bool (MangTamGiac::*thutu)(double, double));
};

#endif