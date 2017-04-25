#include "xuly.h"

void main()
{
	FixConsoleWindow();
	ShowCur(false);
	thread main_thread(ThreadFunc);
	HANDLE handle_main_thread = main_thread.native_handle();

	cout << "Press t to load saved games or anykey to start" << endl;
	int temp = toupper(_getch());
	StartGame();
	if (temp == 'T')
	{
		SuspendThread(handle_main_thread);
		DrawSnakeFoodGate(' ', ' ');
		GotoXY(0, HEIGHT_CONSOLE + 2);
		cout << "Where saved game?" << endl;
		char filename[20];
		cin >> filename;
		LoadGame(filename);
		GotoXY(0, HEIGHT_CONSOLE + 2);
		for (int i = 0; i < 150; ++i)
			cout << " ";
		ResumeThread(handle_main_thread);
	}
	while (true)
	{
		int temp = toupper(_getch());
		if (STATE)
		{
			if (temp == 'P')
			{
				SuspendThread(handle_main_thread);
			}
			else if (temp == 'R')
			{
				ResumeThread(handle_main_thread);
			}
			else if (temp == ESC)
			{
				ExitGame(handle_main_thread);
				break;
			}
			else if (temp == 'L')
			{
				SuspendThread(handle_main_thread);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Input filename to save game" << endl;
				char filename[20];
				cin >> filename;
				SaveGame(filename);
				GotoXY(0, HEIGHT_CONSOLE + 2);
				for (int i = 0; i < 150; ++i)
					cout << " ";
				ResumeThread(handle_main_thread);
			}
			else if (temp == 'T')
			{
				SuspendThread(handle_main_thread);
				DrawSnakeFoodGate(' ', ' ');
				GotoXY(0, HEIGHT_CONSOLE + 2);
				cout << "Where saved game?" << endl;
				char filename[20];
				cin >> filename;
				LoadGame(filename);
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