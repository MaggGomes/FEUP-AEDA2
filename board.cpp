#include <iostream>

#include "board.h"
#include "ship.h"

Board::Board()
{
	vector<Ship> navios;
	vector<vector<int>> tab;

	numLines = 0;
	numColumns = 0;
	ships = navios;
	board = tab;
}

Board::Board(const string &filename)
{
	ifstream readfile(filename); // Lê ficheiro com as configurações do tabuleiro
	char operatorX; // String que absorve elemento sem importância da primeira linha do ficheiro

	// Valores para guardar no vector ships
	char symbol, orientation;
	PositionChar positionchar;
	unsigned int color, size;

	readfile >> numLines >> operatorX >> numColumns; // Lê a primeira linha de código que tem as dimensões do tabuleiro

	while (!readfile.eof()) // Lê ficheiro de configuração enquanto não chega ao fim do mesmo
	{
		readfile >> symbol >> size >> positionchar.lin >> positionchar.col >> orientation >> color; // lê valores do navio da primeira linha de texto do ficheiro de configuração

		Ship navio(symbol, positionchar, orientation, size, color); // Constrói objeto da classe Ship com as suas características
		ships.push_back(navio);
	}

	readfile.close();

	vector <vector <int>> boardtemp(numLines, vector <int>(numColumns, -1)); // Cria tabuleiro temporário a partir do ficheiro de configurações, onde -1 representa o mar
	board = boardtemp; // Atribui valores ao parâmetro board da class Board
}

int Board::getLines() const
{
	return numLines; // Devolve número de linhas do tabuleiro
}

int Board::getColumns() const
{
	return numColumns; // Devolve número de colunas do tabuleiro
}

bool Board::putShip(const Ship &s)
{
	int x = (int)s.position.lin - 65;
	int y = (int)s.position.col - 97;


	if (s.orientation == 'H')
	{
		if ((x > numLines) || (y + s.size - 1 > numColumns))
			return false;
		else
		{
			for (size_t i = 0; i < s.size; i++)
			{
				if (board[x][y + i] != -1)
					return false;
			}

		}

		return true;
	}
	else if (s.orientation == 'V')
	{
		if ((x + s.size - 1 > numLines) || (y > numColumns))
			return false;
		else
		{
			for (size_t i = 0; i < s.size; i++)
			{
				if (board[x + i][y] != -1)
					return false;
		}

		}
	}

}

void Board::moveShips() // FALTA TESTAR
{
	ships[0i.moveRand(0, 0, numLines, numColumns);
	\S

	/*for (size_t i = 0; ships[i] < ships.size; i++)
		if ((ships[i].moveRand(0, 0, numLines, numColumns)) == true*/
			
}


bool Board::attack(const Bomb &b) // FALTA COMPLETAR
{
	PositionInt coordbombanum;
	coordbombanum.lin = b.getTargetPosition().lin - 65; // Coordenada da linha em formato unsigned int
	coordbombanum.col = b.getTargetPosition().col - 97; // Coordenada da coluna em formato unsigned int

	if (board[coordbombanum.lin][coordbombanum.col] == -1)
	{
		cout << "FALHOU O ALVO!!" << endl;
		return false;
	}

	else if (coordbombanum.lin < 0 || coordbombanum.col < 0 || coordbombanum.lin >= numLines || coordbombanum.col >= numColumns)
	{
		cout << "FALHOU O ALVO!!" << endl;
		return false;
	}
	else
	{

		if 



		board[coordbombanum.lin][coordbombanum.col]


	}
}

/*
void Board::display() const
{
// Mostra tabuleiro
}

void Board::show() const
{
// Mostra tabuleiro
}*/