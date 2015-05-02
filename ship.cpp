#include <iostream>
#include "ship.h"
#include "functions.h"


// FALTA COMPLETAR

Ship::Ship(char symbol, PositionChar position, char orientation, unsigned int size, unsigned int color)
{
	this->symbol = symbol;
	this->position.lin = getlinha(position.lin, coordenadas);
	this->position.col = getcoluna(position.col, coordenadas);
	this->orientation = orientation;
	this->size = size;
	this->color = color;

	// string status

}

void Ship::show() const
{
	cout << "simbolo: " << symbol << "\ncoordenada linha: " << position.lin << "\ncoordenada coluna: " << position.col << "\norientacao: " << orientation << "\ntamanho do barco: " << size << "\ncor: " << color << "\nstatus do barco: " << status;
}

