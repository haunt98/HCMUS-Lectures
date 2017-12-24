#include "big.h"
#include <iostream>

using namespace std;

// -123 hay 123
BigNum::BigNum(const string &numb)
{
    size_t i = 0;
    if (numb[i] == '-')
    {
        positive = false;
        ++i;
    }
    else
    {
        positive = true;
    }
    for (; i < numb.size(); ++i)
    {
        if (numb[i] >= '0' && numb[i] <= '9')
        {
            m_digits.addTail(numb[i] - '0');
        }
    }
}

void BigNum::print()
{
    if (!positive)
    {
        cout << '-';
    }
    m_digits.print();
}

BigNum &BigNum::operator+=(const BigNum &bn)
{
    // cong hai so cung dau
    if ((positive && bn.positive) || (!positive && !bn.positive))
    {
        m_digits += bn.m_digits;
    }
    // cong hai so trai dau
    else
    {
        if (m_digits < bn.m_digits)
        {
            positive = !positive;
        }
        m_digits -= bn.m_digits;
    }
    return *this;
}

BigNum &BigNum::operator-=(const BigNum &bn)
{
    // duong - am = duong + (- am) = duong + duong
    if ((positive && !bn.positive) || (!positive && bn.positive))
    {
        m_digits += bn.m_digits;
    }
    else
    {
        if (m_digits < bn.m_digits)
        {
            positive = !positive;
        }
        m_digits -= bn.m_digits;
    }
    return *this;
}