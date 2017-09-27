#include "mang.h"
#include <iostream>

using namespace std;

int main(void)
{
    int A[] = {2, 1, 24, 5, 67, 3, 89, 12};
    int size_A = sizeof(A) / sizeof(A[0]);
    Mang<int> mangInt(A, size_A);
    mangInt.xuat();

    float B[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int size_B = sizeof(B) / sizeof(B[0]);
    Mang<float> mangFloat(B, size_B);
    mangFloat.xuat();
    return 0;
}
