#ifndef functions_h
#define funcions_h

#include "variables.h"

// Declara��o de fun��es

void clrscr(void); // limpa o ecr�
void gotoxy(int x, int y); // posiciona o cursor na coluna 'x', linha 'y'
void setcolor(unsigned int color, unsigned int background_color); // defini��o da cor do texto & background
void impressaoTitulo(); // t�tulo do jogo
unsigned int getlinha(char &linha, const vector < vector <char> > &coordenadas); // converte coordenada linha "char" em "unsigned int"
unsigned int getcoluna(char &coluna, const vector < vector <char> > &coordenadas); // converte coordenada coluna "char" em "unsigned int"
char getlowercase(char symbol, const vector < vector <char> > &coordenadas); // converte s�mbolo do navio de letra mai�scula pra lettra min�scula

#endif