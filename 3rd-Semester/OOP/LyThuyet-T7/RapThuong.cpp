#include "RapThuong.h"

RapThuong::RapThuong()
{
    m_M = 0;
    m_N = 0;
}

RapThuong::RapThuong(int M, int N)
{
    m_M = M > 0 ? M : 1;
    m_N = N > 0 ? M : 1;
    m_arr = new bool *[m_M];
    for (int i = 0; i < m_M; ++i)
    {
        m_arr[i] = new bool[m_N];
        for (int j = 0; j < m_N; ++j)
        {
            m_arr[i][j] = true; // con cho trong
        }
    }
}

RapThuong::RapThuong(const RapThuong &rap)
{
    m_M = rap.m_M;
    m_N = rap.m_N;
    m_arr = new bool *[m_M];
    for (int i = 0; i < m_M; ++i)
    {
        m_arr[i] = new bool[m_N];
        for (int j = 0; j < m_N; ++j)
        {
            m_arr[i][j] = rap.m_arr[i][j];
        }
    }
}

RapThuong &RapThuong::operator=(const RapThuong &rap)
{
    for (int i = 0; i < m_M; ++i)
    {
        delete[] m_arr[i];
    }
    delete[] m_arr;

    m_M = rap.m_M;
    m_N = rap.m_N;
    m_arr = new bool *[m_M];
    for (int i = 0; i < m_M; ++i)
    {
        m_arr[i] = new bool[m_N];
        for (int j = 0; j < m_N; ++j)
        {
            m_arr[i][j] = rap.m_arr[i][j];
        }
    }

    return *this;
}

RapThuong::~RapThuong()
{
    for (int i = 0; i < m_M; ++i)
    {
        delete[] m_arr[i];
    }
    delete[] m_arr;
}

bool RapThuong::conTrong(ViTri vt)
{
    if (vt.i < 0 || vt.i >= m_M || vt.j < 0 || vt.j >= m_N)
    {
        return false; // cho ngoi khong hop le
    }
    return m_arr[vt.i][vt.j];
}

float RapThuong::giaVe(ViTri vt, bool &hopLe, float giaGoc)
{
    if (vt.i < 0 || vt.i >= m_M || vt.j < 0 || vt.j >= m_N)
    {
        hopLe = false; // cho ngoi khong hop le
    }
    else
        hopLe = true;
    // kcach -> hang trung tam
    int kcach = m_M / 2 > vt.i ? m_M / 2 - vt.i : vt.i - m_M / 2;
    return giaGoc - VE_GIAM * kcach;
}

bool RapThuong::datVe(ViTri vt)
{
    if (vt.i < 0 || vt.i >= m_M || vt.j < 0 || vt.j >= m_N)
        return false;              // cho ngoi khong hop le
    if (m_arr[vt.i][vt.j] == true) // con cho trong
    {
        m_arr[vt.i][vt.j] = false;
        return true; // dat cho thanh cong
    }
    return false; // cho da co nguoi khac dat
}

float RapThuong::tongTien(float giaGoc)
{
    float tong = 0;
    for (int i = 0; i < m_M; ++i)
    {
        for (int j = 0; j < m_N; ++j)
        {
            if (m_arr[i][j] == false) // ve da duoc ban
            {
                bool flag;
                tong += giaVe(ViTri{i, j}, flag, giaGoc);
            }
        }
    }
    return tong;
}
