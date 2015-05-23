#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

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

Bomb Player::getBomb() const
{
	cout << board;
	
	string coord;
	Position<char> pos;
	
	do
	{
		clrscr();
		cout << board;
		cout << ">> COORDENADAS A ATACAR (Linha " << coordenadas.at(1).at(0) << ".." << coordenadas.at(1).at(board.getLines() - 1) << ") (Coluna " << coordenadas.at(0).at(0) << ".." << coordenadas.at(0).at(board.getColumns() - 1) << ") : ";
		cin >> coord;

		if (validCoord(coord))
		{
			setcolor(2, 0);
			cout << ":: Coordenadas inseridas com sucesso!" << endl << endl;
			setcolor(7, 0);
			Sleep(1200);
		}
		
		else
		{
			setcolor(4, 0);
			cout << ":: ERRO: Coordenadas invalidas! Reintroduza coordenadas." << endl << endl;
			setcolor(7, 0);
			Sleep(1400);
		}
	} while (!validCoord(coord));
	
	pos.lin = coord.at(0);
	pos.col = coord.at(1);

	Bomb bomba(pos);
	
	return bomba;
}

void Player::attackBoard(const Bomb &b)
{	
	board.moveShips(); // Faz mover os navios aleatoriamente
	cout << board; // Mostra os navios após movimento aleatório dos mesmos

	if (board.attack(b))
	{
		setcolor(2, 0);
		cout << ":: RESULTADO: Bom tiro! Acertou no navio!" << endl << endl;
		Sleep(1000);
		setcolor(7, 0);
		cout << board;
		Sleep(1000);
	}

	else
	{
		setcolor(4, 0);
		cout << ":: RESULTADO: Falhou o alvo." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
	}

	cout << board;
}

Board Player::getBoard() const
{
	return board;
}

bool Player::fleetDestroyed()
{
	if (board.getShipstatus())
		return true;
	else
		return false;
}