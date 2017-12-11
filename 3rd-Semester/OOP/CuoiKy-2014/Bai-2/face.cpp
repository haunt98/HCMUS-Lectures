#include "face.h"
#include <iostream>

using namespace std;

// Face
string Face::getShape()
{
    return m_shape;
}

void Face::show()
{
    cout << "Shape: " << m_shape << endl;
}

Face *Face::clone()
{
    return new Face(m_shape);
}

// EyedFace
EyedFace::EyedFace(string sh, int ey) : Face(sh)
{
    m_eyes = ey;
    ++count;
}

void EyedFace::show()
{
    Face::show();
    cout << "Eyes: " << m_eyes << endl;
}

EyedFace *EyedFace::clone()
{
    return new EyedFace(this->getShape(), m_eyes);
}

EyedFace::~EyedFace()
{
    --count;
}

void testFace(IFace *fc)
{
    IFace *a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++)
    {
        a[i]->show();
    }
    cout << "The same 3 lines ?" << endl;
    // free memory use by clone
    delete a[1];
    delete a[2];
}