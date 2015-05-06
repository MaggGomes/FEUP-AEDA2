#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <fstream>

#include "ship.h"
#include "bomb.h"

using namespace std;

class Board
{
public:
	Board();
	Board(const string &filename);   // carrega o tabuleiro do ficheiro 'filename'
	bool putShip(const Ship &s);     // adiciona um navio ao tabuleiro se possível
	void moveShips();                // tenta mover aleatoriamente todos os navios da frota
	bool attack(const Bomb &b);
	void display() const;            // mostra o tabuleiro colorido durante o jogo
	void show() const;               // mostra os atributos do tabuleiro (para debugging)
	
private:
	int numLines, numColumns;        
	vector<Ship> ships;              // vector com os navios que são colocados no tabuleiro
	vector<vector<int>> board;       // cada elemento indica o índice de um navio no vector "ships"; -1 representa o mar
};

#endif // BOARD_H