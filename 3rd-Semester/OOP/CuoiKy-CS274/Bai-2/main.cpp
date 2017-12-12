#include <iostream>
using namespace std;

// Tu giac
//    b
//  a   c
//    d
class Quad
{
private:
    float m_a, m_b, m_c, m_d;

public:
    Quad(float a, float b, float c, float d) : m_a(a), m_b(b), m_c(c), m_d(d) {}
    void set(float a, float b, float c, float d);
    float get_a() { return m_a; }
    float get_b() { return m_b; }
    virtual float Area() = 0;
};

void Quad::set(float a, float b, float c, float d)
{
    m_a = a, m_b = b, m_c = c, m_d = d;
}

class Rectangle : public Quad
{
public:
    Rectangle(float rlong, float rshort) : Quad(rlong, rshort, rlong, rshort) {}
    float Area() { return get_a() * get_b(); }
};

int main()
{
    Rectangle r(1, 2);
    cout << r.Area() << endl;
    return 0;
}