#ifndef _BENH_VIEN_H
#define _BENH_VIEN_H

#include "BenhNhan.h"
#include <vector>

using namespace std;

class BenhVien
{
      private:
	vector<BenhNhan *> m_ds;
	int m_slNgoaiTru;
	int m_slNoiTru;

      public:
	BenhVien();
	void doc(const string &FileName);
	~BenhVien();
	void themBN(BenhNhan *bn);
	void outMoney();
	int slNgoaiTru();
	int slNoiTru();
};

#endif