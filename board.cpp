#include "board.h"

Board::Board(const string &filename)
{
	ifstream leficheiro(filename); // l� ficheiro com as configura��es do tabuleiro
	char operatorX; // string que absorve elemento sem import�ncia da primeira linha do ficheiro

	// valores para guardar no vector ships
	char symbol, orientation;
	PositionChar positchar;
	PositionInt positint;
	unsigned int color, size;

	// FALTA VERIFICA SYMBOL

	leficheiro >> numLines >> operatorX >> numColumns; // le a primeira linha de c�digo que tem as coordenadas da linhas e colunas

	while (!leficheiro.eof()) // l� ficheiro de configura��o enquanto n�o chega ao fim do mesmo
	{
		leficheiro >> symbol >> size >> positchar.lin >> positchar.col >> orientation >> color; // l� valores do navio da primeira linha de texto do ficheiro de configura��o
		positint.lin = positchar.lin - 65; // converte de char mai�scula para int
		positint.col = positchar.col - 97; // converte de char min�scula para int

		Ship navio(symbol, positint, orientation, size, color);

		ships.push_back(navio);
	}

	vector <vector <int>> tabuleiro(numLines, vector <int>(numColumns));
	
	leficheiro.close();
}

bool Board::putShip(const Ship &s)
{
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
	// mostra tabuleiro
}