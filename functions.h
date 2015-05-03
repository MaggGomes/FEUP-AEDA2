#ifndef functions_h
#define funcions_h

#include "variables.h"

// Declaração de funções

void clrscr(void); // limpa o ecrâ
void gotoxy(int x, int y); // posiciona o cursor na coluna 'x', linha 'y'
void setcolor(unsigned int color, unsigned int background_color); // definição da cor do texto & background
void impressaoTitulo(); // título do jogo
unsigned int getlinha(char &linha, const vector < vector <char> > &coordenadas); // converte coordenada linha "char" em "unsigned int"
unsigned int getcoluna(char &coluna, const vector < vector <char> > &coordenadas); // converte coordenada coluna "char" em "unsigned int"
char getlowercase(char symbol, const vector < vector <char> > &coordenadas); // converte símbolo do navio de letra maiúscula pra lettra minúscula

#endif