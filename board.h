#ifndef board_h
#define board_h

#include <string>
#include <vector>
#include "ship.h"
#include "bomb.h"

using namespace std;

class Board
{
public:
	Board(const string &filename);   // carrega o tabuleiro do ficheiro 'filename'
	bool putShip(const Ship &s);     // adiciona um navio ao tabuleiro se poss�vel
	void moveShips();                // tenta mover aleatoriamente todos os navios da frota
	bool attack(const Bomb &b);
	void display() const;            // mostra o tabuleiro colorido durante o jogo
	void show() const;               // mostra os atributos do tabuleiro (para debugging)
	
private:
	int numLines, numColumns;        
	vector<Ship> ships;              // vector com os navios que s�o colocados no tabuleiro
	vector<vector<int>> board;       // each element indicates
	
	// -1 � usado para representar o mar
};

#endif