#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <time.h>

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
	while (true) // Permite repetir o jogo até o utilizador querer sair do mesmo
	{
		unsigned int r = 1; // Contador do numero de rondas ao longo do jogo
		clock_t inic1, fim1, inic2, fim2;
		clock_t acum1 = 0;
		clock_t acum2 = 0;
		double area1, area2;
		double	ocup1 = 0;
		double	ocup2 = 0;
		double iacum1 = 0;
		double iacum2 = 0;
		createMenu();
		Score p1sc, p2sc;
		vector < Score >  scores;

		scores = readScore();

		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(48) << "<< CRIAR JOGADOR 1 >>" << endl << endl;
		setcolor(7, 0);
		Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
		/*
		cout << endl;
		cout << ">> TABULEIRO DE " << playerone.getPlayerName() << ":" << endl;
		playerone.boardPreview();
		Sleep(5000);
		*/

		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(48) << "<< CRIAR JOGADOR 2>>" << endl << endl;
		setcolor(7, 0);
		Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 2
		
		/*
		cout << endl;
		cout << ">> TABULEIRO DE " << playertwo.getPlayerName() << ":" << endl;
		playertwo.boardPreview();
		Sleep(5000);
		*/

		while (!playerone.fleetDestroyed() || !playertwo.fleetDestroyed())
		{
			inic1 = clock();
			playertwo.attackBoard(playertwo.getBomb(r, playerone.getPlayerName()),r,playerone.getPlayerName());
			fim1 = clock();
			acum1 = (acum1 + (fim1 - inic1));

			if (playertwo.fleetDestroyed()) // Verifica se a frota do jogador 2 está destruída e consequentemente se o jogador 1 venceu
			{
				cout << ":: PARABENS! O jogador " << playerone.getPlayerName() << " venceu!" << endl;
				Sleep(2000);
				break;
			}

			inic2 = clock();
			playerone.attackBoard(playerone.getBomb(r, playertwo.getPlayerName()),r,playertwo.getPlayerName());
			r++;
			fim2 = clock();
			acum2 = (acum2 + (fim2 - inic2));

			if (playerone.fleetDestroyed()) // Verifica se a frota do jogador 1 está destruída e consequentemente se o jogador 2 venceu
			{
				cout << ":: PARABENS! O jogador " << playertwo.getPlayerName() << " venceu!" << endl;
				Sleep(2000);
				break;
			}
		}

		iacum1 = acum1 / CLOCKS_PER_SEC;
		iacum2 = acum2 / CLOCKS_PER_SEC;

		for (int y = 0; y < playertwo.getBoard().getShips().size(); y++)
		{
			ocup1 = ocup1 + playertwo.getBoard().getShips().at(y).getSize();
		}
		for (int z = 0; z < playerone.getBoard().getShips().size(); z++)
		{
			ocup2 = ocup2 + playertwo.getBoard().getShips().at(z).getSize();
		}

		area1 = playertwo.getBoard().getLines() * playertwo.getBoard().getColumns();
		area2 = playerone.getBoard().getLines() * playerone.getBoard().getColumns();

		p1sc.name = playerone.getPlayerName();
		p2sc.name = playertwo.getPlayerName();
		p1sc.points = iacum1 * (ocup1 / area1);
		p2sc.points = iacum2 * (ocup2 / area2);

		scores = atScore(p1sc, scores);
		scores = atScore(p2sc, scores);

		createScoreDoc(scores);
	}

	return 0;
}