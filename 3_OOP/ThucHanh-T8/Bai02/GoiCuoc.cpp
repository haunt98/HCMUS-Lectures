#include "GoiCuoc.h"

// BASIC
// Khoi tao
GoiCuocBasic::GoiCuocBasic() : m_callTime(0), m_useNet(0)
{
}

GoiCuocBasic::GoiCuocBasic(int callTime, int useNet)
    : m_callTime(callTime), m_useNet(useNet)
{
}

GoiCuocBasic::GoiCuocBasic(const GoiCuocBasic &basic)
    : m_callTime(basic.m_callTime), m_useNet(basic.m_useNet)
{
}

// Goi cuoc
float GoiCuocBasic::cuocDienThoai()
{
	return m_callTime * GoiCuocBasic::MONEY_PER_MINUTE;
}

float GoiCuocBasic::cuocInternet()
{
	return m_useNet * GoiCuocBasic::MONEY_PER_MB;
}

float GoiCuocBasic::cuocTong()
{
	float tong = cuocDienThoai() + cuocInternet();
	return tong * 1.1; // Thue VAT 10%
}

GoiCuocBasic *GoiCuocBasic::clone() const
{
	return new GoiCuocBasic(*this);
}

// DATA FREE
GoiCuocDataFree::GoiCuocDataFree() : GoiCuocBasic()
{
	m_freeNet = 0;
	m_moneyFreeNet = 0;
}

GoiCuocDataFree::GoiCuocDataFree(int callTime, int useNet, int freeNet,
				 float moneyFreeNet)
    : GoiCuocBasic(callTime, useNet), m_freeNet(freeNet),
      m_moneyFreeNet(moneyFreeNet)
{
}

GoiCuocDataFree::GoiCuocDataFree(const GoiCuocDataFree &free)
    : GoiCuocBasic(free), m_freeNet(free.m_freeNet),
      m_moneyFreeNet(free.m_moneyFreeNet)
{
}

float GoiCuocDataFree::cuocInternet()
{
	if (m_useNet <= m_freeNet) {
		return m_moneyFreeNet;
	} else {
		return m_moneyFreeNet +
		       (m_useNet - m_freeNet) * GoiCuocBasic::MONEY_PER_MB;
	}
}

GoiCuocDataFree *GoiCuocDataFree::clone() const
{
	return new GoiCuocDataFree(*this);
}

// DATA FIX
GoiCuocDataFix::GoiCuocDataFix() : GoiCuocBasic()
{
}

GoiCuocDataFix::GoiCuocDataFix(int callTime, int useNet)
    : GoiCuocBasic(callTime, useNet)
{
}

GoiCuocDataFix::GoiCuocDataFix(const GoiCuocDataFix &fix) : GoiCuocBasic(fix)
{
}

float GoiCuocDataFix::cuocDienThoai()
{
	return GoiCuocBasic::cuocDienThoai() * 0.9; // Giam 10%
}

float GoiCuocDataFix::cuocInternet()
{
	return 1000; // 1.000.000 dong
}

GoiCuocDataFix *GoiCuocDataFix::clone() const
{
	return new GoiCuocDataFix(*this);
}