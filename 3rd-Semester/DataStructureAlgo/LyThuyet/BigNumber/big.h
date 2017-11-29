#ifndef _BIG_H
#define _BIG_H

#include "List.h"
#include <string>

using namespace std;

// So nguyen lon
class BigNum
{
private:
    bool positive; // âm hay dương
    List m_digits;

public:
    BigNum(const string &numb);
    void print();

    // operator
    BigNum &operator=(const BigNum &);
    BigNum &operator+=(const BigNum &);
    BigNum &operator-=(const BigNum &);
};

#endif