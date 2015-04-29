#include "structs.h"

#ifndef bomb_h
#define bomb_h

// FALTA COMPLETAR

class Bomb
{
public:
	Bomb(PositionChar targetPosition);
	PositionChar getTargetPosition() const;
	
	void show() const; // mostra os atributos da bomba (para debugging)
private:
	char targetLine, targetColumn;
};

#endif