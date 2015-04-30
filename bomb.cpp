#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bomb.h"

Bomb::Bomb()
{
	
}

Bomb::Bomb(PositionChar targetPosition)
{
	/*srand((unsigned int)time(NULL)); // permite gerar números aleatórios
	
	int erro = rand() % 5; // se 0(acerta) 1(+1cima) 2(+1baixo) 3(+1direita) 4(+1esquerda)
	switch (erro)
	{
	case '1':
		targetPosition.col++;
		break;
	case '2':
		targetPosition.col--;
		break;
	case '3':
		targetPosition.lin++;
		break;
	case '4':
		targetPosition.lin--;
		break;
	case '0':
		break;
	}*/

	targetLine = targetPosition.lin;
	targetColumn = targetPosition.col;



}

PositionChar Bomb::getTargetPosition() const
{
	PositionChar temp; // struct que a funçao vai devolver 
	char x, y;         // var locais onde ficam as coordenadas pedidas

	cout << "Indique as coordenadas do alvo." << endl;
	cin >> x >> y;

	temp.lin = x;
	temp.col = y;

	

	return temp;
}

void Bomb::show() const
{
	cout << "Coordenada da linha: " << targetLine << endl << "Coordenada da coluna: " << targetColumn << endl << endl;
}
