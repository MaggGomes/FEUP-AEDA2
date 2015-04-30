#ifndef ship_h
#define ship_h

class Ship
{
public:
	Ship(char symbol, PositionChar position, char orientation, unsigned int size, unsigned int color);
	
	bool move(char direction, bool rotate, unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax); // move o navio
	bool moveRand(unsigned int lineMin, unsigned int columnMin, unsigned int lineMax, unsigned int columnMax); // move o navio aleatoriamente
	bool attack(size_t partNumber); //partNumber = {0,1,…, tamanho-1}
	bool isDestroyed() const; // verifica se o navio está destruído
	void show() const; // mostra os atributos do navio (para debugging)
private:
	char symbol; // 'P' = "porta-aviões"; 'F' = "fragata"; … 
	PositionInt position; // coordenadas do canto superior esquerdo do navio
	char orientation; // 'H' = horizontal; 'V' = vertical
	unsigned int size; // número de células ocupadas pelo navio
	unsigned int color; // código das cores
	string status; // status[i]: maiúscula = bom; lowercase = danificado
	// ex: "FFFF" significa que a "fragata" está intacta;
	// ex: "FFfF" significa que a 'partNumber' 2 was hit by a bomb
	};

#endif