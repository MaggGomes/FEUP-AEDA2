#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "bomb.h"
#include "board.h"

class Player
{
public:
	Player(string boardFilename, string playerName);
	string getPlayerName() const; // Mostra nome do jogador (para debugging)
	void showBoard() const;       // Mostra o tabuleiro do jogador
	void boardDebug() const; // Mostra o tabuleiro do jogador para debuging
	bool validCoord(string &coordenada) const; // Valida as coordenadas da bomba inseridas pelo utilizador
	Bomb getBomb() const;         // Pergunta pelas coordenadas da bomba e coloca bomba
	void attackBoard(const Bomb &b); // "Recebe" a bomba do adversário
	// Atualiza o tabuleiro tabuleiro tendo em conta o dano da bomba e se o navio se move
	void move(); // APAGAR - VERSAO PARA TESTAR MOVESHIPS
	Board getBoard() const; // devolve o tabuleiro

private:
	string name; // Nome do jogador
	Board board; // Tabuleiro do jogador
};

#endif // PLAYER_H