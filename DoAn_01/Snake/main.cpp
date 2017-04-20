#include "xuly.h"

void main()
{
	int temp;
	FixConsoleWindow();
	StartGame();
	ShowCur(false);
	thread t1(ThreadFunc);
	HANDLE handle_t1 = t1.native_handle();
	while (true)
	{
		temp = toupper(_getch());
		if (STATE)
		{
			if (temp == 'P')
			{
				PauseGame(handle_t1);
			}
			else if (temp == ESC)
			{
				ExitGame(handle_t1);
				break;
			}
			// Luu game
			else if (temp == 'L')
			{
				PauseGame(handle_t1);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Input filename to save game" << endl;
				char p[20];
				cin >> p;
				SaveGame(p);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				for (int i = 0; i < 150; ++i)
					cout << " ";
				//cout << "Game Saved";
				ResumeThread(handle_t1);
			}
			// Tai game da luu
			else if (temp == 'T')
			{
				PauseGame(handle_t1);
				DrawSnakeAndFood(" ", " ");
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Where saved game?" << endl;
				char p[20];
				cin >> p;
				LoadGame(p);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				for (int i = 0; i < 150; ++i)
					cout << " ";
				ResumeThread(handle_t1);
			}
			else
			{
				ResumeThread(handle_t1);
				if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A'
					|| temp == 'W' || temp == 'S'))
				{
					if (temp == 'D')
						CHAR_LOCK = 'A';
					else if (temp == 'W')
						CHAR_LOCK = 'S';
					else if (temp == 'S')
						CHAR_LOCK = 'W';
					else
						CHAR_LOCK = 'D';
					MOVING = temp;
				}
			}
		}
		else
		{
			if (temp == 'Y')
				StartGame();
			else
			{
				ExitGame(handle_t1);
				break;
			}
		}
	}
	t1.join();
	return;
}