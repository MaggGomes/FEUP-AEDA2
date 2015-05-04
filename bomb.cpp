#include <iostream>
#include <cstdlib>

#include "bomb.h"
#include "functions.h"

Bomb::Bomb(PositionChar targetPosition) // constrói objeto da classe Bomb
{
	targetLine = targetPosition.lin;
	targetColumn = targetPosition.col;

	switch (RandomPosition())
	{
	case '0':
		break;
	case 'N':
		targetLine = targetPosition.lin + 1;
		break;
	case 'S':
		if (targetLine != 'A')
			targetLine = targetPosition.lin - 1;
		break;
	case 'E':
		targetColumn = targetPosition.col + 1;
		break;
	case 'W':
		if (targetColumn != 'a')
			targetColumn = targetPosition.col - 1;
		break;
	}
}

PositionChar Bomb::getTargetPosition() const
{
	PositionChar temp; // struct que a funçao vai devolver 

	temp.lin = targetLine;
	temp.col = targetColumn;

	return temp;
}

void Bomb::show() const // mostra valores das coordenadas para debugging
{
	cout << "Coordenada da linha: " << targetLine << endl << "Coordenada da coluna: " << targetColumn << endl << endl;
}
