#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <cstddef>
#include "bomb.h"

using namespace std;

// códigos de cores

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// preenchimento com espaços
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// cursor no canto superior esquerdo
	SetConsoleCursorPosition(hCon, coordScreen);
}
//=============================================================
// Posiciona o cursor na coluna 'x', linha 'y'
// As coordenadas do canto superior esquerdo são (x,y)=(0,0)
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//=============================================================
// Definição da cor do texto
void setcolor(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
//=============================================================
// Definição da cor do texto & background
void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN |
		BACKGROUND_RED);
}

// =============================================================

// Declaração de funções

// Titulo do jogo
void impressaoTitulo()
{
	setcolor(3, 0);

	string titulo = "#############################################################################\n#    ____       _______ _______ _      ______  _____ _    _ _____ _____     #\n#   |  _ \\   /\\|__   __|__   __| |    |  ____|/ ____| |  | |_   _|  __ \\    #\n#   | |_) | /  \\  | |     | |  | |    | |__  | (___ | |__| | | | | |__) |   #\n#   |  _ < / /\\ \\ | |     | |  | |    |  __|  \\___ \\|  __  | | | |  ___/    #\n#   | |_) / ____ \\| |     | |  | |____| |____ ____) | |  | |_| |_| |        #\n#   |____/_/    \\_\\_|     |_|  |______|______|_____/|_|  |_|_____|_|        #\n#                                                                           #\n#############################################################################";

	//cout << nome1 << endl << nome2 << endl << nome3 << endl << nome4 << endl<< nome5 << endl << nome6 << endl;
	cout << titulo << endl << endl;

	setcolor(7, 0);
}

int main()
{
	string infilename; // ficheiro de entrada
	string outfilename; // ficheiro de saida
	string modo_funcionamento; // modo funcionamento
	ifstream leficheiro; // objeto para abertura dos ficheiros de configuração
	ofstream escreveficheiro; // grava os dados das posições dos barcos no ficheiro selecionado
	vector < vector <char> > coordenadas = // vector com as coordenadas
	{ { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' } };

	impressaoTitulo(); // imprime título do jogo

	cout << "Bem-vindo ao jogo Battleship!" << endl << endl;

	Bomb bomba;

	bomba.getTargetPosition();

	cout << endl;
	
	bomba.show();

	return 0;
}
