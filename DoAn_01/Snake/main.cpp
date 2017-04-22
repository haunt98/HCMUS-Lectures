#include "xuly.h"

void main()
{
	FixConsoleWindow();
	StartGame();
	ShowCur(false);
	thread main_thread(ThreadFunc);
	HANDLE handle_main_thread = main_thread.native_handle();
	while (true)
	{
		int temp = toupper(_getch());
		if (STATE)
		{
			if (temp == 'P')
			{
				PauseGame(handle_main_thread);
			}
			else if (temp == ESC)
			{
				ExitGame(handle_main_thread);
				break;
			}
			// Luu game
			else if (temp == 'L')
			{
				PauseGame(handle_main_thread);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Input filename to save game" << endl;
				char p[20];
				cin >> p;
				SaveGame(p);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				for (int i = 0; i < 150; ++i)
					cout << " ";
				//cout << "Game Saved";
				ResumeThread(handle_main_thread);
			}
			// Tai game da luu
			else if (temp == 'T')
			{
				PauseGame(handle_main_thread);
				DrawSnakeAndFood(" ", " ");
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Where saved game?" << endl;
				char p[20];
				cin >> p;
				LoadGame(p);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				for (int i = 0; i < 150; ++i)
					cout << " ";
				ResumeThread(handle_main_thread);
			}
			else
			{
				ResumeThread(handle_main_thread);
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
				ExitGame(handle_main_thread);
				break;
			}
		}
	}
	main_thread.join();
	return;
}