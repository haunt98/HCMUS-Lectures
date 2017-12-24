#include <iostream>
#include <string>
using namespace std;

class BigInteger
{
private:
    string m_value;

public:
    BigInteger() : m_value("0") {}
    BigInteger(string value) : m_value(value) {}
    bool operator==(const BigInteger &ano_int)
    {
        return m_value == ano_int.m_value;
    }
    friend istream &operator>>(istream &in, BigInteger &big_int);
    friend ostream &operator<<(ostream &out, const BigInteger &big_int);
};

istream &operator>>(istream &in, BigInteger &big_int)
{
    int temp;
    in >> temp;

    big_int.m_value.clear();
    while (temp)
    {
        big_int.m_value.push_back(temp % 10 + '0');
        temp /= 10;
    }
    for (size_t i = 0, j = big_int.m_value.size() - 1; i < j; ++i, --j)
    {
        char temp = big_int.m_value[i];
        big_int.m_value[i] = big_int.m_value[j];
        big_int.m_value[j] = temp;
    }
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &big_int)
{
    out << big_int.m_value;
    return out;
}

int main()
{
    BigInteger n1("1234");
    BigInteger n2;
    cout << "Input an integer = ";
    cin >> n2;
    if (n1 == n2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }
    return 0;
}
