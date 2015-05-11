#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>

#include "player.h"
#include "variables.h"

using namespace std;

// Declara��o de fun��es

void clrscr(void); // Limpa o ecr�
void gotoxy(int x, int y); // Posiciona o cursor na coluna 'x', linha 'y'
void setcolor(unsigned int color, unsigned int background_color); // Defini��o da cor do texto & background
void impressaoTitulo(); // T�tulo do jogo
char randomPosition(); // (0=�n�o se move�, 1=�N�, 2=�S�, 3=�E�, 4=�W�)
bool rotation(); // Roda o navio (true=roda,false=mant�m a orienta��o)



#endif // FUNCTIONS_H