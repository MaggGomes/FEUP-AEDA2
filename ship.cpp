#include <iostream>
#include <cstddef>

#include "ship.h"
#include "functions.h"

// FALTA COMPLETAR

Ship::Ship(char symbol, PositionChar position, char orientation, unsigned int size, unsigned int color)
{
	string statustemp(size, symbol); // cria string com comprimento igual ao navio e formada pelo símbolo do mesmo

	this->symbol = symbol;
	this->position.lin = getLinha(position.lin, coordenadas);
	this->position.col = getColuna(position.col, coordenadas);
	this->orientation = orientation;
	this->size = size;
	this->color = color;
	status = statustemp;// statustemp; // atribui a informação da variável temporária statustemp à variável status da classe Ship
}


bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{

}

bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{

}

bool Ship::attack(size_t partNumber)
{

}


bool Ship::isDestroyed() const
{
	int numlowercase = 0; // número de letras minúculas
	float halfship = status.length() / 2; // metade do comprimento do barco;
	
	bool destroyed = false;

	for (size_t i = 0; i < status.length(); i++) // verifica o numero de letras minúsculas que existem na string status
		if (status.at(i) == getLowercase(symbol, coordenadas))
		{
		numlowercase++;
		}

	if (numlowercase >= halfship) // o navio é considerado destruído se pelo menos 50% das suas células foram atingidas por bombas
		destroyed = true;
	
	return destroyed;
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