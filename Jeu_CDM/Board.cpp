#include "Board.h"

Board::Board()
{
	board = new Entity ** [X_SIZE]();
	for (int i = 0; i < X_SIZE; i++)
	{
		board[i] = new Entity*[Y_SIZE]();
		for (int j = 0; j < X_SIZE; j++)
		{
			board[i][j] = new Entity();
		}
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

void Board::printBoard()
{
	for (int i = Y_SIZE-1; i >= 0; i--)
	{
		for (int j = 0; j < X_SIZE; j++)
		{
			cout << board[j][i]->getType() << " ";
		}
		cout << endl;
	}
}

void Board::movePlayer(int direction)
{
	Entity* tempPlayer = board[playerXY.x][playerXY.y];

	switch (direction)
	{
	case UP:
		//delete[] board[playerXY.x][playerXY.y];
		board[playerXY.x][playerXY.y] = new Entity();

		if (playerXY.y < Y_SIZE - 1)
		{
			playerXY.y++;
		}
		board[playerXY.x][playerXY.y] = tempPlayer;
		break;

	case DOWN:
		//delete[] board[playerXY.x][playerXY.y];
		board[playerXY.x][playerXY.y] = new Entity();

		if (playerXY.y > 0)
		{
			playerXY.y--;
		}
		board[playerXY.x][playerXY.y] = tempPlayer;
		break;

	case RIGHT:
		//delete[] board[playerXY.x][playerXY.y];
		board[playerXY.x][playerXY.y] = new Entity();

		if (playerXY.x < X_SIZE - 1)
		{
			playerXY.x++;
		}
		board[playerXY.x][playerXY.y] = tempPlayer;
		break;

	case LEFT:
		//delete[] board[playerXY.x][playerXY.y];
		board[playerXY.x][playerXY.y] = new Entity();

		if (playerXY.x > 0)
		{
			playerXY.x--;
		}
		board[playerXY.x][playerXY.y] = tempPlayer;
		break;

	default:
		break;
	}
}

void Board::moveEnemies(int)
{

}

void Board::dropEnemiesOnce()
{

}

Entity* Board::getPlayerInfo()
{
	return board[playerXY.x][playerXY.y];
}

Entity** Board::operator[](int index)
{
	return board[index];
}
