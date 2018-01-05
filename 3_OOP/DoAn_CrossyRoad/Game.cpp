#include "Game.h"
#include "Console.h"
#include "GlobalVar.h"

// C++ stuff
#include <condition_variable>
#include <conio.h>
#include <mutex>
#include <string>

// Create and Del obj
void Game::CreObj(int level)
{
	const float LIMIT = 0.75;
	const int HEIGHT_OBJ = 13;

	const int WIDTH_DINA = 8;
	m_klong = new Dina *[LINE_DINA];
	for (int i = 0; i < LINE_DINA; ++i) {
		COL_DINA = level;
		while (COL_DINA * WIDTH_DINA > WIDTH_BOARD * LIMIT) {
			--COL_DINA;
		}
		m_klong[i] = new Dina[COL_DINA];
		for (int j = 0; j < COL_DINA; ++j) {
			m_klong[i][j] =
			    Dina(ToaDo(1 + j * WIDTH_DINA, 2 + i * HEIGHT_OBJ));
		}
	}

	const int WIDTH_BIRD = 10;
	m_chim = new Bird *[LINE_BIRD];
	for (int i = 0; i < LINE_BIRD; ++i) {
		COL_BIRD = level;
		while (COL_BIRD * WIDTH_BIRD > WIDTH_BOARD * LIMIT) {
			--COL_BIRD;
		}
		m_chim[i] = new Bird[COL_BIRD];
		for (int j = 0; j < COL_BIRD; ++j) {
			m_chim[i][j] =
			    Bird(ToaDo(1 + j * WIDTH_BIRD, 6 + i * HEIGHT_OBJ));
		}
	}

	const int WIDTH_TRUCK = 12;
	m_xetai = new Truck *[LINE_TRUCK];
	for (int i = 0; i < LINE_TRUCK; ++i) {
		COL_TRUCK = level;
		while (COL_TRUCK * WIDTH_TRUCK > WIDTH_BOARD * LIMIT) {
			--COL_TRUCK;
		}
		m_xetai[i] = new Truck[COL_TRUCK];
		for (int j = 0; j < COL_TRUCK; ++j) {
			m_xetai[i][j] =
			    Truck(ToaDo(WIDTH_BOARD - 2 - j * WIDTH_TRUCK,
					9 + i * HEIGHT_OBJ));
		}
	}

	const int WIDTH_CAR = 10;
	m_xehoi = new Car *[LINE_CAR];
	for (int i = 0; i < LINE_CAR; ++i) {
		COL_CAR = level;
		while (COL_CAR * WIDTH_CAR > WIDTH_BOARD * LIMIT) {
			--COL_CAR;
		}
		m_xehoi[i] = new Car[COL_CAR];
		for (int j = 0; j < COL_CAR; ++j) {
			m_xehoi[i][j] =
			    Car(ToaDo(WIDTH_BOARD - 2 - j * WIDTH_CAR,
				      12 + i * HEIGHT_OBJ));
		}
	}
}

void Game::DelObj()
{
	// Dinasour
	if (m_klong) {
		for (int i = 0; i < LINE_DINA; ++i) {
			delete[] m_klong[i];
		}
		delete[] m_klong;
		m_klong = NULL;
	}
	// Bird
	if (m_chim) {
		for (int i = 0; i < LINE_BIRD; ++i) {
			delete[] m_chim[i];
		}
		delete[] m_chim;
		m_chim = NULL;
	}
	// Truck
	if (m_xetai) {
		for (int i = 0; i < LINE_TRUCK; ++i) {
			delete[] m_xetai[i];
		}
		delete[] m_xetai;
		m_xetai = NULL;
	}
	// Car
	if (m_xehoi) {
		for (int i = 0; i < LINE_CAR; ++i) {
			delete[] m_xehoi[i];
		}
		delete[] m_xehoi;
		m_xehoi = NULL;
	}
}

Game::Game() : m_nvat()
{
	m_greenLight = true;
	m_clockLight = 1;
	m_level = 1;
	CreObj(m_level);
	run = false;
}

Game::~Game()
{
	DelObj();
}

void Game::Reset()
{
	m_nvat.Reset();
	m_greenLight = true;
	m_clockLight = 1;
	m_level = 1;
	DelObj();
	CreObj(m_level);
}

People Game::getPeople()
{
	return m_nvat;
}

void Game::DrawObj(int ch)
{
	// Dinasour
	setColor(CYAN);
	if (m_klong) {
		for (int i = 0; i < LINE_DINA; ++i) {
			if (m_klong[i]) {
				for (int j = 0; j < COL_DINA; ++j) {
					m_klong[i][j].Draw(ch);
				}
			}
		}
	}
	// Bird
	setColor(MAGENTA);
	if (m_chim) {
		for (int i = 0; i < LINE_BIRD; ++i) {
			if (m_chim[i]) {
				for (int j = 0; j < COL_BIRD; ++j) {
					m_chim[i][j].Draw(ch);
				}
			}
		}
	}
	// Truck
	setColor(CYAN);
	if (m_xetai) {
		for (int i = 0; i < LINE_TRUCK; ++i) {
			if (m_xetai[i]) {
				for (int j = 0; j < COL_TRUCK; ++j) {
					m_xetai[i][j].Draw(ch);
				}
			}
		}
	}
	// Car
	setColor(MAGENTA);
	if (m_xehoi) {
		for (int i = 0; i < LINE_CAR; ++i) {
			if (m_xehoi[i])
				for (int j = 0; j < COL_CAR; ++j) {
					m_xehoi[i][j].Draw(ch);
				}
		}
	}
	setColor(WHITE);
}

void Game::ClearObj()
{
	DrawObj(' ');
}

void Game::DrawConstinous()
{
	const int CHAR_OBJ = 254;
	const int CHAR_PEOPLE = 239;

	// After set color, remember to set white to reset
	setColor(BROWN);
	m_nvat.Draw(CHAR_PEOPLE);
	setColor(WHITE);

	DrawObj(CHAR_OBJ);

	// Draw traffic light
	const int CHAR_TRAFFIC = 219;
	if (m_greenLight) {
		setColor(GREEN);
	} else {
		setColor(RED);
	}
	ToaDo(1, 9).GotoXY();
	cout << (char)CHAR_TRAFFIC;
	ToaDo(1, 12).GotoXY();
	cout << (char)CHAR_TRAFFIC;
	setColor(WHITE);
}

void Game::DrawOnly()
{
	DrawBoard();
	// Draw level
	ToaDo(WIDTH_BOARD + 2, 2).GotoXY();
	cout << "Level: " << m_level;
	// Instruction
	ToaDo(WIDTH_BOARD + 2, 7).GotoXY();
	cout << "Move: W S A D";
	ToaDo(WIDTH_BOARD + 2, 8).GotoXY();
	cout << "Load saved file: T";
	ToaDo(WIDTH_BOARD + 2, 9).GotoXY();
	cout << "Save file: L";
}

void Game::MovePeople(char MOVING)
{
	if (MOVING == 'W') {
		m_nvat.Up();
	} else if (MOVING == 'S') {
		m_nvat.Down();
	} else if (MOVING == 'A') {
		m_nvat.Left();
	} else if (MOVING == 'D') {
		m_nvat.Right();
	}
}

void Game::MoveObj()
{
	// Dinasour
	if (m_klong) {
		for (int i = 0; i < LINE_DINA; ++i) {
			if (m_klong[i]) {
				for (int j = 0; j < COL_DINA; ++j) {
					m_klong[i][j].MoveRight();
				}
			}
		}
	}

	// Bird
	if (m_chim) {
		for (int i = 0; i < LINE_BIRD; ++i) {
			if (m_chim[i]) {
				for (int j = 0; j < COL_BIRD; ++j) {
					m_chim[i][j].MoveRight();
				}
			}
		}
	}
	// After 10 clock, change the traffic light
	if (m_clockLight % 10 == 0) {
		m_greenLight = !m_greenLight;
	}
	if (m_greenLight) {
		// Truck
		if (m_xetai) {
			for (int i = 0; i < LINE_TRUCK; ++i) {
				if (m_xetai[i]) {
					for (int j = 0; j < COL_TRUCK; ++j) {
						m_xetai[i][j].MoveLeft();
					}
				}
			}
		}
		// Car
		if (m_xehoi) {
			for (int i = 0; i < LINE_CAR; ++i) {
				if (m_xehoi[i]) {
					for (int j = 0; j < COL_CAR; ++j) {
						m_xehoi[i][j].MoveLeft();
					}
				}
			}
		}
	}
	++m_clockLight;
	if (m_clockLight > 100) {
		m_clockLight = 1;
	}
}

bool Game::isHit()
{
	// Dinasour
	if (m_klong) {
		for (int i = 0; i < LINE_DINA; ++i) {
			if (m_klong[i]) {
				for (int j = 0; j < COL_DINA; ++j) {
					if (m_nvat.isHit(&m_klong[i][j])) {
						return true;
					}
				}
			}
		}
	}
	// Bird
	if (m_chim) {
		for (int i = 0; i < LINE_BIRD; ++i) {
			if (m_chim[i]) {
				for (int j = 0; j < COL_BIRD; ++j) {
					if (m_nvat.isHit(&m_chim[i][j])) {
						return true;
					}
				}
			}
		}
	}
	// Truck
	if (m_xetai) {
		for (int i = 0; i < LINE_TRUCK; ++i) {
			if (m_xetai[i]) {
				for (int j = 0; j < COL_TRUCK; ++j) {
					if (m_nvat.isHit(&m_xetai[i][j])) {
						return true;
					}
				}
			}
		}
	}
	// Car
	if (m_xehoi) {
		for (int i = 0; i < LINE_CAR; ++i) {
			if (m_xehoi[i]) {
				for (int j = 0; j < COL_CAR; ++j) {
					if (m_nvat.isHit(&m_xehoi[i][j])) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Game::isLive()
{
	return m_nvat.isLive();
}

void Game::Win()
{
	m_nvat.Reset();
	ClearObj();
	NextLevel();
}

void Game::Lose()
{
	m_nvat.Die();
	// Write goodbye
	ToaDo(0, HEIGHT_BOARD).GotoXY();
	setColor(LIGHTRED);
	cout << "You failed, press Y to reset game or any key to exit\n";
	setColor(WHITE);
	// Make sure obj go away
	DelObj();
}

void Game::NextLevel()
{
	++m_level;
	if (m_level > 5) {
		m_level = 1;
	}
	DelObj();
	CreObj(m_level);
	// Rewrite level
	ToaDo(WIDTH_BOARD + 2, 2).GotoXY();
	cout << "Level: " << m_level;
}

void Game::Save(const string &saveFile)
{
	ofstream outF(saveFile, ios::out | ios::binary);
	outF << m_nvat;
	outF << m_greenLight << " " << m_clockLight << endl;
	outF << m_level << endl;
	// Dina
	outF << COL_DINA << " " << COL_BIRD << " " << COL_TRUCK << " "
	     << COL_CAR << endl;
	if (m_klong) {
		for (int i = 0; i < LINE_DINA; ++i) {
			if (m_klong[i]) {
				for (int j = 0; j < COL_DINA; ++j) {
					outF << m_klong[i][j].getRoot() << " "
					     << m_klong[i][j].getPrev() << " ";
				}
			}
			outF << endl;
		}
	}
	if (m_chim) {
		for (int i = 0; i < LINE_BIRD; ++i) {
			if (m_chim[i]) {
				for (int j = 0; j < COL_BIRD; ++j) {
					outF << m_chim[i][j].getRoot() << " "
					     << m_chim[i][j].getPrev() << " ";
				}
			}
			outF << endl;
		}
	}
	if (m_xetai) {
		for (int i = 0; i < LINE_TRUCK; ++i) {
			if (m_xetai[i]) {
				for (int j = 0; j < COL_TRUCK; ++j) {
					outF << m_xetai[i][j].getRoot() << " "
					     << m_xetai[i][j].getPrev() << " ";
				}
			}
			outF << endl;
		}
	}
	if (m_xehoi) {
		for (int i = 0; i < LINE_CAR; ++i) {
			if (m_xehoi[i]) {
				for (int j = 0; j < COL_CAR; ++j) {
					outF << m_xehoi[i][j].getRoot() << " "
					     << m_xehoi[i][j].getPrev() << " ";
				}
			}
			outF << endl;
		}
	}
	outF.close();
}

void Game::Load(const string &saveFile)
{
	ifstream inF(saveFile, ios::in | ios::binary);
	if (!inF.is_open()) {
		return;
	}
	inF >> m_nvat;
	inF >> m_greenLight >> m_clockLight;
	inF >> m_level;
	inF >> COL_DINA >> COL_BIRD >> COL_TRUCK >> COL_CAR;
	// Load game right now
	clearScreen();
	DrawOnly();
	DelObj();
	CreObj(m_level);
	ToaDo temp;
	for (int i = 0; i < LINE_DINA; ++i) {
		for (int j = 0; j < COL_DINA; ++j) {
			inF >> temp;
			m_klong[i][j].setRoot(temp);
			inF >> temp;
			m_klong[i][j].setPrev(temp);
		}
	}
	for (int i = 0; i < LINE_BIRD; ++i) {
		for (int j = 0; j < COL_BIRD; ++j) {
			inF >> temp;
			m_chim[i][j].setRoot(temp);
			inF >> temp;
			m_chim[i][j].setPrev(temp);
		}
	}
	for (int i = 0; i < LINE_TRUCK; ++i) {
		for (int j = 0; j < COL_TRUCK; ++j) {
			inF >> temp;
			m_xetai[i][j].setRoot(temp);
			inF >> temp;
			m_xetai[i][j].setPrev(temp);
		}
	}
	for (int i = 0; i < LINE_CAR; ++i) {
		for (int j = 0; j < COL_CAR; ++j) {
			inF >> temp;
			m_xehoi[i][j].setRoot(temp);
			inF >> temp;
			m_xehoi[i][j].setPrev(temp);
		}
	}
	inF.close();
	run = true;
}

int Game::Menu()
{
	setColor(WHITE);
	// Dau game
	if (!run) {
		bool validInput = false;
		int input;
		while (!validInput) {
			clearScreen();
			ToaDo(0, 0).GotoXY();
			cout << "********************************" << endl;
			cout << "*   Press any key to New game  *" << endl;
			cout << "*   Press T to       Load game *" << endl;
			cout << "*   Press S to       Settings  *" << endl;
			cout << "*   Press ESC to     Exit      *" << endl;
			cout << "********************************" << endl;
			input = _getch();
			input = toupper(input);
			if (input == 'T') {
				clearScreen();
				cout << "Input name of saved file: ";
				string saveFile;
				cin >> saveFile;
				ifstream saveStream(saveFile,
						    ios::in | ios::binary);
				if (!saveStream.is_open()) {
					clearScreen();
					cout << "Can find saved file" << endl;
					cout << "Please press any key to back "
						"menu"
					     << endl;
					input = _getch();
					input = toupper(input);
				} else {
					Load(saveFile);
					validInput = true;
				}
			} else if (input == 'S') {
				clearScreen();
				cout << "Please press M to Mute sound or "
					"anykey to return menu"
				     << endl;
				input = _getch();
				input = toupper(input);
				if (input == 'M') {
					return 1;
				}
			} else if (input == ESC) {
				clearScreen();
				return -1;
			} else {
				Start();
				validInput = true;
			}
		}
	}
	// Trong game
	else {
		bool validInput = false;
		int input;
		while (!validInput) {
			clearScreen();
			ToaDo(0, 0).GotoXY();
			cout << "**********************************" << endl;
			cout << "*   Press any key to Resume game *" << endl;
			cout << "*   Press T to       Load game   *" << endl;
			cout << "*   Press L to       Save game   *" << endl;
			cout << "*   Press ESC to     Exit        *" << endl;
			cout << "**********************************" << endl;
			input = _getch();
			input = toupper(input);
			if (input == 'T') {
				clearScreen();
				cout << "Input name of saved file: ";
				string saveFile;
				cin >> saveFile;
				ifstream saveStream(saveFile,
						    ios::in | ios::binary);
				if (!saveStream.is_open()) {
					clearScreen();
					cout << "Can find saved file" << endl;
					cout << "Please press any key to back "
						"menu"
					     << endl;
					input = _getch();
					input = toupper(input);
				} else {
					Load(saveFile);
					validInput = true;
				}
			} else if (input == 'L') {
				clearScreen();
				cout << "Input name to save game: ";
				string saveFile;
				cin >> saveFile;
				Save(saveFile);
				validInput = true;
				clearScreen();
				setColor(WHITE);
				DrawOnly();
			} else if (input == ESC) {
				clearScreen();
				return -1;
			} else {
				clearScreen();
				setColor(WHITE);
				DrawOnly();
				validInput = true;
			}
		}
	}
	return 0;
}

void Game::Logo()
{
}

// Game specific
void Game::Start()
{
	setColor(WHITE);
	clearScreen();
	DrawOnly();
	Reset();
	run = true;
}

void Game::Exit(thread &t)
{
	run = false;
	TerminateThread(t.native_handle(), 0);
	if (t.joinable()) {
		t.join();
	}
	DelObj();
	clearScreen();
}

void Game::Pause(HANDLE handle_t)
{
	SuspendThread(handle_t);
}

void Game::Resume(HANDLE handle_t)
{
	while (ResumeThread(handle_t) > 0)
		;
}
