#include "SortAlgorithm.h"
#include <iostream>
using namespace std;

int main()
{
    float a1[] = {1.4F, -5.2F, 3.3F, 0};
    char a2[] = {'D', 'B', 'A', 'C'};
    HOCSINH a3[] = {HOCSINH("Lan", 4), HOCSINH("Huong", 3)};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int n3 = sizeof(a3) / sizeof(a3[0]);
    SortAlgorithm<float> *alg1 =
        SortAlgorithm<float>::getObject(SortAlgorithm<float>::InterchangeSort);
    SortAlgorithm<char> *alg2 =
        SortAlgorithm<char>::getObject(SortAlgorithm<char>::InterchangeSort);
    SortAlgorithm<HOCSINH> *alg3 = SortAlgorithm<HOCSINH>::getObject(
        SortAlgorithm<HOCSINH>::InterchangeSort);
    alg1->Sort(a1, n1);
    alg2->Sort(a2, n2);
    alg3->Sort(a3, n3);
    cout << "Mang sau khi sap xep tang dan:" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
    cout << "Mang ki tu sau khi sap xep tang dan:" << endl;

    for (int i = 0; i < n2; i++)
    {
        cout << a2[i] << "\t";
    }
    cout << endl;
    cout << "Mang HOCSINH sau khi sap xep tang dan theo diem:" << endl;
    for (int i = 0; i < n3; i++)
    {
        cout << a3[i] << "\t";
    }
    cout << endl;
    return 0;
}