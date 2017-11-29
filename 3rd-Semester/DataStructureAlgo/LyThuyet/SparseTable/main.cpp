// Bảng thưa mô phỏng bảng 2 chiều

#include "SparseTable.h"
#include <iostream>

using namespace std;

int main()
{
    SparseTable t(2, 2);
    t.add(100, 0, 1);
    t.add(99, 0, 0);
    t.add(111, 1, 0);
    t.print();
    t.del(0, 0);
    t.print();
    return 0;
}