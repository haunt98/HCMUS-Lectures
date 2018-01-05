#ifndef XE_H
#define XE_H

class Xe
{
      private:
	double m_xang;		// xang tren xe
	double m_duong;		// quang duong
	double m_hang;		// hang hoa
	double m_tocdoXang0Tai; // luong xang tieu thu 1km khong tai
	double m_tocdoXangHH;   // luong xang tieu thu 1kg hang hoa tren 1km
	double m_xangTieuThu;   // tong luong tieu thu cua xang
      public:
	Xe(double tocdoXang0Tai, double tocdoXangHH);
	void themHang(double hang); // them mot luong hang
	void botHang(double hang);  // bot mot luong hang
	void themXang(double xang);
	void chay(double duong); // di mot doan duong
	bool hetXang();
	double xang(); // luong xang con
};

class XeMay : public Xe
{
      private:
      public:
	XeMay() : Xe(0.02, 0.01)
	{
	}
};

class XeTai : public Xe
{
      private:
      public:
	XeTai() : Xe(0.2, 0.001)
	{
	}
};

#endif
