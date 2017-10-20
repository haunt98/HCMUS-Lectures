#include "RapCaoCap.h"

bool RapCaoCap::conTrong(ViTri vt)
{
    return RapThuong::conTrong(vt);
}

float RapCaoCap::giaVe(ViTri vt, bool &hopLe, float giaGoc)
{
    float temp = RapThuong::giaVe(vt, hopLe, giaGoc);
    if (m_thu == nam)
        return temp * 0.8; // giam 20% thu nam
    return temp;
}

bool RapCaoCap::datVe(ViTri vt)
{
    return RapThuong::datVe(vt);
}

float RapCaoCap::tongTien(float giaGoc)
{
    float temp = RapThuong::tongTien(giaGoc);
    if (m_thu == nam)
        return temp * 0.8;
    return temp;
}
