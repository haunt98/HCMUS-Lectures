#ifndef _BENH_NHAN_H
#define _BENH_NHAN_H

#include <string>

using namespace std;

class BenhNhan
{
protected:
    string m_MSBN;
    float m_money; // don vi 1000 VND
    int m_dayIn;   // ngay nhap vien
    int m_dayOut;  // ngay xuat vien
public:
    BenhNhan(const string &MSBN);
    BenhNhan(const string &MSBN, float money);

    // Money
    virtual void addMoney(float money) {}
    float getMoney() { return m_money; }
    void outMoney();
    virtual void updateMoney(int dayOut) {}

    // Day
    void setDayIn(int dayIn);
    void setDayOut(int dayOut);

    // Other check
    bool sameMSBN(const string &MSBN);

    // Lich su benh nhan
    virtual void writehistory(float money) {}
};

class BN_NgoaiTru : public BenhNhan
{
public:
    BN_NgoaiTru(const string &MSBN, float money);
    void addMoney(float money);
    void writehistory(float money);
};

class BN_NoiTru : public BenhNhan
{
private:
    int m_moneyPerDay;
    char m_phong; // Phong loai A, B, C
public:
    BN_NoiTru(const string &MSBN, int moneyPerDay, char phong);
    void updateMoney(int dayOut);
    void writehistory(float moneyPerDay);
};

#endif