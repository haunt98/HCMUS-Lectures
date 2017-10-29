#include "Animal.h"
#include <iostream>

using namespace std;

int main()
{
    Bao b1;
    LinhDuong ld1;
    SuTu st1;
    Ngua n1;
    Cho c1;

    cout << soSanh(&b1, &ld1) << endl;
    cout << soSanh(&st1, &ld1) << endl;
    cout << soSanh(&n1, &c1) << endl;

    return 0;
}
