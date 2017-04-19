#include "xuly.h"

void main()
{
	int temp;
	FixConsoleWindow();
	StartGame();
	thread t1(ThreadFunc);
	HANDLE handle_t1 = t1.native_handle();
	while (true)
	{
		temp = toupper(_getch());
		if (STATE == 1)
		{
			if (temp == 'P')
			{
				PauseGame(handle_t1);
			}
			else if (temp == ESC)
			{
				ExitGame(handle_t1);
				return;
			}
			else
			{
				ResumeThread(handle_t1);
				if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
				{
					if (temp == 'D')
						CHAR_LOCK = 'A';
					else if (temp == 'W')
						CHAR_LOCK = 'S';
					else if (temp == 'S')
						CHAR_LOCK = 'W';
					else CHAR_LOCK = 'D';
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
				return;
			}
		}
	}
}