#ifndef MANGDUONGTRON_H
#define MANGDUONGTRON_H

class DuongTron;

class MangDuongTron
{
      private:
	DuongTron *m_arr;
	int m_size;

      public:
	void nhap();
	void xuat();
	~MangDuongTron();
	bool nhohon(double a, double b);
	bool lonhon(double a, double b);
	DuongTron tim(double (DuongTron::*giatri)(),
		      bool (MangDuongTron::*sosanh)(double, double));
	void sapxep(double (DuongTron::*giatri)(),
		    bool (MangDuongTron::*sosanh)(double, double));
};

#endif