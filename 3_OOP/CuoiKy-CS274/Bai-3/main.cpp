#include <iostream>
using namespace std;

class Triple
{
private:
    float m_x, m_y, m_z;

public:
    Triple(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}
    Triple() : m_x(0), m_y(0), m_z(0) {}
    // Addition so that corresponding elements are added together
    Triple operator+(float d);
    // Output so that it displays the Triple in the form "The triple is (x, y,
    // z)."
    friend ostream &operator<<(ostream &out, const Triple &tr);
    // Post-increment so that x and z are increased by one each.
    Triple operator++(int);
};

Triple Triple::operator+(float d)
{
    Triple newtr(m_x + d, m_y + d, m_z + d);
    return newtr;
}

ostream &operator<<(ostream &out, const Triple &tr)
{
    out << "The triple is (" << tr.m_x << ", " << tr.m_y << ", " << tr.m_z
        << ").";
    return out;
}

Triple Triple::operator++(int)
{
    Triple newtr(m_x + 1, m_y, m_z + 1);
    return newtr;
}

int main()
{
    Triple tr(1, 2, 3);
    cout << tr << endl;
    cout << (tr + 2) << endl;
    cout << (tr++) << endl;
    return 0;
}