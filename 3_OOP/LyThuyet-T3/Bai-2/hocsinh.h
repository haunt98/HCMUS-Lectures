#ifndef HOCSINH_H
#define HOCSINH_H

class HocSinh
{
      private:
	char *m_ten;
	double m_van, m_toan;

      public:
	void xuat();
	HocSinh(char *ten, double van, double toan);
	HocSinh(char *ten);
	HocSinh(const HocSinh &hs);
	~HocSinh();
};

#endif
