#include <cstdlib>
#include <ctime>
#include "bomb.h"

// FALTA ACABAR DE FAZER ESTES CONSTRUTORES E NO FINAL TESTAR NO MAIN

Bomb::Bomb(PositionChar targetPosition)
{
	srand((unsigned int)time(NULL)); // permite gerar n�meros aleat�rios
	
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
	}



}



PositionChar getTargetPosition();
{
	PositionChar temp; // struct que a fun�ao vai devolver 
	char x, y;         // var locais onde ficam as coordenadas pedidas

	cout << "Indique as coordenadas do alvo." << endl;
	cin >> x >> y;

	temp.lin = x;
	temp.col = y;

	return temp;
}



 