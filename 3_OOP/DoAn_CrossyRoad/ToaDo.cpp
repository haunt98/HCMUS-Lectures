#include "ToaDo.h"

using namespace std;

ToaDo::ToaDo()
{
    X = 0;
    Y = 0;
}

ToaDo::ToaDo(int x, int y)
{
    X = x;
    Y = y;
}

ToaDo::ToaDo(const ToaDo &td)
{
    X = td.X;
    Y = td.Y;
}

// Operator
ToaDo &ToaDo::operator=(const ToaDo &td)
{
    X = td.X;
    Y = td.Y;
    return *this;
}

ToaDo ToaDo::operator+(const ToaDo &td) const
{
    ToaDo tong;
    tong.X = X + td.X;
    tong.Y = Y + td.Y;
    return tong;
}

ToaDo &ToaDo::operator+=(const ToaDo &td)
{
    *this = (*this) + td;
    return *this;
}

ToaDo ToaDo::operator-(const ToaDo &td) const
{
    ToaDo hieu;
    hieu.X = X - td.X;
    hieu.Y = Y - td.Y;
    return hieu;
}

ToaDo &ToaDo::operator-=(const ToaDo &td)
{
    *this = (*this) - td;
    return *this;
}

bool ToaDo::operator==(const ToaDo &td) const
{
    return X == td.X && Y == td.Y;
}

bool ToaDo::operator!=(const ToaDo &td) const
{
    return !(*this == td);
}

// Action
void ToaDo::GotoXY()
{
    static const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, COORD{X, Y});
}

void ToaDo::Draw(int ch)
{
    GotoXY();
    cout << (char)ch;
}

// Move
ToaDo ToaDo::Up()
{
    return (*this) - ToaDo(0, 1);
}

ToaDo ToaDo::Down()
{
    return (*this) + ToaDo(0, 1);
}

ToaDo ToaDo::Left()
{
    return (*this) - ToaDo(1, 0);
}

ToaDo ToaDo::Right()
{
    return (*this) + ToaDo(1, 0);
}

// I/O
ostream &operator<<(ostream &out, const ToaDo &td)
{
    out << td.X << " " << td.Y;
    return out;
}

istream &operator>>(istream &in, ToaDo &td)
{
    in >> td.X >> td.X;
    return in;
}

ofstream &operator<<(ofstream &out, const ToaDo &td)
{
    out << td.X << " " << td.Y;
    return out;
}

ifstream &operator>>(ifstream &in, ToaDo &td)
{
    in >> td.X >> td.Y;
    return in;
}