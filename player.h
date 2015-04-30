#ifndef player_h
#define player_h

#include "bomb.h"
#include "board.h"

class Player
{
public:
	Player();
	Player(string playerName, string boardFilename);
	void showBoard() const; // mostra o tabuleiro do jogador
	Bomb getBomb() const; // pergunta pelas coordenadas da bomba e coloca bomba
	void attackBoard(const Bomb &b); // ""recebe" a bomba do adversário
	// atualiza o tabuleiro tabuleiro tendo em conta o dano da bomba e se o navio se move
	
private:
	string name; // nome do jogador
	Board board; // tabuleiro do jogador
};

#endif