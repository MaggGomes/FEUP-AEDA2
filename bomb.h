#ifndef BOMB_H
#define BOMB_H

#include "structs.h"

class Bomb
{
public:
	Bomb(PositionChar targetPosition); // Contrutor da classe Bomb
	PositionChar getTargetPosition() const; // Devolve valores das coordenadas do objeto da class Bomb
	void show() const; // Mostra os atributos da bomba (para debugging)

private:
	char targetLine, targetColumn;
};

#endif // BOMB_H