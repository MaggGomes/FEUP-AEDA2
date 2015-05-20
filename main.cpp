#include <iostream>
#include <vector>
#include <string>

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
	impressaoTitulo(); // Imprime título do jogo
	cout << "CRIAR JOGADOR 1" << endl << endl;
	Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1

	clrscr(); // Limpa ecrâ;
	impressaoTitulo();
	cout << "CRIAR JOGADOR 2" << endl << endl;
	Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1

	playerone.showBoard(); // TESTE

	

	/*char symbol = 'F';
	Position<char> position;
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
