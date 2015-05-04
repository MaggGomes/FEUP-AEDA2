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
	
	char symbol = 'F';
	PositionChar position;
	position.lin = 'A';
	position.col = 'a';
	char orientation = 'H';
	unsigned int size = 5;
	unsigned int color = 0;
		
	Bomb bomba(position);

	bomba.show();

	
	
	

	

	return 0;
}
