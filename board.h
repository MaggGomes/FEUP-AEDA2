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
	Board(const string &filename);   // Carrega o tabuleiro do ficheiro 'filename'
	int getLines() const; // Devolve número de linhas do tabuleiro
	int getColumns() const; // Devolve número de colunas do tabuleiro
	bool putShip(const Ship &s, vector<vector<int>> &b, const int &i); // Adiciona um navio ao tabuleiro se possível
	void setBoard(); // Coloca os navios inicialmente no tabuleiro após leitura do ficheiro de configuração
	void moveShips();                // Tenta mover aleatoriamente todos os navios da frota
	bool attack(const Bomb &b);
	bool getShipstatus();			 // Se devolver True, os navios já se encontram todos destruídos
	void display() const;            // Mostra o tabuleiro colorido durante o jogo
	void show() const;               // Mostra os atributos do tabuleiro (para debugging)
	friend ostream& operator<<(ostream& os, const Board& tab);
	
private:
	int numLines, numColumns;        // Número de linhas e colunas do tabuleiro
	vector<Ship> ships;              // Vector com os navios que são colocados no tabuleiro
	vector<vector<int>> board;       // Cada elemento indica o índice de um navio no vector "ships"; -1 representa o mar
};

#endif // BOARD_H