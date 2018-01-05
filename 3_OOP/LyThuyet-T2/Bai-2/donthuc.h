#ifndef DONTHUC_H
#define DONTHUC_H

class DonThuc
{
      private:
	float m_heso;
	int m_mu;

      public:
	void nhap();
	void xuat();
	float layHeso();
	int layMu();
	void ganHeso(float heso);
	void ganMu(int mu);
	DonThuc daoham();
	DonThuc cong(DonThuc p);
	DonThuc nhan(DonThuc p);
	int sosanh(DonThuc p);
};

#endif
