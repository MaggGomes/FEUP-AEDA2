#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>

#include "player.h"
#include "variables.h"

using namespace std;

// Declaração de funções

void clrscr(void); // Limpa o ecrâ
void gotoxy(int x, int y); // Posiciona o cursor na coluna 'x', linha 'y'
void setcolor(unsigned int color, unsigned int background_color); // Definição da cor do texto & background
void impressaoTitulo(); // Título do jogo
char randomPosition(); // (0=“não se move”, 1=‘N’, 2=‘S’, 3=’E’, 4=’W’)
bool rotation(); // Roda o navio (true=roda,false=mantém a orientação)



#endif // FUNCTIONS_H