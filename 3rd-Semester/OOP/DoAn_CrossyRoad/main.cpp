#include "Game.h"

using namespace std;

// Global var
char MOVING;
Game CR;

// Thread function
void GameThread();

int main()
{
    // Fixed console
    fixedOutputWindow();
    hideCursor();
    clearScreen();

    // Need variable
    static const int ESC = 27;
    int input;
    bool isPause = false;

    // Menu
    bool validInput = false;
    while (!validInput)
    {
        clearScreen();
        ToaDo(0, 0).GotoXY();
        cout << "********************************\n";
        cout << "*   Press any key to New game  *\n";
        cout << "*   Press L to Load game       *\n";
        cout << "*   Press S to Settings        *\n";
        cout << "*   Press ESC to exit          *\n";
        cout << "********************************\n";
        input = _getch();
        input = toupper(input);
        if (input == 'L')
        {
            clearScreen();
            cout << "Input name of saved file: ";
            string saveFile;
            cin >> saveFile;
            ifstream saveStream(saveFile, ios::in);
            if (!saveStream.is_open())
            {
                clearScreen();
                cout << "Can find saved file\n";
                cout << "Please press any key to back menu\n";
                input = _getch();
                input = toupper(input);
            }
            else
            {
                CR.Load(saveFile);
                validInput = true;
            }
        }
        else if (input == 'S')
        {
            clearScreen();
            cout << "This feature is under construction\n";
            cout << "Please press any key to back menu\n";
            input = _getch();
            input = toupper(input);
        }
        else if (input == ESC)
        {
            clearScreen();
            return 0;
        }
        else
        {
            CR.Start();
            validInput = true;
        }
    }

    // Create thread
    thread t(GameThread);
    ThreadGuard g_t(t);
    HANDLE handle_t = t.native_handle();

    while (true)
    {
        input = _getch();
        input = toupper(input);
        if (CR.getPeople().isLive())
        {
            if (input == ESC)
            {
                CR.Exit(t);
                return 0;
            }

            else if (input == 'P')
            {
                CR.Pause(handle_t);
                ToaDo(0, HEIGHT_BOARD).GotoXY();
                cout << "Pause game, press any key to resume\n";
                isPause = true;
            }

            else if (input == 'T') // Tai file
            {
                CR.Pause(handle_t);
                ToaDo(0, HEIGHT_BOARD).GotoXY();
                cout << "Input name of saved file: ";
                string saveFile;
                cin >> saveFile;
                if (!ifstream(saveFile, ios::in).is_open())
                {
                    cout << "Can find saved file\n";
                    cout << "Press any key to resume\n";
                    isPause = true;
                }
                else
                {
                    CR.Load(saveFile);
                    CR.Resume(handle_t);
                }
            }
            else if (input == 'L') // Luu file
            {
                CR.Pause(handle_t);
                ToaDo(0, HEIGHT_BOARD).GotoXY();
                cout << "Input name to save game: ";
                string saveFile;
                cin >> saveFile;
                CR.Save(saveFile);
                cout << "Successful! Press any key to continue playing";
                isPause = true;
            }
            else
            {
                if (isPause)
                {
                    ToaDo(0, HEIGHT_BOARD).GotoXY();
                    for (int i = 0; i < 4; ++i)
                    {
                        for (int j = 0; j < WIDTH_BOARD; ++j)
                        {
                            cout << ' ';
                        }
                        isPause = false;
                    }
                }
                CR.Resume(handle_t);
                MOVING = input;
            }
        }
        else
        {
            // When character die
            // Player choose to Reset or Exit
            if (input == 'Y')
            {
                CR.Start();
            }
            else
            {
                CR.Exit(t);
                return 0;
            }
        }
    }
    return 0;
}
void GameThread()
{
    while (CR.run)
    {
        // When the people die, but user haven't press any key yet
        // do nothing
        while (!CR.isLive() && CR.run)
        {
            // Sleep to wait for user input
            Sleep(200);
        }

        // Make sure the loop don't run again
        // after people die and user press exit
        if (!CR.run)
        {
            return;
        }

        if (CR.isLive())
        {
            CR.MovePeople(MOVING);
        }
        // Block move, wait for signal
        MOVING = ' ';
        // Move object
        CR.MoveObj();
        // Continous-draw
        CR.DrawConstinous();

        // Check touch
        if (CR.isHit())
        {
            CR.Lose();
        }
        if (CR.getPeople().isWin())
        {
            CR.Win();
        }
        Sleep(200);
    }
}