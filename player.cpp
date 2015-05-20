#include "player.h"
#include "bomb.h"
#include "board.h"

Player::Player(string boardFilename, string playerName) : board(Board(boardFilename))
{
    name = playerName;
}

string Player::getPlayerName() const
{
	return name;
}

void Player::showBoard() const
{
	board.display();
}

Bomb Player::getBomb() const
{
	char x, y;
	Position<char> pos;

	cout << "Coordenadas a atacar? \n";
	cin >> x >> y;
	//FALTA VERIFICAR SE AS COORDENADAS ESTAO CORRETAS

	pos.lin = x;
	pos.col = y;

	Bomb bomba(pos);
		
	return bomba;
}

void Player::attackBoard(const Bomb &b)
{
	board.attack(b);
}
