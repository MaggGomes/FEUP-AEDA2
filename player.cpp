#include "player.h"
#include "bomb.h"
#include "board.h"
#include "functions.h"

Player::Player(string boardFilename, string playerName) : board(Board(boardFilename))
{
    name = playerName;
	board.setBoard(); //Coloca os navios inicialmente no tabuleiro
}

string Player::getPlayerName() const
{	
	return name;
}

void Player::showBoard() const
{
	board.display();
}

void Player::boardDebug() const
{
	board.show();
}

bool Player::validCoord(string &coordenada) const
{
	int nl = board.getLines();
	int nc = board.getColumns();
	int x, y;
	bool validade = false;

	if (coordenada.length() == 2)
	{
		x = (int)coordenada.at(0) - 65;
		y = (int)coordenada.at(1) - 97;

		if ((0 <= x) && (x < nl) && (0 <= y) && (y < nc))
			validade = true;
	}

	return validade;
}

Bomb Player::getBomb() const
{
	string coord;
	Position<char> pos;

	do
	{
		cout << ">> COORDENADAS A ATACAR: ";
		cin >> coord;

		if (validCoord(coord))
		{
			setcolor(2, 0);
			cout << ":: Coordenadas inseridas com sucesso!" << endl << endl;
			setcolor(7, 0);
		}
		
		else
		{
			setcolor(4, 0);
			cout << ":: ERRO: Coordenadas invalidas! Reintroduza coordenadas." << endl << endl;
			setcolor(7, 0);
		}
	} while (!validCoord(coord));
	
	pos.lin = coord.at(0);
	pos.col = coord.at(1);

	Bomb bomba(pos);
	
	return bomba;
}

void Player::attackBoard(const Bomb &b) // FALTA TESTAR
{
	board.attack(b);
}
