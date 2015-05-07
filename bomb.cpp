#include <iostream>
#include <cstdlib>

#include "bomb.h"
#include "board.h"
#include "functions.h"

Bomb::Bomb(PositionChar targetPosition) // constr�i objeto da classe Bomb
{
	PositionInt positionint; // cria struct para armazenar as coordenadas da bomb em formato int
	positionint.lin = targetPosition.lin - 65; // converte de char mai�sculo para int
	positionint.col = targetPosition.col - 97; // converte de char min�sculo para int
	// numLines, numColumns
	// atribui valores das coordenadas da bomba
	targetLine = targetPosition.lin;
	targetColumn = targetPosition.col;

	switch (randomPosition()) // modifica coordenadas da bomba em caso de ela se "desviar" do alvo de modo aleat�rio
	{
	case '0': // mant�m coordenadas originais
		break;
	case 'N': // norte
		if (targetPosition.lin != 'A') // a bomba n�o pode ter coordenada de linha menor que 'A' para nao sair para fora do tabuleiro
			targetLine = targetPosition.lin - 1;
		break;
	case 'S': // sul
		if (targetLine != 'A')
			targetLine = targetPosition.lin + 1;
		break;
	case 'E': // este
		targetColumn = targetPosition.col + 1;
		break;
	case 'W': // oeste
		if (targetColumn != 'a') // a bomba n�o pode ter coordenada de coluna menor que 'a' para nao sair para fora do tabuleiro
			targetColumn = targetPosition.col - 1;
		break;
	}
}

PositionChar Bomb::getTargetPosition() const
{
	PositionChar temp; // struct que a fun�ao vai devolver 

	temp.lin = targetLine;
	temp.col = targetColumn;

	return temp;
}

void Bomb::show() const // mostra valores das coordenadas para debugging
{
	cout << "Coordenada da linha: " << targetLine << endl << "Coordenada da coluna: " << targetColumn << endl << endl;
}