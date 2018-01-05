#ifndef RAPCAOCAP_H
#define RAPCAOCAP_H

#include "RapThuong.h"

enum weekday { cnhat = 1, hai = 2, ba = 3, tu = 4, nam = 5, sau = 6, bay = 7 };

class RapCaoCap : public RapThuong
{
      private:
	weekday m_thu; // thu 2, 3 ..
      public:
	static float VE_VIP_TT;

	RapCaoCap(int M, int N) : RapThuong(M, N), m_thu(cnhat)
	{
	}
	RapCaoCap(int M, int N, weekday thu) : RapThuong(M, N), m_thu(thu)
	{
	}

	bool conTrong(ViTri vt);
	float giaVe(ViTri vt, bool &hopLe, float giaGoc);
	bool datVe(ViTri vt);
	float tongTien(float giaGoc);
};

#endif
