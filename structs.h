#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

using namespace std;

// Características navio
struct ValoresNavio{
	int quantidade; // quantidade de cada tipo de navios
	string nome_navio; // nome do navio
	int comprimento; // comprimento do navio
	char simbolo; // simbolo do navio
	string coordenadas; // letra maiuscula indica a linha, minuscula a coluna
	string cor; //cor do navio
	char coord_linha; // coordenada do tipo char superior esquerdo de colocacao do navio
	int coordenada_numlinha; // coordenada do tipo int da linha do canto superior esquerdo de colocacao do navio
	char coord_coluna; // coordenada do tipo char da coluna do canto superior esquerdo de colocacao do navio
	int coordenada_numcoluna; // coordenada do tipo int da coluna do canto superior esquerdo de colocacao do navio
	char orientacao; // 'H' ou 'h' para horizontal e 'V' ou 'v' para vertical
};

struct PositionChar
{
	char lin, col; // guarda posição em formato char; ranges: lin - ['A'..'Z']; col - ['a'..'z']
};

struct PositionInt
{
	unsigned int lin, col; // guarda a posição em formato de inteiro sem sinal
};

#endif // STRUCTS_H