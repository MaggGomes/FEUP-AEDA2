#include "board.h"
#include "bomb.h"

Board::Board()
{
	// Default constructor
}

Board::Board(const string &filename) 
{
	ifstream readfile(filename); // L� ficheiro com as configura��es do tabuleiro
	char operatorX; // String que absorve elemento sem import�ncia da primeira linha do ficheiro

	// Valores para guardar no vector ships
	char symbol, orientation;
	PositionChar positionchar;
	unsigned int color, size;

	readfile >> numLines >> operatorX >> numColumns; // L� a primeira linha de c�digo que tem as dimens�es do tabuleiro

	while (!readfile.eof()) // L� ficheiro de configura��o enquanto n�o chega ao fim do mesmo
	{
		readfile >> symbol >> size >> positionchar.lin >> positionchar.col >> orientation >> color; // l� valores do navio da primeira linha de texto do ficheiro de configura��o

		Ship navio(symbol, positionchar, orientation, size, color); // constr�i objeto da classe Ship com as suas caracter�sticas
		ships.push_back(navio);
	}

	readfile.close();
	
	vector <vector <int>> boardtemp(numLines, vector <int>(numColumns, -1)); // Cria tabuleiro tempor�rio a partir do ficheiro de configura��es, onde -1 representa o mar
	board = boardtemp; // Atribui valores ao par�metro board da class Board
}

int Board::getLines() const
{
	return numLines; // Devolve n�mero de linhas do tabuleiro
}

int Board::getColumns() const
{
	return numColumns; // Devolve n�mero de colunas do tabuleiro
}

/*bool Board::putShip(const Ship &s)
{
	/*
	int x = (int)s.position.lin - 65;
	int y = (int)s.position.col - 97;

	if (s.orientation == 'H')
	if ((x <= numLines) && (y + s.size <= numColumns))
	for ()
	else if (s.orientation == 'V')

	// Method putShip() must update both the board and the ships attributes of the class.If the ship does not fit inside the board or collides with other already placed ship(s) those attributes must not be updated and the function must return false, returning true otherwise.
	
}

void Board::moveShips()
{
	// Move navios
}
bool Board::attack(const Bomb &b)
{
	// Coloca bomba no tabuleiro
}

void Board::display() const
{
	// Mostra tabuleiro
}

void Board::show() const
{
	// Mostra tabuleiro
}*/