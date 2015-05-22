#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>

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
	startMenu(); // FALTA ACABAR
	
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) << "<< CRIAR JOGADOR 1 >>" << endl << endl;
	setcolor(7, 0);
	Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
	/*
	clrscr(); // Limpa ecrâ;
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) <<"<< CRIAR JOGADOR 2>>" << endl << endl;
	setcolor(7, 0);
	Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
	*/
	
	cout << playerone.getBoard(); // TESTE
	string abc;
	playerone.move();
	cin >> abc; // Teste
	cout << playerone.getBoard();
	cin >> abc;
	playerone.move();
	cin >> abc; // Teste
	cout << playerone.getBoard();
	cin >> abc;
	playerone.move(); // Teste
	cin >> abc;
	cout << playerone.getBoard();
	
	

	
	return 0;
}
