#include <iostream>
#include <cstddef>

#include "ship.h"
#include "functions.h"

// FALTA COMPLETAR

Ship::Ship(char symbol, PositionChar position, char orientation, unsigned int size, unsigned int color)
{
	string statustemp(size, symbol); // cria string com comprimento igual ao navio e formada pelo s�mbolo do mesmo

	this->symbol = symbol;
	this->position.lin = getlinha(position.lin, coordenadas);
	this->position.col = getcoluna(position.col, coordenadas);
	this->orientation = orientation;
	this->size = size;
	this->color = color;
	status = "FFFfff";// statustemp; // atribui a informa��o da vari�vel tempor�ria statustemp � vari�vel status da classe Ship
}

/*
bool Ship::move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{

}

bool Ship::moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax)
{

}

bool Ship::attack(size_t partNumber)
{

}
*/

bool Ship::isDestroyed() const
{
	int numlowercase = 0; // n�mero de letras min�culas
	float halfship = status.length() / 2; // metade do comprimento do barco;
	
	bool destroyed = false;

	for (size_t i = 0; i < status.length(); i++) // verifica o numero de letras min�sculas que existem na string status
		if (status.at(i) == getlowercase(symbol, coordenadas))
		{
		numlowercase++;
		}

	if (numlowercase >= halfship) // o navio � considerado destru�do se pelo menos 50% das suas c�lulas foram atingidas por bombas
		destroyed = true;
	
	return destroyed;
}

void Ship::show() const
{
	cout << "simbolo: " << symbol << "\ncoordenada linha: " << position.lin << "\ncoordenada coluna: " << position.col << "\norientacao: " << orientation << "\ntamanho do barco: " << size << "\ncor: " << color << "\nstatus do barco: " << status << endl;
}

