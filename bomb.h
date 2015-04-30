#ifndef bomb_h
#define bomb_h

#include "structs.h"

class Bomb
{
public:
	Bomb();
	Bomb(PositionChar targetPosition);
	PositionChar getTargetPosition() const;
	void show() const; // mostra os atributos da bomba (para debugging)

private:
	char targetLine, targetColumn;
};

#endif