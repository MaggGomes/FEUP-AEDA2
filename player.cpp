#include "player.h"
#include "bomb.h"
#include "board.h"

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

/*Bomb Player::getBomb() const
{
	/*string coord, x, y;
	Position<char> pos;
	bool temp;

	cout << "Coordenadas a atacar? \n";
	cin >> coord;
   

	pos.lin = x;
	pos.col = y;

	Bomb bomba(pos);
		
	return bomba;
}*/



bool Player::validcoord(string &pos) // FALTA TESTAR
{
	int nl = board.getLines();
	int nc = board.getColumns();
	int x, y;
	bool validade = false;

	if (pos.length() == 2)
	{
		x = (int)pos.at(0) - 65;
		y = (int)pos.at(1) - 97;

		if ((0 <= x) && (x < nl) && (0 <= y) && (y < nc))
		{

		}
	}

	return validade;
}


void Player::attackBoard(const Bomb &b) // FALTA TESTAR
{
	board.attack(b);
}
