#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

using namespace std;

struct PositionChar
{
	char lin, col; // Guarda posição em formato char; ranges: lin - ['A'..'Z']; col - ['a'..'z']
};

struct PositionInt
{
	unsigned int lin, col; // Guarda a posição em formato de inteiro sem sinal
};

#endif // STRUCTS_H