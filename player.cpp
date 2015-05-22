#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	cout << board;
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

	if (coordenada.length() == 2) // Verfica se o input tem o comprimento correto (2 letras para as coordenadas)
	{
		x = (int)coordenada.at(0) - 65;
		y = (int)coordenada.at(1) - 97;

		if ((0 <= x) && (x < nl) && (0 <= y) && (y < nc)) // Verfica se as letras do input são coordenadas possíveis do tabuleiro
			validade = true;
	}
	return validade;
}

void Player::move() // APAGAR - VERSAO PARA TESTAR MOVESHIPS
{
	srand(time(NULL));
	board.moveShips();
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
	if (board.attack(b))
	{
		setcolor(2, 0);
		cout << ":: RESULTADO: Bom tiro! Acertou no navio!" << endl << endl;
		setcolor(7, 0);
	}

	else
	{
		setcolor(4, 0);
		cout << ":: RESULTADO: Falhou o alvo." << endl << endl;
		setcolor(7, 0);
	}
}

Board Player::getBoard() const
{
	return board;
}