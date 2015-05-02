#ifndef bomb_h
#define bomb_h

#include "structs.h"

class Bomb
{
public:
	Bomb(PositionChar targetPosition); // contrutor da classe Bomb
	PositionChar getTargetPosition() const; // devolve valores das coordenadas do objeto da class Bomb
	void show() const; // mostra os atributos da bomba (para debugging)

private:
	char targetLine, targetColumn;
};

#endif
