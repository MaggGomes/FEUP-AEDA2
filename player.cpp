#include "player.h"

Player::Player(string boardFilename, string playerName) : board(Board(boardFilename))
{
    name = playerName;
}

string Player::getPlayerNam() const
{
		return name;
}

void Player::showBoard() const
{
	board.display();
}

/*Bomb Player::getBomb() const
{

}

void Player::attackBoard(const Bomb &b)
{

}*/
