#include "BenhNhan.h"
#include <fstream>
#include <iostream>

using namespace std;

BenhNhan::BenhNhan(const string &MSBN) : m_MSBN(MSBN)
{
	m_dayIn = 0;
	m_dayOut = 0;
}

BenhNhan::BenhNhan(const string &MSBN, float money) : m_MSBN(MSBN)
{
	m_money = money;
	m_dayIn = 0;
	m_dayOut = 0;
}

// Money
void BenhNhan::outMoney()
{
	cout << m_MSBN << ": " << m_money << " kVND" << endl;
}

// Day
void BenhNhan::setDayIn(int dayIn)
{
	m_dayIn = dayIn;
}

void BenhNhan::setDayOut(int dayOut)
{
	m_dayOut = dayOut;
}

// Other check
bool BenhNhan::sameMSBN(const string &MSBN)
{
	return m_MSBN == MSBN;
}

// Ngoai tru
BN_NgoaiTru::BN_NgoaiTru(const string &MSBN, float money)
    : BenhNhan(MSBN, money)
{
}

void BN_NgoaiTru::addMoney(float money)
{
	m_money += money;
}

void BN_NgoaiTru::writehistory(float money)
{
	string FileName = m_MSBN + ".txt";
	ofstream file(FileName, ios::app); // ghi tiep theo chu khong ghi moi
	file << m_dayIn << " KB " << money << endl;
	file.close();
}

// Noi tru
BN_NoiTru::BN_NoiTru(const string &MSBN, int moneyPerDay, char phong)
    : BenhNhan(MSBN)
{
	m_moneyPerDay = moneyPerDay;
	m_phong = phong;
	updateMoney(m_dayOut);
}

void BN_NoiTru::updateMoney(int dayOut)
{
	if (m_dayOut == 0) {
		m_dayOut = dayOut;

		const float PHONG_A = 1400;
		const float PHONG_B = 900;
		const float PHONG_C = 600;

		if (m_phong == 'A') {
			m_money =
			    (m_dayOut - m_dayIn) * (m_moneyPerDay + PHONG_A);
		} else if (m_phong == 'B') {
			m_money =
			    (m_dayOut - m_dayIn) * (m_moneyPerDay + PHONG_B);
		} else if (m_phong == 'C') {
			m_money =
			    (m_dayOut - m_dayIn) * (m_moneyPerDay + PHONG_C);
		}
	}
}

void BN_NoiTru::writehistory(float moneyPerDay)
{
	string FileName = m_MSBN + ".txt";
	ofstream file(FileName, ios::app); // ghi tiep theo chu khong ghi moi
	if (m_dayOut == 0) {
		file << m_dayIn << " NV " << moneyPerDay << " " << m_phong
		     << endl;
	} else {
		file << m_dayOut << " XV " << endl;
	}
	file.close();
}