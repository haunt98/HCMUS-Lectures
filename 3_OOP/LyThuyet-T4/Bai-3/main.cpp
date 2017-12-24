#include "Mang.h"

int main()
{
    Mang<int> m1;
    cin >> m1;
    int *p = (int *)m1;
    cout << p << endl;
    return 0;
}
