#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void eratos(int max)
{
    // std::vector<int> vec(number_of_elements, default_value);
    vector<bool> A(max + 1, true);
    for (int i = 2; i * i <= max; i++) // 2->sqrt(max)
    {
        if (A[i])
        {
            for (int j = i * i; j <= max; j += i) // i^2->max
            {
                A[j] = false;
            }
        }
    }
    for (int i = 2; i <= max; i++)
    {
        if (A[i])
            cout << i << " ";
    }
}

int main()
{
    eratos(1000);
    return 0;
}
