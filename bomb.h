#ifndef BOMB_H
#define BOMB_H

#include "structs.h"

class Bomb
{
public:
	Bomb(Position<char> targetPosition); // Contrutor da classe Bomb
	Position<char> getTargetPosition() const; // Devolve valores das coordenadas do objeto da class Bomb em letras
	void show() const; // Mostra os atributos da bomba (para debugging)

private:
	char targetLine, targetColumn;
};

#endif // BOMB_H