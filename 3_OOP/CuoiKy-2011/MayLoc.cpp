#include "MayLoc.h"
#include <iostream>

using namespace std;

// May xuc tac
float MayXucTac::congSuat()
{
    if (getTgian() < 10)
    {
        return m_cs * (m_hoaChat / 100);
    }
    else
    {
        return m_cs * (m_hoaChat / 100) / (getTgian() / 10);
    }
}

float MayXucTac::DON_GIA_THUE = 80000;
float MayXucTac::chiPhiThue()
{
    return DON_GIA_THUE * getTgian();
}

float MayXucTac::DON_GIA_HOA_CHAT = 10000;
float MayXucTac::tinhChiPhi()
{
    return chiPhiThue() + m_hoaChat * DON_GIA_HOA_CHAT;
}

void MayXucTac::nhap()
{
    cout << "Nhap thoi gian: ";
    float tgian;
    cin >> tgian;
    setTgian(tgian);
    cout << "Nhap cong suat loc: ";
    cin >> m_cs;
    cout << "Nhap luong hoa chat: ";
    cin >> m_hoaChat;
}
