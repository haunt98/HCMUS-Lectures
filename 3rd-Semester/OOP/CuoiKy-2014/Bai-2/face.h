#ifndef _FACE_H
#define _FACE_H

#include <string>

using namespace std;

class IFace
{
public:
    virtual void show() = 0;
    virtual IFace *clone() = 0;
    virtual ~IFace() {}
};

class Face : public IFace
{
private:
    string m_shape;

protected:
    string getShape();

public:
    Face() : m_shape("") {}
    Face(string sh) : m_shape(sh) {}
    virtual void show();
    virtual Face *clone();
    virtual ~Face() {}
};

class EyedFace : public Face
{
private:
    int m_eyes;

public:
    static int count;
    EyedFace(string sh, int ey);
    void show();
    virtual EyedFace *clone();
    ~EyedFace();
};

void testFace(IFace *fc);

#endif