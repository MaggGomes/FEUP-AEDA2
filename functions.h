#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "variables.h"

// Declaração de funções

void clrscr(void); // limpa o ecrâ
void gotoxy(int x, int y); // posiciona o cursor na coluna 'x', linha 'y'
void setcolor(unsigned int color, unsigned int background_color); // definição da cor do texto & background
void impressaoTitulo(); // título do jogo
unsigned int getLinha(char &linha, const vector < vector <char> > &coordenadas); // converte coordenada linha "char" em "unsigned int"
unsigned int getColuna(char &coluna, const vector < vector <char> > &coordenadas); // converte coordenada coluna "char" em "unsigned int"
char randomPosition(); // (0=“no move”, 1=‘N’, 2=‘S’, 3=’E’, 4=’W’)
bool rotation(); // roda o navio (true=roda,false=mantém a orientação)


#endif // FUNCTIONS_H