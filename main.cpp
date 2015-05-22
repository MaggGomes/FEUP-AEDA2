#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <Windows.h>

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
	createMenu();
	
	
	clrscr();
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) << "<< CRIAR JOGADOR 1 >>" << endl << endl;
	setcolor(7, 0);
	Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
	
	clrscr(); // Limpa ecrâ;
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) <<"<< CRIAR JOGADOR 2>>" << endl << endl;
	setcolor(7, 0);
	Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 2
	
	
	/*setcolor(11, 0);
	cout << setw(48) << "<< CRIAR JOGADOR 1 >>" << endl << endl;
	Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
	

	cout << endl;
	cout << endl;

	setcolor(11, 0);
	cout << setw(48) << "<< CRIAR JOGADOR 2>>" << endl << endl;
	Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 2
	*/
	
	while (!playerone.fleetDestroyed() || !playertwo.fleetDestroyed())
	{
		playertwo.attackBoard(playertwo.getBomb());
		playerone.attackBoard(playerone.getBomb());
	}

	if (playerone.fleetDestroyed())
	{
		cout << ":: PARABENS! O jogador " << playertwo.getPlayerName() << " venceu!" << endl;
		Sleep(2000);
	}


	else if (playertwo.fleetDestroyed())
	{
		cout << ":: PARABENS! O jogador " << playerone.getPlayerName() << " venceu!" << endl;
		Sleep(2000);
	}

	
	return 0;
}
