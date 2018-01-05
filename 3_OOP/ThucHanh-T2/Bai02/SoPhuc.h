#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc
{
      private:
	int m_thuc, m_ao;

      public:
	SoPhuc();
	SoPhuc(int thuc);
	SoPhuc(int thuc, int ao);
	SoPhuc(const SoPhuc &p);
	void Xuat();
	//~SoPhuc();
};

#endif