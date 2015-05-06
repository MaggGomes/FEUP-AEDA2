#include "player.h"

// FALTA COMPLETAR

Player::Player(string playerName, string boardFilename) // corrigir este construtor
{
	string infilename;
do
	{
		cout << "NOME FICHEIRO CONFIGURACAO: ";
		getline(cin, filename);
		leficheiro.open(filename);
		if (!leficheiro.fail())
			cout << "Ficheiro aberto com sucesso!" << endl << endl;
		else
			cout << "Ficheiro inexistente! Tente novamente." << endl << endl;
		setcolor(7, 0);
	} while (leficheiro.fail());
	
}

/*void Player::showBoard() const
{

}

Bomb Player::getBomb() const
{

}

void Player::attackBoard(const Bomb &b)
{

}
*\