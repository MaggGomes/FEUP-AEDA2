#ifndef structs_h
#define structs_h

struct PositionChar
{
	char lin, col; // guarda posi��o em formato char; ranges: lin - ['A'..'Z']; col - ['a'..'z']
};

struct PositionInt
{
	unsigned int lin, col; // guarda a posi��o em formato de inteiro sem sinal
};

#endif