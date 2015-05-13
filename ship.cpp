#include <iostream>
#include <cstddef>

#include "ship.h"
#include "functions.h"
#include "structs.h"

Ship::Ship(char symbol, PositionChar position, char orientation, unsigned int size, unsigned int color)
{
	string statustemp(size, symbol); // cria string com comprimento igual ao navio e formada pelo símbolo do mesmo

	this->symbol = symbol;
	this->position.lin = position.lin - 65; // converte de char maiúscula para int 
	this->position.col = position.col - 97; // converte de char minúscula para int
	this->orientation = orientation;
	this->size = size;
	this->color = color;
	status = statustemp; // atribui a informação da variável temporária statustemp à variável status da classe Ship
}

char Ship::getOrientation() const
{
	return orientation;
}

bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{
	bool moveShip = false; // booleano que a função devolve que indica se o navio se move ou não
		
	/* A função move verifica primeiro se é possível mover o navio uma casa numa direção aleatória.
	Se após esta alteração o navio permanecer totalmente dentro do tabuleiro a função move devolve true e altera pelo menos a posição inicial em uma casa.
	Por fim é testado se também se pode rodar o navio. Caso este permaneça ,na sua totalidade, dentro do tabuleiro depois de rodar, a sua orientação é alterada juntamente com a posição. */
	
	if (orientation == 'H') // alteração posição do navio
	{
		switch (direction)
		{
		case '0': // Não move
			break;
		case 'N': // Move para norte
			if (position.lin > lineMin)
			{
				position.lin = position.lin - 1;
				moveShip = true;
			}
			break;
		case 'S': // Move para sul
			if (position.lin < lineMax)
			{
				position.lin = position.lin + 1;
				moveShip = true;
			}
			break;
		case 'E': // Move para este
			if (position.col + size - 1 < columnMax)
			{
				position.col = position.col + 1;
				moveShip = true;
			}
			break;
		case 'W': // Move para oeste
			if (position.col > columnMin)
			{
				position.col = position.col - 1;
				moveShip = true;
			}
			break;
		}
	}

	else if (orientation == 'V')
	{
		switch (direction)
		{
		case '0': // Não move
			break;
		case 'N': // Move para norte
			if (position.lin > columnMin)
			{
				position.lin = position.lin - 1;
				moveShip = true;
			}
			break;
		case 'S': // Move para sul
			if (position.lin + size - 1 < columnMax)
			{
				position.lin = position.lin + 1;
				moveShip = true;
			}
			break;
		case 'E': // Move para este
			if (position.col < lineMax)
			{
				position.col = position.col + 1;
				moveShip = true;
			}
			break;
		case 'W': // Move para oeste
			if (position.col > lineMin)
			{
				position.col = position.col - 1;
				moveShip = true;
			}
			break;
		}
	}

	if (rotate) // Altera orientação do navio caso rotate seja true
	{
		if (orientation == 'H')
		{
			if (position.lin + (size - 1) < lineMax)
			{
				orientation = 'V';
				moveShip = true;
			}
		}

		else if (orientation == 'V')
		{
			if (position.col + (size - 1) < columnMax)
			{
				moveShip = true;
				orientation = 'H';
			}
		}
	}

	return moveShip;
}

bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{
	bool moveShip = false; // booleano que a função devolve que indica se o navio se move ou não

	/* A função move verifica primeiro se é possível mover o navio uma casa numa direção aleatória.
	Se após esta alteração o navio permanecer totalmente dentro do tabuleiro a função move devolve true e altera pelo menos a posição inicial em uma casa.
	Por fim é testado se também se pode rodar o navio. Caso este permaneça ,na sua totalidade, dentro do tabuleiro depois de rodar, a sua orientação é alterada juntamente com a posição. */

	if (orientation == 'H') // alteração posição do navio
	{
		switch (randomPosition())
		{
		case '0': // Não move
			break;
		case 'N': // Move para norte
			if (position.lin > lineMin)
			{
				position.lin = position.lin - 1;
				moveShip = true;
			}
			break;
		case 'S': // Move para sul
			if (position.lin < lineMax)
			{
				position.lin = position.lin + 1;
				moveShip = true;
			}
			break;
		case 'E': // Move para este
			if (position.col + size - 1 < columnMax)
			{
				position.col = position.col + 1;
				moveShip = true;
			}
			break;
		case 'W': // Move para oeste
			if (position.col > columnMin)
			{
				position.col = position.col - 1;
				moveShip = true;
			}
			break;
		}
	}

	else if (orientation == 'V')
	{
		switch (randomPosition())
		{
		case '0': // Não move
			break;
		case 'N': // Move para norte
			if (position.lin > columnMin)
			{
				position.lin = position.lin - 1;
				moveShip = true;
			}
			break;
		case 'S': // Move para sul
			if (position.lin + size - 1 < columnMax)
			{
				position.lin = position.lin + 1;
				moveShip = true;
			}
			break;
		case 'E': // Move para este
			if (position.col < lineMax)
			{
				position.col = position.col + 1;
				moveShip = true;
			}
			break;
		case 'W': // Move para oeste
			if (position.col > lineMin)
			{
				position.col = position.col - 1;
				moveShip = true;
			}
			break;
		}
	}

	if (rotation()) // Altera orientação do navio caso rotate seja true
	{
		if (orientation == 'H')
		{
			if (position.lin + (size - 1) < lineMax)
			{
				orientation = 'V';
				moveShip = true;
			}
		}

		else if (orientation == 'V')
		{
			if (position.col + (size - 1) < columnMax)
			{
				moveShip = true;
				orientation = 'H';
			}
		}
	}

	return moveShip;
}

bool Ship::attack(size_t partNumber)
{
	bool acertaship = false;

	if (partNumber < size) // Verifica se a célula do navio existe
	{
		status.at(partNumber) = tolower(symbol); // Converte de letra maiúscula para minúscula
		acertaship = true; // Caso atinja o navio, retorna true
	}

	return acertaship;
}

bool Ship::isDestroyed() const
{
	int numlowercase = 0; // Número de letras minúculas
	double halfship = status.length() / 2; // metade do comprimento do barco;

	bool destroyed = false;

	for (size_t i = 0; i < status.length(); i++) // Verifica o numero de letras minúsculas que existem na string status
		if (status.at(i) == tolower(symbol))
		{
		numlowercase++;
		}
	if (numlowercase >= halfship) // O navio é considerado destruído se pelo menos 50% das suas células foram atingidas por bombas
		destroyed = true;

	return destroyed;
}

PositionInt Ship::getPosition() const
{
	return position;
}

char Ship::getSymbol() const
{
	return symbol;
}


int Ship::getSize() const
{
	return size;
}

void Ship::show() const
{
	cout << "simbolo: " << symbol
		<< "\ncoordenada linha: " << position.lin
		<< "\ncoordenada coluna: " << position.col
		<< "\norientacao: " << orientation
		<< "\ntamanho do barco: " << size
		<< "\ncor: " << color
		<< "\nstatus do barco: " << status
		<< endl;
}