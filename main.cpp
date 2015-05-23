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

vector<Score> atScore(Score &sc, vector<Score> &vcs)
{
	vector<Score> temp,temp2;
	int i = 0;

	while (sc.points > vcs.at(i).points)
	{
		i++;
	}
		
	for (size_t j = 0; j < i; j++)	
	{
		temp.push_back(vcs.at(j));
	}

	temp.push_back(sc);
		
	for (size_t h = 0; h < (vcs.size() - i); h++)	
	{
		temp.push_back(vcs.at(i + h));
	}


	return temp;
}

void createScoreDoc(vector<Score> &vcs)
{
	ofstream doc;
	remove("score.txt");
	doc.open("score.txt");
	
	for (size_t i = 0; i < 10; i++)
	{
		doc << vcs.at(i).name << " - " << vcs.at(i).points << endl;
	}

	doc.close();
}

vector<Score> readScore()
{
	string temp;
	Score temp1;
	vector<Score> vect;
	ifstream vec ("score.txt");

	for (size_t i = 0; i < 10; i++)
	{
		vec >> temp1.name;
		vec.ignore(100, '-');
		vec >> temp1.points;
		vec.ignore(100, '-');
		vect.push_back(temp1);
		vec.ignore(100, '\n');
	}

	return vect;
}

int main()
{

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

	/*
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
	*/
	
	clrscr();
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) << "<< CRIAR JOGADOR 1 >>" << endl << endl;
	setcolor(7, 0);
	Player playerone(getFilename(), getPlayername()); // Inicializa classe Player do jogador 1
	playerone.showBoard();
	cout << "Tabuleiro de " << playerone.getPlayerName() << endl;
	Sleep(5000);
	
	clrscr();
	impressaoTitulo();
	setcolor(11, 0);
	cout << setw(48) <<"<< CRIAR JOGADOR 2>>" << endl << endl;
	setcolor(7, 0);
	Player playertwo(getFilename(), getPlayername()); // Inicializa classe Player do jogador 2
	playertwo.showBoard();
	cout << "Tabuleiro de " << playertwo.getPlayerName() << endl;
	Sleep(5000);


	//while (!playerone.fleetDestroyed() || !playertwo.fleetDestroyed())
	//{
		inic1 = clock();
		playertwo.attackBoard(playertwo.getBomb());
		fim1 = clock();
		acum1 = (acum1 + (fim1 - inic1));
		inic2 = clock();
		playerone.attackBoard(playerone.getBomb());
		fim2 = clock();
		acum2 = (acum2 + (fim2 - inic2));
	//}

		iacum1 = acum1 / CLOCKS_PER_SEC;
		iacum2 = acum2 / CLOCKS_PER_SEC;

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

	Score x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;

	scores = atScore(p1sc, scores);
	scores = atScore(p2sc, scores);


	createScoreDoc(scores);

	return 0;
}