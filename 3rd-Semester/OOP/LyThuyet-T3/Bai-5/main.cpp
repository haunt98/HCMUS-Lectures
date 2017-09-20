#include "phanso.h"

int main()
{
    PhanSo* ps = PhanSo::tao(1, 2);
    (*ps).xuat();
    delete ps;
    return 0;
}
