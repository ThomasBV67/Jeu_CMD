#include "Board.h"

Board::Board()
{
	for (int i = 0; i < X_SIZE; i++)
	{
		for (int j = 0; j < X_SIZE; j++)
		{
			board[i][j] = Entity();
		}
	}
}

Board::~Board()
{
}