#include "Animal.h"

// Animal
Animal::Animal() : m_root(), m_prev() {}

Animal::Animal(const ToaDo &td) : m_root(td), m_prev(td) {}

Animal::Animal(const Animal &an) : m_root(an.m_root), m_prev(an.m_prev) {}

ToaDo Animal::getRoot()
{
    return m_root;
}

void Animal::setRoot(const ToaDo &td)
{
    m_root = td;
}

ToaDo Animal::getPrev()
{
    return m_prev;
}

void Animal::setPrev(const ToaDo &td)
{
    m_prev = td;
}

void Animal::Reset()
{
    m_root.X = 1; // The most left
}

Animal &Animal::operator=(const Animal &an)
{
    m_root = an.m_root;
    m_prev = an.m_prev;
    return *this;
}

// Dinasour
// D DD
// DDDD
// DD
void Dina::setlpos()
{
    m_lpos[0] = ToaDo(0, 0);
    m_lpos[1] = ToaDo(0, 1);
    m_lpos[2] = ToaDo(0, 2);
    m_lpos[3] = ToaDo(1, 2);
    m_lpos[4] = ToaDo(1, 1);
    m_lpos[5] = ToaDo(2, 1);
    m_lpos[6] = ToaDo(2, 0);
    m_lpos[7] = ToaDo(3, 1);
    m_lpos[8] = ToaDo(3, 0);
}

Dina::Dina()
{
    setlpos();
}

Dina::Dina(const ToaDo &td) : Animal(td)
{
    setlpos();
}

Dina::Dina(const Dina &di) : Animal(di)
{
    setlpos();
}

void Dina::Draw(int ch)
{
    if (m_root == m_prev)
    {
        for (int i = 0; i < SIZE_DINA; ++i)
        {
            (m_root + m_lpos[i]).Draw(ch);
        }
    }
    else
    {
        ToaDo old_pos[SIZE_DINA];
        ToaDo new_pos[SIZE_DINA];
        for (int i = 0; i < SIZE_DINA; ++i)
        {
            old_pos[i] = m_prev + m_lpos[i];
            new_pos[i] = m_root + m_lpos[i];
        }
        bool isDup;
        // Only remove not duplicate
        for (int i = 0; i < SIZE_DINA; ++i)
        {
            isDup = false;
            ToaDo old_temp = old_pos[i];
            for (int j = 0; j < SIZE_DINA; ++j)
            {
                if (old_temp == new_pos[j])
                {
                    isDup = true;
                    break;
                }
            }
            if (!isDup)
            {
                old_temp.Draw(' ');
            }
        }
        // Only write what new
        for (int i = 0; i < SIZE_DINA; ++i)
        {
            isDup = false;
            ToaDo new_temp = new_pos[i];
            for (int j = 0; j < SIZE_DINA; ++j)
            {
                if (new_temp == old_pos[i])
                {
                    isDup = true;
                    break;
                }
            }
            if (!isDup)
            {
                new_temp.Draw(ch);
            }
        }
        m_prev = m_root;
    }
}

void Dina::MoveRight()
{
    ToaDo endlpos = m_root + m_lpos[SIZE_DINA - 1];
    if (endlpos.X < WIDTH_BOARD - 2)
    {
        m_root = m_root.Right();
    }
    else
    {
        Reset();
    }
}

bool Dina::isHit(const ToaDo &td)
{
    for (int i = 0; i < SIZE_DINA; ++i)
    {
        if (m_root + m_lpos[i] == td)
        {
            return true;
        }
    }
    return false;
}

Dina &Dina::operator=(const Dina &di)
{
    Animal::operator=(di);
    for (int i = 0; i < SIZE_DINA; ++i)
    {
        m_lpos[i] = di.m_lpos[i];
    }
    return *this;
}

// Bird
// BB  BB
//   BB
void Bird::setlpos()
{
    m_lpos[0] = ToaDo(0, 0);
    m_lpos[1] = ToaDo(1, 0);
    m_lpos[2] = ToaDo(2, 1);
    m_lpos[3] = ToaDo(3, 1);
    m_lpos[4] = ToaDo(4, 0);
    m_lpos[5] = ToaDo(5, 0);
}

Bird::Bird() : Animal()
{
    setlpos();
}

Bird::Bird(const ToaDo &td) : Animal(td)
{
    setlpos();
}

Bird::Bird(const Bird &bi) : Animal(bi)
{
    setlpos();
}

void Bird::Draw(int ch)
{
    if (m_root == m_prev)
    {
        for (int i = 0; i < SIZE_BIRD; ++i)
        {
            (m_root + m_lpos[i]).Draw(ch);
        }
    }
    else
    {
        ToaDo old_pos[SIZE_BIRD];
        ToaDo new_pos[SIZE_BIRD];
        for (int i = 0; i < SIZE_BIRD; ++i)
        {
            old_pos[i] = m_prev + m_lpos[i];
            new_pos[i] = m_root + m_lpos[i];
        }
        bool isDup;
        // Only remove not duplicate
        for (int i = 0; i < SIZE_BIRD; ++i)
        {
            isDup = false;
            ToaDo old_temp = old_pos[i];
            for (int j = 0; j < SIZE_BIRD; ++j)
            {
                if (old_temp == new_pos[j])
                {
                    isDup = true;
                    break;
                }
            }
            if (!isDup)
            {
                old_temp.Draw(' ');
            }
        }
        // Only write what new
        for (int i = 0; i < SIZE_BIRD; ++i)
        {
            isDup = false;
            ToaDo new_temp = new_pos[i];
            for (int j = 0; j < SIZE_BIRD; ++j)
            {
                if (new_temp == old_pos[i])
                {
                    isDup = true;
                    break;
                }
            }
            if (!isDup)
            {
                new_temp.Draw(ch);
            }
        }
        m_prev = m_root;
    }
}

void Bird::MoveRight()
{
    ToaDo endlpos = m_root + m_lpos[SIZE_BIRD - 1];
    if (endlpos.X < WIDTH_BOARD - 2)
    {
        m_root = m_root.Right();
    }
    else
    {
        Reset();
    }
}

bool Bird::isHit(const ToaDo &td)
{
    for (int i = 0; i < SIZE_BIRD; ++i)
    {
        if (m_root + m_lpos[i] == td)
        {
            return true;
        }
    }
    return false;
}

Bird &Bird::operator=(const Bird &bi)
{
    Animal::operator=(bi);
    for (int i = 0; i < SIZE_BIRD; ++i)
    {
        m_lpos[i] = bi.m_lpos[i];
    }
    return *this;
}