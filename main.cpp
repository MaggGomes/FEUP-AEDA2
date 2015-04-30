#include <iostream>
#include <vector>
#include <string>
#include "variables.h"
#include "functions.h"
#include "structs.h"
#include "bomb.h"

using namespace std;

int main()
{
	
	impressaoTitulo(); // imprime título do jogo

	cout << "Bem-vindo ao jogo Battleship!" << endl << endl;




	
	PositionChar navio;
	
	navio.col = 'a';
	navio.lin = 'b';

Bomb bomba(navio);


	cout << endl;
	
	
	bomba.show();

	return 0;
}
