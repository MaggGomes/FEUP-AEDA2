#include "bomb.h"


Bomb::Bomb(PositionChar targetPosition)
{
	
	
	int erro = rand() % 5; //se 0(acerta) 1(+1cima) 2(+1baixo) 3(+1direita) 4(+1esquerda)
	if (erro == 1)


}



PositionChar getTargetPosition();
{
	PositionChar temp; //struct que a funçao vai devolver 
	char x, y;         // var locais onde ficam as coordenadas pedidas

	cout << "Indique as coordenadas do alvo." << endl;
	cin >> x >> y;

	temp.lin = x;
	temp.col = y;

	return temp;
}



 