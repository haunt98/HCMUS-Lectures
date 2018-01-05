#ifndef RAPTHUONG_H
#define RAPTHUONG_H

struct ViTri {
	int i, j;
};

class RapThuong
{
      private:
	int m_M; // hang ghe
	int m_N; // so ghe moi hang
	bool **m_arr;

      public:
	// Gia ve hang ghe trung tam
	static float VE_GIAM;
	static float VE_THUONG_TT;

	RapThuong();
	RapThuong(int M, int N);
	RapThuong(const RapThuong &);
	RapThuong &operator=(const RapThuong &);
	~RapThuong();

	bool conTrong(ViTri vt);
	float giaVe(ViTri vt, bool &hopLe, float giaGoc);
	bool datVe(ViTri vt);
	float tongTien(float giaGoc);
};

#endif
