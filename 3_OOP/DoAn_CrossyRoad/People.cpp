#include "GlobalVar.h"
#include "People.h"

People::People()
{
    m_pos = ToaDo(WIDTH_BOARD / 2, HEIGHT_BOARD - 2);
    m_prev = m_pos;
    m_origin = m_pos;
    m_live = true;
}

ToaDo People::getPos()
{
    return m_pos;
}

void People::Reset()
{
    m_pos = m_origin;
    m_live = true;
}

void People::Draw(int ch)
{
    // Only update when People move
    if (m_pos == m_prev)
    {
        m_pos.Draw(ch);
    }
    else
    {
        m_prev.Draw(' ');
        m_pos.Draw(ch);
        m_prev = m_pos;
    }
}

// Moving
void People::Up()
{
    if (m_pos.Y > 1)
    {
        m_pos = m_pos.Up();
    }
}

void People::Down()
{
    if (m_pos.Y < HEIGHT_BOARD - 2)
    {
        m_pos = m_pos.Down();
    }
}

void People::Left()
{
    if (m_pos.X > 1)
    {
        m_pos = m_pos.Left();
    }
}

void People::Right()
{
    if (m_pos.X < WIDTH_BOARD - 2)
    {
        m_pos = m_pos.Right();
    }
}

// State
bool People::isLive()
{
    return m_live;
}

bool People::isWin()
{
    return m_pos.Y == 1;
}

void People::Die()
{
    m_live = false;
}

bool People::isHit(Animal *an)
{
    if (an->isHit(m_pos))
    {
        return true;
    }
    return false;
}

bool People::isHit(Vehicle *ve)
{
    if (ve->isHit(m_pos))
    {
        return true;
    }
    return false;
}

// I/O
ostream &operator<<(ostream &out, const People &nvat)
{
    out << nvat.m_pos << " " << nvat.m_prev << " " << nvat.m_origin << " "
        << nvat.m_live << endl;
    return out;
}

istream &operator>>(istream &in, People &nvat)
{
    in >> nvat.m_pos >> nvat.m_prev >> nvat.m_origin >> nvat.m_live;
    return in;
}

ofstream &operator<<(ofstream &out, const People &nvat)
{
    out << nvat.m_pos << " " << nvat.m_prev << " " << nvat.m_origin << " "
        << nvat.m_live << endl;
    return out;
}

ifstream &operator>>(ifstream &in, People &nvat)
{
    in >> nvat.m_pos >> nvat.m_prev >> nvat.m_origin >> nvat.m_live;
    return in;
}