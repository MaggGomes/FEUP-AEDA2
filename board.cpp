#include "board.h"
#include "bomb.h"

Board::Board(const string &filename) 
{
	ifstream readfile(filename); // lê ficheiro com as configurações do tabuleiro
	char operatorX; // string que absorve elemento sem importância da primeira linha do ficheiro

	// valores para guardar no vector ships
	char symbol, orientation;
	PositionChar positionchar;
	unsigned int color, size;

	readfile >> numLines >> operatorX >> numColumns; // lê a primeira linha de código que tem as dimensões do tabuleiro

	while (!readfile.eof()) // lê ficheiro de configuração enquanto não chega ao fim do mesmo
	{
		readfile >> symbol >> size >> positionchar.lin >> positionchar.col >> orientation >> color; // lê valores do navio da primeira linha de texto do ficheiro de configuração

		Ship navio(symbol, positionchar, orientation, size, color); // constrói objeto da classe Ship com as suas características
		ships.push_back(navio);
	}

	readfile.close();
	
	vector <vector <int>> boardtemp(numLines, vector <int>(numColumns, -1)); // cria tabuleiro temporário a partir do ficheiro de configurações, onde -1 representa o mar
	board = boardtemp; // atribui valores ao parâmetro board da class Board
}

int Board::getLines() const
{
	return numLines;
}

int Board::getColumns() const
{
	return numColumns;
}

bool Board::putShip(const Ship &s)
{
	/*
	int x = (int)s.position.lin - 65;
	int y = (int)s.position.col - 97;

	if (s.orientation == 'H')
	if ((x <= numLines) && (y + s.size <= numColumns))
	for ()
	else if (s.orientation == 'V')

	// Method putShip() must update both the board and the ships attributes of the class.If the ship does not fit inside the board or collides with other already placed ship(s) those attributes must not be updated and the function must return false, returning true otherwise.
	*/
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
	// mostra tabuleiro
}

void Board::show() const
{
	// mostra tabuleiro
}