#ifndef BOARD_H
#define BOARD_H

#include "Entity.h"

#define X_SIZE 11
#define Y_SIZE 11

class Board
{
public:
	Board();
	~Board();

	Entity* operator[](int);
	//void operator=(Entity*);
private:
	Entity** board;
};

#endif