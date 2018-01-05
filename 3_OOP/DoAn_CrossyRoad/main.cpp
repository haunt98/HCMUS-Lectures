#pragma comment(lib, "winmm.lib")
#include "Console.h"
#include "Game.h"
#include "GlobalVar.h"
#include <conio.h>

// C++ stuff
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Global var
char MOVING;
const int ESC = 27;
Game CR;
int temp_menu_glo;

// Thread function
void GameThread();

int main()
{
	// Fixed console
	fixedOutputWindow();
	hideCursor();
	clearScreen();

	// Loading screen
	// clang-format off
	cout << endl;
	cout<<"   #####                                 ######                      "<<endl;
	cout<<"  #     # #####   ####   ####   ####     #     #  ####    ##   ##### "<<endl;
	cout<<"  #       #    # #    # #      #         #     # #    #  #  #  #    #"<<endl;
	cout<<"  #       #    # #    #  ####   ####     ######  #    # #    # #    #"<<endl;
	cout<<"  #       #####  #    #      #      #    #   #   #    # ###### #    #"<<endl;
	cout<<"  #     # #   #  #    # #    # #    #    #    #  #    # #    # #    #"<<endl;
	cout<<"   #####  #    #  ####   ####   ####     #     #  ####  #    # ##### "<<endl;
	// clang-format on
	ToaDo(2, 9).GotoXY();
	cout << "Loading [";
	for (int i = 0; i < 56; ++i) {
		ToaDo(11, 9).GotoXY();
		int j;
		for (j = 0; j < i; ++j) {
			cout << "#";
		}
		ToaDo(67, 9).GotoXY();
		cout << "]";
		ToaDo(25, 10).GotoXY();
		cout << "        " << endl;
		ToaDo(25, 10).GotoXY();
		cout << "[" << (i + 1) * 100 / 57 << "%]" << endl;
		Sleep(45);
	}
	clearScreen();

	// Need variable
	int input;
	bool isPause = false;

	// Menu
	temp_menu_glo = CR.Menu();
	if (temp_menu_glo == -1) {
		return 0;
	}
	if (temp_menu_glo == 1) {
		clearScreen();
		CR.Start();
	} else {
		// clang-format off
        PlaySound(TEXT("D:\\Project\\1612180_CrossyRoad\\CrossyRoad\\Background.wav"),
			NULL, SND_ASYNC | SND_LOOP);
		// clang-format on
	}
	// Create thread
	thread t(GameThread);
	ThreadGuard g_t(t);
	HANDLE handle_t = t.native_handle();

	while (true) {
		input = _getch();
		input = toupper(input);
		if (CR.getPeople().isLive()) {
			if (input == ESC) {
				CR.Pause(handle_t);
				int temp_menu_loc = CR.Menu();
				if (temp_menu_loc == -1) {
					CR.Exit(t);
					return 0;
				}
				CR.Resume(handle_t);
			}

			else if (input == 'P') {
				CR.Pause(handle_t);
				ToaDo(0, HEIGHT_BOARD).GotoXY();
				cout << "Pause game, press any key to resume"
				     << endl;
				isPause = true;
			}

			else if (input == 'T') // Tai file
			{
				CR.Pause(handle_t);
				ToaDo(0, HEIGHT_BOARD).GotoXY();
				cout << "Input name of saved file: ";
				string saveFile;
				cin >> saveFile;
				if (!ifstream(saveFile, ios::in | ios::binary)
					 .is_open()) {
					cout << "Can find saved file" << endl;
					cout << "Press any key to resume"
					     << endl;
					isPause = true;
				} else {
					CR.Load(saveFile);
					CR.Resume(handle_t);
				}
			} else if (input == 'L') // Luu file
			{
				CR.Pause(handle_t);
				ToaDo(0, HEIGHT_BOARD).GotoXY();
				cout << "Input name to save game: ";
				string saveFile;
				cin >> saveFile;
				CR.Save(saveFile);
				cout << "Successful! Press any key to continue "
					"playing";
				isPause = true;
			} else {
				if (isPause) {
					ToaDo(0, HEIGHT_BOARD).GotoXY();
					for (int i = 0; i < 4; ++i) {
						for (int j = 0; j < WIDTH_BOARD;
						     ++j) {
							cout << ' ';
						}
						isPause = false;
					}
				}
				CR.Resume(handle_t);
				MOVING = input;
			}
		} else {
			// When character die
			// Player choose to Reset or Exit
			if (input == 'Y') {
				if (temp_menu_glo != 1) {
					// clang-format off
                    PlaySound(TEXT("D:\\Project\\1612180_CrossyRoad\\CrossyRoad\\Background.wav"),
                              NULL, SND_ASYNC | SND_LOOP);
					// clang-format on
				}
				CR.Start();
			} else {
				CR.Exit(t);
				return 0;
			}
		}
	}
	return 0;
}
void GameThread()
{
	while (CR.run) {
		// When the people die, but user haven't press any key yet
		// do nothing
		while (!CR.isLive() && CR.run) {
			// Sleep to wait for user input
			Sleep(100);
		}

		// Make sure the loop don't run again
		// after people die and user press exit
		if (!CR.run) {
			return;
		}

		if (CR.isLive()) {
			CR.MovePeople(MOVING);
		}
		// Block move, wait for signal
		MOVING = ' ';
		// Move object
		CR.MoveObj();
		// Continous-draw
		CR.DrawConstinous();

		// Check touch
		if (CR.isHit()) {
			if (temp_menu_glo != 1) {
				// clang-format off
				PlaySound(TEXT("D:\\Project\\1612180_CrossyRoad\\CrossyRoad\\Omae.wav"),
					NULL, SND_SYNC);
				// clang-format on
			}
			CR.Lose();
		}
		if (CR.getPeople().isWin()) {
			CR.Win();
		}
		Sleep(150);
	}
}