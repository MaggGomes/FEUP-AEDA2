#include <iostream>
#include <vector>
#include <string>
#include <locale>

#include "variables.h"
#include "structs.h"
#include "functions.h"
#include "bomb.h"
#include "ship.h"
#include "board.h"
#include "player.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	impressaoTitulo(); // Imprime título do jogo


	cout << initiatePlayer();
	
	/*char symbol = 'F';
	PositionChar position;
	position.lin = 'A';
	position.col = 'a';
	char orientation = 'H';
	unsigned int size = 5;
	unsigned int color = 0;

	int dir = 'S';
		
	Bomb bomba(position);

	Ship navio(symbol, position, orientation, size, color);

	cout << endl;

	navio.moveRand(0, 0, 5, 5);

	navio.show();

	cout << endl;*/
	
	

	return 0;
}
