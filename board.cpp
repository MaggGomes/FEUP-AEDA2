#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#include "board.h"
#include "ship.h"
#include "functions.h"

Board::Board(const string &filename)
{
	ifstream readfile(filename); // Lê ficheiro com as configurações do tabuleiro
	char operatorX; // String que absorve elemento sem importância da primeira linha do ficheiro

	// Valores para guardar no vector ships
	char symbol, orientation;
	Position<char> positionchar;
	unsigned int color, size;

	readfile >> numLines >> operatorX >> numColumns; // Lê a primeira linha de código que tem as dimensões do tabuleiro

	while (!readfile.eof()) // Lê ficheiro de configuração enquanto não chega ao fim do mesmo
	{
		readfile >> symbol >> size >> positionchar.lin >> positionchar.col >> orientation >> color; // lê valores do navio da primeira linha de texto do ficheiro de configuração

		Ship navio(symbol, positionchar, orientation, size, color); // Constrói objeto da classe Ship com as suas características
		ships.push_back(navio);
	}

	readfile.close();

	vector <vector <int>> boardTemp(numLines, vector <int>(numColumns, -1)); // Cria tabuleiro temporário a partir do ficheiro de configurações, onde -1 representa o mar
	board = boardTemp; // Atribui valores ao parâmetro board da class Board
}

int Board::getLines() const
{
	return numLines; // Devolve número de linhas do tabuleiro
}

int Board::getColumns() const
{
	return numColumns; // Devolve número de colunas do tabuleiro
}

bool Board::putShip(const Ship &s, vector<vector<int>> &b, const int &i)
{
// Verifica se o navio a colocar fica sobre outro navio

	if (s.getOrientation() == 'H')
	{
		for (size_t j = 0; j < s.getSize(); j++)
		{
			if ((s.getPosition().col + j) >= numColumns)
				return false;

			if (b.at(s.getPosition().lin).at(s.getPosition().col + j) != -1)
				return false;
		}

		for (size_t k = 0; k < s.getSize(); k++)
		{
			if ((s.getPosition().col + k) >= numColumns)
				return false;

			b.at(s.getPosition().lin).at(s.getPosition().col + k) = i;
		}
		return true;
	}

	else if (s.getOrientation() == 'V')
	{

		for (size_t j = 0; j < s.getSize(); j++)
		{
			if ((s.getPosition().lin + j) >= numLines)
				return false;

			if (b.at(s.getPosition().lin + j).at(s.getPosition().col) != -1)
				return false;
		}
		
		for (size_t k = 0; k < s.getSize(); k++)
		{
			if ((s.getPosition().lin + k) >= numLines)
				return false;

			b.at(s.getPosition().lin + k).at(s.getPosition().col) = i;
		}
		return true;
	}
	return true;
}

void Board::setBoard()
{
	for (size_t i = 0; i < ships.size(); i++)
	{
		putShip(ships.at(i), board, i);
	}
}

vector<Ship> Board::getShips() // devolve o vetor de navios do
{
	return ships;
}

void Board::moveShips()
{
	srand(time(NULL)); // Permite gerar números aleatórios
	vector<Ship> shipsTemp = ships; // Cria vector ships temporário
	vector <vector <int>> boardTemp(numLines, vector <int>(numColumns, -1)); // Cria tabuleiro temporário
	bool validade = true;
	
	for (size_t i = 0; i < shipsTemp.size(); i++) // Altera posição/orientação dos navios de forma aleatória
		shipsTemp.at(i).moveRand(0, 0, numLines, numColumns);
	
	for (size_t i = 0; i < shipsTemp.size(); i++)
	{		
		if (!putShip(shipsTemp.at(i), boardTemp, i)) // Verifica se é possível colocar os navios
		{
			validade = false;
			break;
		}
	}

	if (validade) // Se tiver sido possível colocar os barcos no tabuleiro após a sua alteraão de posição,
	{	 	      // então são alterados os vectores ships e board
			ships = shipsTemp;
			board = boardTemp;
			setcolor(3, 0);
			cout << ":: ATENCAO! Os navios inimigos preparam-se para se mover!";
			setcolor(7, 0);
			Sleep(2000);		
	}
}

bool Board::attack(const Bomb &b)
{
	Position <unsigned int> coordBomba;
	coordBomba.lin = b.getTargetPosition().lin - 65; // Coordenada da linha em formato unsigned int
	coordBomba.col = b.getTargetPosition().col - 97; // Coordenada da coluna em formato unsigned int
	size_t partNumber = 0; // Inicialização do índice da célula do navio que é atacada

	if (coordBomba.lin < 0 || coordBomba.lin >= numLines || coordBomba.col < 0 || coordBomba.col >= numColumns) // Verifica se a bomba é lançada para fora dos limites do tabuleiro
		return false;

	if (board.at(coordBomba.lin).at(coordBomba.col) == -1) // Verifica se a bomba é lançada ao mar
		return false;
	
	else if (coordBomba.lin < 0 || coordBomba.col < 0 || coordBomba.lin >= numLines || coordBomba.col >= numColumns) // Verifica se a bomba é lançada para fora do tabuleiro
	{
		return false;
	}

	else // Acertou um navio
	{
		if (ships.at(board.at(coordBomba.lin).at(coordBomba.col)).getOrientation() == 'H')
		{
			Position <unsigned int> position = ships.at(board.at(coordBomba.lin).at(coordBomba.col)).getPosition();
			int coordCol = coordBomba.col;

			while (coordCol > position.col)
			{
				partNumber++;
				coordCol = coordCol - 1;
			}
		}

		if (ships.at(board.at(coordBomba.lin).at(coordBomba.col)).getOrientation() == 'H')
		{
			Position <unsigned int> position = ships.at(board.at(coordBomba.lin).at(coordBomba.col)).getPosition();
			int coordLin = coordBomba.lin;

			while (coordLin > position.lin)
			{
				partNumber++;
				coordLin = coordLin - 1;
			}
		}

		ships.at(board.at(coordBomba.lin).at(coordBomba.col)).attack(partNumber); // Faz o "ataque" ao navio

		return true;
	}
}

bool Board::getShipstatus()
{
	bool destroyed = true;

	for (size_t i = 0; i < ships.size(); i++)
	{
		if (!ships.at(i).isDestroyed()) // Verifica navio a navio se todos estão destruídos
		{
			return destroyed = false;
		}
	}
	
	return destroyed;
}

void Board::display() const
{
	for (size_t i = 0; i < board.size(); i++) // Imprime coordenadas das colunas da primeira linha do tabuleiro
	{
		gotoxy(i * 2 + 3, 5);
		setcolor(15, 0);
		cout << coordenadas.at(0).at(i);
	}

	for (size_t i = 0; i < board.size(); i++) // Imprime coordenadas das linhas da primeira coluna do tabuleiro
	{
		gotoxy(1, i + 1 + 5);
		setcolor(15, 0);
		cout << coordenadas.at(1).at(i);
	}
	for (size_t i = 0; i < board.size(); i++) // Imprime segunda coluna vazia
	{
		gotoxy(2, i + 1 + 5);
		setcolor(0, 7);
		cout << " ";
	}

	for (size_t i = 0; i < numLines; i++) // Impressão do tabuleiro
	{
		for (size_t j = 0; j < numColumns; j++)
		{
			gotoxy(j * 2 + 3, i + 1 + 5);
			if (board.at(i).at(j) == -1)
			{
				setcolor(9, 7);
				cout << '.' << " "; // Impressão caso seja "mar" (-1)
			}

			else if (ships.at(board.at(i).at(j)).getOrientation() == 'H')
			{
				Position <unsigned int> position = ships.at(board.at(i).at(j)).getPosition();
				int coordCol = j;
				size_t partNumber = 0; // Índice da célula do barco "inicial"

				while (coordCol > position.col)
				{
					partNumber++;
					coordCol = coordCol - 1;
				}

				setcolor(ships.at(board.at(i).at(j)).getColor(), 7);
				cout << ships.at(board.at(i).at(j)).getStatus()[partNumber] << " ";
			}

			else if (ships.at(board.at(i).at(j)).getOrientation() == 'V')
			{
				Position <unsigned int> position = ships.at(board.at(i).at(j)).getPosition();
				int coordLin = i;
				size_t partNumber = 0; // Índice da célula do barco "inicial"

				while (coordLin > position.lin)
				{
					partNumber++;
					coordLin = coordLin - 1;
				}

				setcolor(ships.at(board.at(i).at(j)).getColor(), 7);
				cout << ships.at(board.at(i).at(j)).getStatus()[partNumber] << " ";
			}
		}
	}
	cout << endl << endl;
	setcolor(7, 0);
}

void Board::show() const
{
	int ll = (int)'A';
	int lc = (int)'a';

	cout << setw(2) << " ";
	for (int i = 0; i < numColumns; i++)
		cout << setw(2) << (char)(lc + i);
	cout << endl;

	for (int i = 0; i < numLines; i++)
	{
		cout << setw(2) << (char)(ll + i);
		for (int j = 0; j < numColumns; j++)
		{
			cout << setw(2) << board[i][j];
		}
		cout << endl;
	}
}

ostream& operator<<(ostream& os, const Board& tab)
{
	tab.display();
	return os;
}

void Board::preview() const
{
	for (size_t i = 0; i < board.size(); i++) // Imprime coordenadas das colunas da primeira linha do tabuleiro
	{
		gotoxy(i * 2 + 3, 22);
		setcolor(15, 0);
		cout << coordenadas.at(0).at(i);
	}

	for (size_t i = 0; i < board.size(); i++) // Imprime coordenadas das linhas da primeira coluna do tabuleiro
	{
		gotoxy(1, i + 1 + 22);
		setcolor(15, 0);
		cout << coordenadas.at(1).at(i);
	}
	for (size_t i = 0; i < board.size(); i++) // Imprime segunda coluna vazia
	{
		gotoxy(2, i + 1 + 22);
		setcolor(0, 7);
		cout << " ";
	}

	for (size_t i = 0; i < numLines; i++) // Impressão do tabuleiro
	{
		for (size_t j = 0; j < numColumns; j++)
		{
			gotoxy(j * 2 + 3, i + 1 + 22);
			if (board.at(i).at(j) == -1)
			{
				setcolor(9, 7);
				cout << '.' << " "; // Impressão caso seja "mar" (-1)
			}

			else if (ships.at(board.at(i).at(j)).getOrientation() == 'H')
			{
				Position <unsigned int> position = ships.at(board.at(i).at(j)).getPosition();
				int coordCol = j;
				size_t partNumber = 0; // Índice da célula do barco "inicial"

				while (coordCol > position.col)
				{
					partNumber++;
					coordCol = coordCol - 1;
				}

				setcolor(ships.at(board.at(i).at(j)).getColor(), 7);
				cout << ships.at(board.at(i).at(j)).getStatus()[partNumber] << " ";
			}

			else if (ships.at(board.at(i).at(j)).getOrientation() == 'V')
			{
				Position <unsigned int> position = ships.at(board.at(i).at(j)).getPosition();
				int coordLin = i;
				size_t partNumber = 0; // Índice da célula do barco "inicial"

				while (coordLin > position.lin)
				{
					partNumber++;
					coordLin = coordLin - 1;
				}

				setcolor(ships.at(board.at(i).at(j)).getColor(), 7);
				cout << ships.at(board.at(i).at(j)).getStatus()[partNumber] << " ";
			}
		}
	}
	cout << endl << endl;
	setcolor(7, 0);
}