#ifndef GAME_H
#define GAME_H

// Background
#include "Console.h"
#include "GlobalVar.h"
#include "ThreadGuard.h"

// Game element
#include "Animal.h"
#include "People.h"

// C++ stuff
#include <condition_variable>
#include <conio.h>
#include <mutex>
#include <string>

using namespace std;

class Game
{
private:
    People m_nvat;

    // traffic light
    // true is green
    // false is red
    bool m_greenLight;
    int m_clockLight;

    // Num of Obj = level
    int m_level;

    Dina **m_klong;
    const int LINE_DINA = 2;
    int COL_DINA;

    Bird **m_chim;
    const int LINE_BIRD = 2;
    int COL_BIRD;

    Truck **m_xetai;
    const int LINE_TRUCK = 1;
    int COL_TRUCK;

    Car **m_xehoi;
    const int LINE_CAR = 1;
    int COL_CAR;

    // Create and Del object
    void CreObj(int level);
    void DelObj();

public:
    bool run;

    Game();
    ~Game();
    People getPeople();

    void Reset();
    void ClearObj();
    void DrawObj(int ch);
    void DrawConstinous();
    void DrawOnly();
    void MovePeople(char MOVING);
    void MoveObj();
    bool isHit();
    bool isLive();
    void Win();
    void Lose();
    void NextLevel();
    void Save(const string &saveFile);
    void Load(const string &loadFile);

    // Game specific
    void Start();
    void Exit(thread &t);
    void Pause(HANDLE handle_t);
    void Resume(HANDLE handle_t);
};

#endif