#ifndef player_h
#define player_h


class Player
{
public:
	Player(string playerName, string boardFilename);
	void showBoard() const; // mostra o tabuleiro do jogador
	Bomb getBomb() const; // pergunta pelas coordenadas da bomba e coloca bomba
	void attackBoard(const Bomb &b); // ""recebe" a bomba do adversário
	// atualiza o tabuleiro tabuleiro tendo em conta o dano da bomba e se o navio se move
	
private:
	string name; // nome do jogador
	Board board; // tabuleirodo jogador
};

#endif