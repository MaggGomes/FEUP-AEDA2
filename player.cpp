#include "player.h"

Player::Player(string playerName, string boardFilename) // FALTA - corrigir este construtor
{
    name = playerName;
	Board board(boardFilename);
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
