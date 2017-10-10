#define _CRT_SECURE_NO_WARNINGS
#include "HOCSINH.H"
#include <string.h>

HOCSINH::HOCSINH()
{
    mTen = NULL;
    mDiem = 0;
}

HOCSINH::HOCSINH(const char *ten, float diem)
{
    mTen = new char[strlen(ten) + 1];
    strcpy(mTen, ten);
    mDiem = diem;
}

HOCSINH::HOCSINH(const HOCSINH &hs)
{
    mTen = new char[strlen(hs.mTen) + 1];
    strcpy(mTen, hs.mTen);
    mDiem = hs.mDiem;
}

HOCSINH &HOCSINH::operator=(const HOCSINH &hs)
{
    delete[] mTen;
    mTen = new char[strlen(hs.mTen) + 1];
    strcpy(mTen, hs.mTen);
    mDiem = hs.mDiem;
    return (*this);
}

HOCSINH::~HOCSINH()
{
    delete[] mTen;
    mDiem = 0;
}

bool HOCSINH::operator<(const HOCSINH &hs) { return mDiem < hs.mDiem; }
bool HOCSINH::operator>(const HOCSINH &hs) { return mDiem > hs.mDiem; }

ostream &operator<<(ostream &out, const HOCSINH &hs)
{
    out << hs.mTen;
    return out;
}