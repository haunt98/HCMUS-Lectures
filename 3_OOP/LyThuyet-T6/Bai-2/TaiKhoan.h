#ifndef TAIKHOAN_H
#define TAIKHOAN_H

class TaiKhoan
{
      private:
	float m_soDu;

      public:
	TaiKhoan() : m_soDu(0)
	{
	}
	float baoSoDu()
	{
		return m_soDu;
	}
	void napTien(float soTien)
	{
		m_soDu += soTien;
	}
	void rutTien(float soTien)
	{
		if (soTien <= m_soDu)
			m_soDu -= soTien;
	}
};

class TaiKhoanTietKiem : public TaiKhoan
{
      private:
	int m_kyHanGui; // gui may thang ?!
	float m_laiSuat;
	int m_thangDaGui; // so thang da gui
      public:
	TaiKhoanTietKiem()
	    : TaiKhoan(), m_kyHanGui(0), m_laiSuat(0.01), m_thangDaGui(0)
	{
	}
	float napTien(float soTien); // tra ve lai suat
	float rutTien(float soTien);
	void tangThangDaGui(int thang);
};

#endif
