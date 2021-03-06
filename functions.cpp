#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstddef>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

#include "functions.h"
#include "variables.h"

using namespace std;

// Implementação das funções

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // Canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Preenchimento com espaços
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// Cursor no canto superior esquerdo
	SetConsoleCursorPosition(hCon, coordScreen);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void impressaoTitulo()
{
	setcolor(3, 0);

	string titulo = "###############################################################################\n##    ____       _______ _______ _      ______  _____ _    _ _____ _____     ##\n##   |  _ \\   /\\|__   __|__   __| |    |  ____|/ ____| |  | |_   _|  __ \\    ##\n##   | |_) | /  \\  | |     | |  | |    | |__  | (___ | |__| | | | | |__) |   ##\n##   |  _ < / /\\ \\ | |     | |  | |    |  __|  \\___ \\|  __  | | | |  ___/    ##\n##   | |_) / ____ \\| |     | |  | |____| |____ ____) | |  | |_| |_| |        ##\n##   |____/_/    \\_\\_|     |_|  |______|______|_____/|_|  |_|_____|_|        ##\n##                                                                           ##\n###############################################################################";

	cout << titulo << endl << endl << endl;

	setcolor(7, 0);
}

char randomPosition() // (0=“no move”, 1=‘N’, 2=‘S’, 3=’E’, 4=’W’)
{
	//srand(time(NULL));
	char changeposition = '0'; // Variável a devolver que indica se houve mudança de posição ou não e se sim em que sentido

	int move = rand() % 5; // Se 0 (não altera posição: '0') 1(+1: 'N') 2(+1: 'S') 3(+1: 'E') 4(+1: 'W')
	switch (move)
	{
	case 1:
		changeposition = 'N';
		break;
	case 2:
		changeposition = 'S';
		break;
	case 3:
		changeposition = 'E';
		break;
	case 4:
		changeposition = 'W';
		break;
	default: // Case '0'
		changeposition = '0';
		break;
	}

	return changeposition;
}

bool rotation() // Roda o navio (true=roda,false=mantém a orientação)
{
	bool rotate = true; // Variável a devolver que indica se a orientação será ou não alterada

	int change = rand() % 2; // Caso seja 0 o navio "roda", caso seja 1 o navio mantém a orientação
	switch (change)
	{
	case 0:
		rotate = true;
		break;
	case 1:
		rotate = false;
		break;
	}

	return rotate;
}

string getPlayername()
{
	string playerName;

	do
	{
		cout << ">> NICKNAME JOGADOR (entre 3 e 6 caracteres): ";
		getline(cin, playerName);

		if (cin.fail() || playerName.length() < 3 || playerName.length() > 6)
		{
			setcolor(4, 0);
			cout << ":: ERRO: Nickname invalido! Tente novamente." << endl << endl;
			setcolor(7, 0);
		}

		else
		{
			setcolor(2, 0);
			cout << ":: Nickname guardado com sucesso!" << endl << endl;
			setcolor(7, 0);
		}
	} while (cin.fail() || playerName.length() < 3 || playerName.length() > 6);

	return playerName;
}

string getFilename()
{
	string filename;
	ifstream readfile;

	do
	{
		cout << ">> NOME FICHEIRO CONFIGURACAO: ";
		getline(cin, filename);
		readfile.open(filename);

		if (!readfile.fail())
		{
			setcolor(2, 0);
			cout << ":: Ficheiro aberto com sucesso!" << endl << endl;
			setcolor(7, 0);
			Sleep(400);
		}
		else
		{
			setcolor(4, 0);
			cout << ":: ERRO: Ficheiro inexistente! Tente novamente." << endl << endl;
			setcolor(7, 0);
		}
	} while (readfile.fail());

	readfile.close();

	return filename;
}

void createMenu() // FALTA COMPLETAR
{
	string Menu[3] = { "<<    INICIAR JOGO   >>", "<<     TOP SCORES    >>", "<<    SAIR DO JOGO   >>" };
	bool validade = true;
	int pointer = 0;
	int temp;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<< MENU JOGO >>>>>>" << endl << endl;

		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{				
				cout << "                            ";
				setcolor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setcolor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setcolor(7, 0);

		while (validade)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				Beep(250, 160);
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				setcolor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					cin.ignore(5000, '\n');
					break;
				case 1:
				{
					clrscr();
					showScore();
					setcolor(3, 0);
					cout << endl << "PRESS DOWN ARROW KEY TO RETURN TO MENU";
					setcolor(7, 0);
				} break;
				case 2:
					exit(0);
				}	
			}
		}
	}
}

vector<Score> atScore(Score &sc, vector<Score> &vcs)
{
	vector<Score> temp, temp2;
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
	
	doc << " PLAYER - POINTS" << endl;

	for (size_t i = 0; i < 10; i++)
	{
		doc << setw(7) << vcs.at(i).name << " - " << vcs.at(i).points << endl;
	}

	doc.close();
}

vector<Score> readScore()
{
	string temp;
	Score temp1;
	vector<Score> vect;
	ifstream vec("score.txt");

	for (size_t i = 0; i < 10; i++)
	{
		vec >> temp1.name;
		vec.ignore(100, '-');
		vec >> temp1.points;
		vect.push_back(temp1);
		vec.ignore(100, '\n');
	}

	return vect;
}

void showScore()
{
	vector<Score> temp = readScore();

	setcolor(11, 0);
	cout << "<<<< PLAYER - POINTS >>>>" << endl;
	
	setcolor(3, 0);
	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(11) << temp.at(i).name << " - " << temp.at(i).points << endl;
	}
	setcolor(7, 0);
}


/*void print_boards(Player &one, Player &two)
{
	UM.showBoard();	
	DOIS.showBoard();
	UM.getBoard().show();
	DOIS.getBoard().show();
}*/