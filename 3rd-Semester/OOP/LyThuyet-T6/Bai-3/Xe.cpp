#include "Xe.h"

// Xe
Xe::Xe(double tocdoXang0Tai, double tocdoXangHH)
{
    m_xang = 0;
    m_duong = 0;
    m_hang = 0;
    m_tocdoXang0Tai = tocdoXang0Tai;
    m_tocdoXangHH = tocdoXangHH;
    m_xangTieuThu = m_tocdoXang0Tai * m_duong + m_tocdoXangHH * m_hang;
}

void Xe::themHang(double hang)
{
    m_hang += hang;
    m_xangTieuThu += m_tocdoXangHH * hang;
}

void Xe::botHang(double hang)
{
    hang = hang <= m_hang ? hang : m_hang;
    themHang(-hang);
}

void Xe::themXang(double xang)
{
    m_xang += xang;
}

void Xe::chay(double duong)
{
    m_duong += duong;
    m_xangTieuThu += m_tocdoXang0Tai * duong;
    m_xang -= m_xangTieuThu;
}

bool Xe::hetXang()
{
    return m_xang <= 0;
}

double Xe::xang()
{
    return m_xang;
}
