#include <iostream>
#include <vector>
#include <string>
#include "variables.h"
#include "functions.h"
#include "structs.h"
#include "bomb.h"
#include "ship.h"

using namespace std;

int main()
{
	impressaoTitulo(); // imprime título do jogo

	cout << "Bem-vindo ao jogo Battleship!" << endl << endl;

	char symbol = 'a';
	PositionChar position;
	position.lin = 'A';
	position.col = 'a';
	char orientation = 'H';
	unsigned int size = 5;
	unsigned int color = 0;
		

	Ship navio(symbol, position, orientation, size, color);
	navio.show();


	return 0;
}
