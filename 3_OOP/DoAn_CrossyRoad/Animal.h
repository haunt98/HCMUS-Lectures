#ifndef ANIMAL_H
#define ANIMAL_H

#include "Board.h"
#include "ToaDo.h"

#define SIZE_DINA 9
#define SIZE_BIRD 6

class Animal
{
protected:
    ToaDo m_root;
    ToaDo m_prev;

public:
    Animal();
    Animal(const ToaDo &);
    Animal(const Animal &);
    virtual ToaDo getRoot();
    virtual void setRoot(const ToaDo &);
    virtual ToaDo getPrev();
    virtual void setPrev(const ToaDo &);
    virtual void Reset();
    virtual void Draw(int ch) = 0;
    virtual void MoveRight() = 0;
    virtual bool isHit(const ToaDo &) = 0;
    virtual Animal &operator=(const Animal &);
};

class Dina : public Animal
{
private:
    ToaDo m_lpos[SIZE_DINA];
    void setlpos();

public:
    Dina();
    Dina(const ToaDo &);
    Dina(const Dina &);
    void Draw(int ch);
    void MoveRight();
    bool isHit(const ToaDo &);
    Dina &operator=(const Dina &);
};

class Bird : public Animal
{
private:
    ToaDo m_lpos[SIZE_BIRD];
    void setlpos();

public:
    Bird();
    Bird(const ToaDo &);
    Bird(const Bird &);
    void Draw(int ch);
    void MoveRight();
    bool isHit(const ToaDo &);
    Bird &operator=(const Bird &);
};

#endif