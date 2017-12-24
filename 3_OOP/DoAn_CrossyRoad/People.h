#ifndef PEOPLE_H
#define PEOPLE_H

#include "Animal.h"
#include "Board.h"
#include "ToaDo.h"
#include "Vehicle.h"

using namespace std;

class People
{
private:
    ToaDo m_pos;
    ToaDo m_prev; // Only draw when move, to fix flickering
    ToaDo m_origin;
    bool m_live; // dead or alive

public:
    People();
    ToaDo getPos();

    void Reset();
    void Draw(int ch);

    // Moving
    void Up();
    void Down();
    void Left();
    void Right();

    // State
    bool isLive();
    bool isWin();
    void Die();
    bool isHit(Animal *an);
    bool isHit(Vehicle *ve);

    // I/O
    friend ostream &operator<<(ostream &out, const People &nvat);
    friend istream &operator>>(istream &in, People &nvat);
    friend ofstream &operator<<(ofstream &out, const People &nvat);
    friend ifstream &operator>>(ifstream &out, People &nvat);
};

#endif