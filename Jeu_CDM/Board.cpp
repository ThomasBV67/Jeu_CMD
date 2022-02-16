#include "Board.h"

Board::Board()
{
	board = new Entity * [X_SIZE]();
	for (int i = 0; i < X_SIZE; i++)
	{
		board[i] = new Entity[Y_SIZE]();
	}
}

Board::~Board()
{
	for (int i = 0; i < X_SIZE; ++i) 
	{
		delete[] board[i];
	}
	delete[] board;
}

Entity* Board::operator[](int index)
{
	return board[index];
}

/*void Board::operator=(Entity* nEntity)
{
	
}*/