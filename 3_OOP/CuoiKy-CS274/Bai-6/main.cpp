#include <iostream>
using namespace std;

template <class T>
class Point
{
private:
    T m_x, m_y;

public:
    Point(T, T);
    void set(T, T);
    void display();
    void swap();
};

template <class T>
Point<T>::Point(T x, T y) : m_x(x), m_y(y)
{
}

template <class T>
void Point<T>::set(T x, T y)
{
    m_x = x, m_y = y;
}

template <class T>
void Point<T>::display()
{
    cout << m_x << " " << m_y << endl;
}

template <class T>
void Point<T>::swap()
{
    T temp = m_x;
    m_x = m_y;
    m_y = temp;
}

int main()
{
    Point<int> p1(2, 3);
    p1.display();
    p1.swap();
    p1.display();
    return 0;
}