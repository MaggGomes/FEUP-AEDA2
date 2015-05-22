#include <iostream>
#include <cstdlib>

#include "bomb.h"
#include "board.h"
#include "functions.h"

Bomb::Bomb(Position<char> targetPosition) // Constrói objeto da classe Bomb; 
{
	// Guarda os valores das coordenadas da bomba
	targetLine = targetPosition.lin;
	targetColumn = targetPosition.col;
	
	/* Modifica coordenadas da bomba em caso de ela se "desviar" do alvo de modo aleatório;
	   A bomba poderá no final ficar com coordenadas fora dos limites do tabuleiro, pelo que poderá atirada para fora do tabuleiro */
	
	switch (randomPosition()) // Função randomPosition() altera coordenadas da bomba aleatoriamente
	{
	case '0': // Mantém coordenadas originais
		break;
	case 'N': // Norte
		targetLine = targetLine - 1;
		break;
	case 'S': // Sul
		targetLine = targetLine + 1;
		break;
	case 'E': // Este
		targetColumn = targetColumn + 1;
		break;
	case 'W': // Oeste
		targetColumn = targetColumn - 1;
		break;
	}
}

Position<char> Bomb::getTargetPosition() const
{
	Position<char> targetposition; // Struct que a funçao vai devolver 

	targetposition.lin = targetLine;
	targetposition.col = targetColumn;

	return targetposition;
}

void Bomb::show() const // Mostra valores das coordenadas para debugging
{
	cout << "Coordenada da linha: " << targetLine << endl << "Coordenada da coluna: " << targetColumn << endl << endl;
}