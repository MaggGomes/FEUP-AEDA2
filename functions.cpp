#include <iostream>
#include <string>
#include <windows.h>
#include <cstddef>
#include <ctime>
#include <fstream>

#include "functions.h"
#include "variables.h"

using namespace std;

// Implementação das funções

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // Canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Preenchimento com espaços
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// Cursor no canto superior esquerdo
	SetConsoleCursorPosition(hCon, coordScreen);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void impressaoTitulo()
{
	setcolor(3, 0);

	string titulo = "#############################################################################\n#    ____       _______ _______ _      ______  _____ _    _ _____ _____     #\n#   |  _ \\   /\\|__   __|__   __| |    |  ____|/ ____| |  | |_   _|  __ \\    #\n#   | |_) | /  \\  | |     | |  | |    | |__  | (___ | |__| | | | | |__) |   #\n#   |  _ < / /\\ \\ | |     | |  | |    |  __|  \\___ \\|  __  | | | |  ___/    #\n#   | |_) / ____ \\| |     | |  | |____| |____ ____) | |  | |_| |_| |        #\n#   |____/_/    \\_\\_|     |_|  |______|______|_____/|_|  |_|_____|_|        #\n#                                                                           #\n#############################################################################";

	cout << titulo << endl << endl;

	setcolor(7, 0);

	cout << endl;
}

char randomPosition() // (0=“no move”, 1=‘N’, 2=‘S’, 3=’E’, 4=’W’)
{
	char changeposition = '0'; // Variável a devolver que indica se houve mudança de posição ou não e se sim em que sentido
	srand((unsigned int)time(NULL)); // Permite gerar números aleatórios

	int move = rand() % 5; // Se 0 (não altera posição: '0') 1(+1: 'N') 2(+1: 'S') 3(+1: 'E') 4(+1: 'W')
	switch (move)
	{
	case 0:
		changeposition = '0';
		break;
	case 1:
		changeposition = 'N';
		break;
	case 2:
		changeposition = 'S';
		break;
	case 3:
		changeposition = 'E';
		break;
	case 4:
		changeposition = 'W';
		break;
	}

	return changeposition;
}

bool rotation() // Roda o navio (true=roda,false=mantém a orientação)
{
	bool rotate = true; // Variável a devolver que indica se a orientação será ou não alterada
	srand((unsigned int)time(NULL));

	int change = rand() % 2; // Caso seja 0 o navio "roda", caso seja 1 o navio mantém a orientação
	switch (change)
	{
	case 0:
		rotate = true;
		break;
	case 1:
		rotate = false;
		break;
	}

	return rotate;
}

string getPlayername()
{
	string playerName;

	do
	{
		cout << ">> NICKNAME JOGADOR (entre 3 e 8 caracteres): ";
		getline(cin, playerName);

		if (cin.fail() || playerName.length() < 3 || playerName.length() > 8)
		{
			setcolor(4, 0);
			cout << ":: ERRO: Nickname invalido! Tente novamente." << endl << endl;
			setcolor(7, 0);
		}
	
		else
		{
			setcolor(2, 0);
			cout << ":: Nickname guardado com sucesso!" << endl << endl;
			setcolor(7, 0);
		}
	} while (cin.fail() || playerName.length() < 3 || playerName.length() > 8);

	return playerName;
}

string getFilename()
{
	string filename;
	ifstream readfile;

	do
	{
		cout << ">> NOME FICHEIRO CONFIGURACAO: ";
		getline(cin, filename);
		readfile.open(filename);

		if (!readfile.fail())
		{
			setcolor(2, 0);
			cout << ":: Ficheiro aberto com sucesso!" << endl << endl;
			setcolor(7, 0);
		}
		else
		{
			setcolor(4, 0);
			cout << ":: ERRO: Ficheiro inexistente! Tente novamente." << endl << endl;
			setcolor(7, 0);
		}
	} while (readfile.fail());

	readfile.close();

	return filename;
}
