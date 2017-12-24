#include "BenhVien.h"
#include <fstream>
#include <iostream>

using namespace std;

BenhVien::BenhVien()
{
    m_slNgoaiTru = 0;
    m_slNoiTru = 0;
}

void BenhVien::doc(const string &FileName)
{
    ifstream file(FileName, ios::in);
    if (!file.is_open())
    {
        cout << "Khong tim thay file" << endl;
        return;
    }
    int curday;
    while (file >> curday)
    {
        string MSBN;
        file >> MSBN;
        string hoatdong;
        file >> hoatdong;
        if (hoatdong == "KB") // Kham benh
        {
            float money;
            file >> money;
            money /= 1000; // don vi kVND
            bool found = false;
            for (size_t i = 0; i < m_ds.size(); ++i)
            {
                if (m_ds[i]->sameMSBN(MSBN))
                {
                    found = true;
                    m_ds[i]->addMoney(money);
                    m_ds[i]->setDayIn(curday);
                    m_ds[i]->writehistory(money);
                }
            }
            if (!found)
            {
                BenhNhan *bn = new BN_NgoaiTru(MSBN, money);
                themBN(bn);
                bn->setDayIn(curday);
                bn->writehistory(money);
                ++m_slNgoaiTru;
            }
        }
        else if (hoatdong == "NV") // Nhap vien
        {
            float moneyPerDay;
            file >> moneyPerDay;
            moneyPerDay /= 1000; // don vi kVND
            char phong;
            file >> phong;
            BenhNhan *bn = new BN_NoiTru(MSBN, moneyPerDay, phong);
            bn->setDayIn(curday);
            themBN(bn);
            bn->writehistory(moneyPerDay);
            ++m_slNoiTru;
        }
        else if (hoatdong == "XV") // Xuat vien
        {
            for (size_t i = 0; i < m_ds.size(); ++i)
            {
                if (m_ds[i]->sameMSBN(MSBN))
                {
                    m_ds[i]->updateMoney(curday);
                    float temp_moneyPerDay = -1;
                    m_ds[i]->writehistory(temp_moneyPerDay);
                    break;
                }
            }
        }
        else if (hoatdong == "TKVP") // Tong ket vien phi
        {
            for (size_t i = 0; i < m_ds.size(); ++i)
            {
                m_ds[i]->updateMoney(curday);
            }
        }
    }
    file.close();
}

BenhVien::~BenhVien()
{
    for (size_t i = 0; i < m_ds.size(); ++i)
    {
        delete m_ds[i];
    }
    m_ds.clear();
}

void BenhVien::themBN(BenhNhan *bn)
{
    m_ds.push_back(bn);
}

void BenhVien::outMoney()
{
    float sum = 0;
    for (size_t i = 0; i < m_ds.size(); ++i)
    {
        m_ds[i]->outMoney();
        sum += m_ds[i]->getMoney();
    }
    cout << "Tong vien phi: " << sum << " kVND" << endl;
}

int BenhVien::slNgoaiTru()
{
    return m_slNgoaiTru;
}

int BenhVien::slNoiTru()
{
    return m_slNoiTru;
}