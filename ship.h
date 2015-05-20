#ifndef SHIP_H
#define SHIP_H

#include "structs.h"

class Ship
{
public:
	Ship(char symbol, Position<char> position, char orientation, unsigned int size, unsigned int color);
	char getOrientation() const; // Devolve valor da orientação do navio
	bool move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax); // Move o navio (para debugging)
	bool moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax); // Move o navio aleatoriamente
	bool attack(size_t partNumber); // partNumber = {0,1,…, tamanho-1}
	bool isDestroyed() const;       // Verifica se o navio está destruído
	Position<unsigned int> getPosition() const;   // Devolve tamanho do navio
	char getSymbol() const; // Devolve símbolo do navio
	unsigned int getSize() const; // Devolve tamanho do navio
	unsigned int getColor() const; // Devolve cor do navio
	void show() const;              // Mostra os atributos do navio (para debugging)

private:
	char symbol; // 'P' = "porta-aviões"; 'F' = "fragata"; … 
	Position<unsigned int> position; // Coordenadas do canto superior esquerdo do navio
	char orientation; // 'H' = horizontal; 'V' = vertical
	unsigned int size; // Número de células ocupadas pelo navio
	unsigned int color; // Código das cores
	string status; // status[i]: maiúscula = bom; lowercase = danificado
	// ex: "FFFF" significa que a "fragata" está intacta;
	// ex: "FFfF" significa que a 'partNumber' 2 foi atingida por uma bomba
	};

#endif // SHIP_H