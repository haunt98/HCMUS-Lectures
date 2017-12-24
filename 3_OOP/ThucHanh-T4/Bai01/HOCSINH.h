#ifndef HOCSINH_H
#define HOCSINH_H

#include <iostream>
using namespace std;

class HOCSINH
{
private:
    char *mTen;
    float mDiem;

public:
    HOCSINH();
    HOCSINH(const char *ten, float diem);
    HOCSINH(const HOCSINH &hs);
    HOCSINH &operator=(const HOCSINH &hs);
    ~HOCSINH();
    bool operator<(const HOCSINH &hs);
    bool operator>(const HOCSINH &hs);

    friend ostream &operator<<(ostream &out, const HOCSINH &hs);
};

#endif