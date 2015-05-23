#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

using namespace std;

template<class T>
struct Position
{
	T lin, col;
};

struct Score
{
	string name;
	int points;
};

#endif // STRUCTS_H