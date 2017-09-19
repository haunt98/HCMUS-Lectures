#include <iostream>
#include "hocsinh.h"

using namespace std;

int main() {
    HocSinh a;
    a.nhap();
    // a.xuat();
    cout << a.layTen() << endl;
    cout << a.layDiemVan() << endl;
    cout << a.layDiemToan() << endl;
    cout << a.layDiemTB() << endl;
    cout << a.layXepLoai() << endl;
    return 0;
}
