#include <iostream>
#include <string>
#include <windows.h>
#include <cstddef>)

#include "functions.h"
#include "variables.h"

// Implementa��o das fun��es

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// preenchimento com espa�os
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// cursor no canto superior esquerdo
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

	//cout << nome1 << endl << nome2 << endl << nome3 << endl << nome4 << endl<< nome5 << endl << nome6 << endl;
	cout << titulo << endl << endl;

	setcolor(7, 0);

	cout << "Bem-vindo ao jogo Battleship!" << endl << endl;
}

unsigned int getlinha(char &linha, const vector < vector <char> > &coordenadas)
{
	unsigned int intlinha;

	for (size_t i = 0; i < coordenadas.at(0).size(); i++)
	{
		if (linha == coordenadas[1][i])
		{
			intlinha = i + 1;
			break;
		};
	}

	return intlinha;
}

unsigned int getcoluna(char &coluna, const vector < vector <char> > &coordenadas)
{
	unsigned int intcoluna;

	for (size_t j = 0; j < coordenadas.at(0).size(); j++)
	{
		if (coluna == coordenadas[0][j])
		{
			intcoluna = j + 1;
		}
	}
	
	return intcoluna;
}

char getlowercase(char symbol, const vector < vector <char> > &coordenadas)
{
	char symblowercase; // inicializa��o da vari�vel simbolo em letra min�scula

	for (size_t i = 0; i < coordenadas.at(0).size(); i++) //
	{
		if (symbol == coordenadas[1][i])
		{
			symblowercase = coordenadas[0][i];
		}
	}

	return symblowercase; // devolve simbolo em letra min�scula
}
